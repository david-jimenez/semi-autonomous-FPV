#include <iostream>
#include <cstring>
#include <unistd.h>
#include <ctime>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

#include "../include/serial.h"
#include "../include/msp.h"
#include "../include/mspdata.h"
#include "../include/multiwii.h"

multiwii::multiwii(){}

template<class T>
bool multiwii::get(MSP& msp, T& t)
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
void multiwii::out(MSP& msp, std::ostream& o)
{
    T t;
    if (get(msp, t))
    {
        o << t;
    }
}

void multiwii::rcTest(MSP& msp)
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

void multiwii::accCalTest(MSP& msp)
{
    AccCalibration cal;
    msp.send(cal);
    msp.ack<AccCalibration>();
    sleep(3);
}


void multiwii::run(std::vector<int> *motVals)
{
    Serial s("/dev/ttyUSB0");
	//std::system("clear");
    MSP msp(s);
	std::stringstream motorOut;
	std::string motorString;
	char * token;
	int i = 0;
	std::vector<std::string> tempMotor(8);
	while(1){
		//out<Attitude>(msp, std::cout);
		//out<Altitude>(msp, std::cout);
		out<Motor>(msp, motorOut);
		motorString = motorOut.str();
		i = 0;
		while(i < 8 && getline(motorOut,tempMotor.at(i))){
			i++;
		}
		//for(int j = 0;j < 4; j++){
		//	std::cout << tempMotor.at(j) << std::endl;
		//}
		std::string tempString;
		std::vector<std::string> tokens;
		std::string item;
		for(int j = 0;j < 4;j++){
			tempString = tempMotor.at(j);
			std::stringstream ss(tempString);
			while(getline(ss,item,':')){
				tokens.push_back(item);
			}							
		}
		std::vector<int> motorVals(4);
		for(int k = 0;k < 4;k++){
			motorVals.at(k) = stoi(tokens.at(2*k + 1));
			motVals->at(k) = motorVals.at(k);
			//printf("%d\n",motorVals.at(k));
		}
		//std::cout << "\033[1;1H";
		//std::cout << tokens.at(1) << std::endl;
		//std::cout << tokens.at(3) << std::endl;
		//std::cout << tokens.at(5) << std::endl;
		//std::cout << tokens.at(7) << std::endl;
		//std::cout << motorString;
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
