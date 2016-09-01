#pragma once
#include "mspdata.h"
#include <iosfwd>

class Serial;

class MSP
{
public:
    MSP(Serial& serial);
    template<class T>
    bool req();
    template<class T>
    bool recv(T& command);
    template<class T>
    bool send(const T& command);
    template<class T>
    bool ack();
private:
    bool send(uint8_t command, const unsigned char* data, unsigned char size);
    Serial& m_serial;
};
