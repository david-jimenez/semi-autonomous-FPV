#include "serial.h"

#include <stdio.h>      // standard input / output functions
#include <stdlib.h>
#include <string.h>     // string function definitions
#include <unistd.h>     // UNIX standard function definitions
#include <fcntl.h>      // File control definitions
#include <errno.h>      // Error number definitions
#include <termios.h>    // POSIX terminal control definitions

#include <iostream>

Serial::Serial(const char* device)
    : m_handle(open(device, O_RDWR | O_NOCTTY))
{
    if (m_handle < 0)
    {
        std::cerr << "Error " << errno << " from tcgetattr: " << strerror(errno) << std::endl;
        exit(1);
    }
    int m_handle = open(device, O_RDWR | O_NOCTTY);

    struct termios tty;
    memset (&tty, 0, sizeof tty);

    /* Error Handling */
    if (tcgetattr(m_handle, &tty) != 0) {
        std::cerr << "Error " << errno << " from tcgetattr: " << strerror(errno) << std::endl;
        exit(1);
    }

    /* Set Baud Rate */
    cfsetospeed(&tty, (speed_t)B115200);
    cfsetispeed(&tty, (speed_t)B115200);

    /* Setting other Port Stuff */
    tty.c_cflag     &=  ~PARENB;            // Make 8n1
    tty.c_cflag     &=  ~CSTOPB;
    tty.c_cflag     &=  ~CSIZE;
    tty.c_cflag     |=  CS8;

    tty.c_cflag     &=  ~CRTSCTS;           // no flow control
    tty.c_cc[VMIN]   =  1;                  // read doesn't block
    tty.c_cc[VTIME]  =  5;                  // 0.5 seconds read timeout
    tty.c_cflag     |=  CREAD | CLOCAL;     // turn on READ & ignore ctrl lines

    /* Make raw */
    cfmakeraw(&tty);

    /* Flush Port, then applies attributes */
    tcflush(m_handle, TCIFLUSH);
    if (tcsetattr(m_handle, TCSANOW, &tty) != 0)
    {
        std::cerr << "Error " << errno << " from tcsetattr" << std::endl;
        exit(1);
    }
}

unsigned char Serial::tx(const unsigned char* cmd, unsigned char size)
{
    unsigned char spot = 0;
    unsigned char n_written = 0;
    do
    {
        n_written = write(m_handle, &cmd[spot], size - spot);
        spot += n_written;
    } while (spot < size && n_written > 0);
    if (n_written == 0)
    {
        std::cerr << "Written 0 bytes, something is wrong" << std::endl;
        exit(1);
    }
    return spot;
}

unsigned char Serial::rx(unsigned char* buf, unsigned char size)
{
    unsigned char spot = 0;
    do
    {
        spot += read(m_handle, &buf[spot], size - spot);
    } while (spot < size);
    return spot;
}
