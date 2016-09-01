#include <iostream>
#include <cstring>
#include <unistd.h>
#include <ctime>

#include "serial.h"
#include "msp.h"
#include "mspdata.h"

template<class T>
bool get(MSP& msp, T& t)
{
    // std::cerr << "Requesting: " << static_cast<int>(T::type) << std::endl;
    if(!msp.req<T>())
    {
        std::cerr << "Failed requesting" << std::endl;
        return false;
    }
    // std::cerr << "Receiving: " << static_cast<int>(T::type) << std::endl;
    if (!msp.recv(t))
    {
        std::cerr << "Failed receiving" << std::endl;
        return false;
    }
    return true;
}

template<class T>
void out(MSP& msp, std::ostream& o)
{
    T t;
    if (get(msp, t))
    {
        o << t;
    }
}

void rcTest(MSP& msp)
{
    SetRawRC set_rc;
    memset(&set_rc, 0, sizeof(set_rc));
    set_rc.rcData[6] = 1000;
    std::cout << msp.send(set_rc) << std::endl;
    const clock_t sent = clock();
    RC rc;
    memset(&rc, 0, sizeof(rc));
    do
    {
        get<RC>(msp, rc);
    } while (rc.rcData[6] != 1000);
    const clock_t set = clock();
    do
    {
        get<RC>(msp, rc);
    } while (rc.rcData[6] == 1000);
    const clock_t reset = clock();
    std::cout << "Lag: " << set - sent << ", reset: " << reset - set << std::endl;
}

void accCalTest(MSP& msp)
{
    AccCalibration cal;
    msp.send(cal);
    msp.ack<AccCalibration>();
    sleep(3);
}


int main()
{
    Serial s("/dev/ttyUSB0");
    MSP msp(s);
	while(1){
		out<Attitude>(msp, std::cout);
		out<Altitude>(msp, std::cout);
	}
	/*
    out<Ident>(msp, std::cout);
    //accCalTest(msp);
    out<Status>(msp, std::cout);
    out<RawIMU>(msp, std::cout);
    out<Servo>(msp, std::cout);
    out<Motor>(msp, std::cout);
    out<RC>(msp, std::cout);
    //rcTest(msp);
    out<Attitude>(msp, std::cout);
    out<Altitude>(msp, std::cout);
	*/
}
