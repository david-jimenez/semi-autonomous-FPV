#include "../include/msp.h"
#include "../include/serial.h"
#include <algorithm>
#include <iostream>

MSP::MSP(Serial& serial) : m_serial(serial)
{
}

bool MSP::send(uint8_t command, const unsigned char* data, unsigned char size)
{
    constexpr unsigned char Size = 3;
    constexpr unsigned char Preamble[] = {'$', 'M', '<'};
    const unsigned char crc = std::accumulate(data, data + size, command ^ size, [](unsigned char a, unsigned char b) { return a ^ b; });
    bool result = m_serial.tx(Preamble, Size) == Size
        && m_serial.tx(&size, 1) == 1
        && m_serial.tx(&command, 1) == 1
        && (size == 0 || m_serial.tx(data, size) == size)
        && m_serial.tx(&crc, 1) == 1;
    return result;
}

template<class T>
bool MSP::req()
{
    return send(T::type, 0, 0);
}

template<class T>
bool MSP::recv(T& command)
{
    unsigned char n = 0;
    unsigned char buf[6];
    do
    {
        n += m_serial.rx(buf, 5 - n);
    } while (n < 5);

    if (buf[0] != '$' || buf[1] != 'M' || buf[2] != '>')
    {
        std::cerr << "Received wrong signature: " << std::string(buf, buf + 2) << std::endl;
        return false;
    }
    // std::cerr << "Receiving command " << static_cast<int>(buf[4]) << ", size: " << static_cast<int>(buf[3]) << std::endl;
    if (buf[3] != sizeof(T))
    {
        std::cerr << "Received incorrect size" << std::endl;
        return false;
    }
    unsigned char s = 0;
    unsigned char* cmd = reinterpret_cast<unsigned char*>(&command);
    do
    {
        s += m_serial.rx(cmd + s, sizeof(T) - s);
    } while (s < sizeof(T));

    do
    {
        n = m_serial.rx(&buf[5], 1);
    } while (n != 1);

    const unsigned char crc = std::accumulate(cmd, cmd + sizeof(T), buf[3] ^ buf[4], [](unsigned char a, unsigned char b) { return a ^ b; });
    return crc == buf[5];
}

template<class T>
bool MSP::send(const T& command)
{
    return send(T::type, reinterpret_cast<const uint8_t*>(&command), sizeof(T));
}

template<class T>
bool MSP::ack()
{
    unsigned char n = 0;
    unsigned char buf[6];
    do
    {
        n += m_serial.rx(buf, 6 - n);
    } while (n < 6);

    if (buf[0] != '$' || buf[1] != 'M' || buf[2] != '>')
    {
        std::cerr << "Received wrong signature: " << std::string(buf, buf + 2) << std::endl;
        return false;
    }
    // std::cerr << "Receiving command " << static_cast<int>(buf[4]) << " ack, size: " << static_cast<int>(buf[3]) << std::endl;
    if (buf[3] != 0)
    {
        std::cerr << "Received incorrect size" << std::endl;
        return false;
    }

    return (buf[3] ^ buf[4]) == buf[5];
}

template bool MSP::req<Ident>();
template bool MSP::req<Status>();
template bool MSP::req<RawIMU>();
template bool MSP::req<Servo>();
template bool MSP::req<Motor>();
template bool MSP::req<RC>();
template bool MSP::req<Attitude>();
template bool MSP::req<Altitude>();

template bool MSP::recv(Ident&);
template bool MSP::recv(Status&);
template bool MSP::recv(RawIMU&);
template bool MSP::recv(Servo&);
template bool MSP::recv(Motor&);
template bool MSP::recv(RC&);
template bool MSP::recv(Attitude&);
template bool MSP::recv(Altitude&);

template bool MSP::send(const SetRawRC&);

template bool MSP::send(const AccCalibration&);
template bool MSP::ack<AccCalibration>();
