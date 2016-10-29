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

#define M_PI 3.14159265358979323846

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


void multiwii::run(std::vector<int> *motVals, std::vector<float> *attitude, std::vector<int> *aux,std::vector<double> *stateSpace)
{
    Serial s("/dev/ttyUSB0");
	//std::cout << "asd1" << std::endl;
	//std::system("clear");
    MSP msp(s);
	//std::cout << "asd2" << std::endl;
	std::stringstream motorOut, attOut, auxOut, gyroOut;
	std::string motorString, attString, auxString, gyroString;
	std::vector<int> motorVals(4);
	std::vector<float> att(3);
	std::vector<int> auxVec(4);
	std::vector<float> gyroValues(3);
	char * token;
	int i = 0;
	std::vector<std::string> tempMotor(8);
	std::vector<std::string> tempAtt(6);
	std::vector<std::string> tempAux(16);
	std::vector<std::string> tempGyro(6);
	float trust = 1;
	float gyroTrust = 1;
	while(aux->at(4) > 1400){
		out<Motor>(msp, motorOut);
		//out<Motor>(msp,std::cout);
		motorString = motorOut.str();
		i = 0;
		//std::cout << "asd" << std::endl;
		while(i < 8 && getline(motorOut,tempMotor.at(i))){
			i++;
		}
		std::string tempString;
		std::vector<std::string> tokens;
		std::string item;
		//std::cout << "asd2" << std::endl;
		for(int j = 0;j < 4;j++){
			tempString = tempMotor.at(j);
			std::stringstream ss(tempString);
			while(getline(ss,item,':')){
				tokens.push_back(item);
			}							
		}
		//std::cout << "asd3" << std::endl;
		for(int k = 0;k < 4;k++){
			motorVals.at(k) = stoi(tokens.at(2*k + 1));
			motVals->at(k) = motorVals.at(k);
		}
/* -----------------------------------------------------------*/
		out<Attitude>(msp, attOut);
		attString = attOut.str();
		i = 0;
		//std::cout << "asd4" << std::endl;
		while(i < 3 && getline(attOut, tempAtt.at(i))){
			i++;
		}
		tempString.clear();
		tokens.clear();
		item.clear();
		//std::cout << "asd5" << std::endl;
		for(int j = 0;j < 3;j++){
			tempString = tempAtt.at(j);
			std::stringstream ss(tempString);
			while(getline(ss,item,':')){
				tokens.push_back(item);
			}
		}
		//std::cout << "asd6" << std::endl;
		for(int k = 0;k < 3;k++){
			att.at(k) = (float) stod(tokens.at(2*k + 1));
		}
		attitude->at(0) = att.at(0)/10;
		attitude->at(1) = att.at(1)/10;
		attitude->at(2) = att.at(2);
		stateSpace->at(3) = trust*attitude->at(1) + (1-trust)*stateSpace->at(3);
		stateSpace->at(4) = trust*attitude->at(0) + (1-trust)*stateSpace->at(4);
		stateSpace->at(5) = trust*attitude->at(2) + (1-trust)*stateSpace->at(5);
//---------------------------------------------------------------//
		out<RC>(msp, auxOut);
		//out<RC>(msp, std::cout);
		//std::cout << "hello" << std::endl;
		auxString = auxOut.str();
		i = 0;
		//std::cout << "asd" << std::endl;
		while(i < 8 && getline(auxOut, tempAux.at(i))){
			i++;
		}
		//std::cout << "blah" << std::endl;
		tempString.clear();
		tokens.clear();
		item.clear();
		for(int j = 0; j < 16; j++){
			tempString = tempAux.at(j);
			std::stringstream ss(tempString);
			while(getline(ss,item,':')){
				tokens.push_back(item);
			}
		}
		//std::cout << tokens.at(2*2 + 9);
		for(int k = 0; k < 4; k++){
			auxVec.at(k) = stoi(tokens.at(2*k + 9));
			aux->at(k) = auxVec.at(k);
		}
		//std::cout << auxVec.at(1) << std::endl;
//-------------------------------------------------------------------//
		out<RawIMU>(msp, gyroOut);
		gyroString = gyroOut.str();
		i = 0;
		while(i < 3 && getline(gyroOut, tempGyro.at(i))){
			i++;
		}
		tempString.clear();
		tokens.clear();
		for(int j = 0; j < 6; j++){
			tempString = tempGyro.at(j);
			std::stringstream ss(tempString);
			while(getline(ss,item,':')){
				tokens.push_back(item);
			}
		}
		std::stringstream sd(tokens.at(3));
		tokens.clear();
		while(getline(sd,item,',')){
			tokens.push_back(item);
		}
		for(int k = 0; k < 3; k++){
			gyroValues.at(k) = (float) stod(tokens.at(k));
			gyroValues.at(k) = gyroValues.at(k)/4.096;
			stateSpace->at(k + 9) = (gyroValues.at(k)*M_PI)/180;
			//std::cout << gyroValues.at(k) << " ";
		}
		// Roll = 0, pitch = 1, yaw = 2
		//std::cout << std::endl;
	}
	//out<RC>(msp, std::cout);
	//out<Attitude>(msp, std::cout);
	//out<Altitude>(msp, std::cout);
    /*out<Ident>(msp, std::cout);
    //accCalTest(msp);
    out<Status>(msp, std::cout);
    out<RawIMU>(msp, std::cout);
    out<Servo>(msp, std::cout);
    out<Motor>(msp, std::cout);

    //rcTest(msp);
    out<Attitude>(msp, std::cout);
    out<Altitude>(msp, std::cout);
	*/
}
