#ifndef __SERIAL__
#define __SERIAL__
#pragma once

class Serial
{
public:
    Serial(const char* device);
    unsigned char tx(const unsigned char* cmd, unsigned char size);
    unsigned char rx(unsigned char* buf, unsigned char size);
    int handle() const { return m_handle; }
private:
    int m_handle;
};

#endif
