#include <iostream>
#include <cstring>
#include <unistd.h>
#include <ctime>
#include "../include/PWM.h"
#include "../include/maestro.h"

#define InputToThrust 0.0063
#define ThrustToInput 158.73

PWM::PWM(){}

PWM::~PWM(){}

bool PWM::combineValues(std::vector<int> *motVals, std::vector<double> *motorLqrAdd, std::vector<double> *tempMotorHold,std::vector<int> *motorTarget){

	//y = 0.0063x - Motor input to Newton Thrust 4S
	//x = 158.73y - Newton Thrust to Motor Input 4S
	//y = 0.0049x - 3S
	//x  = 204.0816 - 3S
	float NazeToThrust,Combine,CombineToPWM;
	bool retVal = false;
	for(int i = 0; i < 4; i ++){
		NazeToThrust = (motVals->at(i) - 1000)*0.0049;
		Combine = NazeToThrust + motorLqrAdd->at(i);
		CombineToPWM = Combine*204.0816;
		//std::cout << CombineToPWM << std::endl;
		if(0 < CombineToPWM && CombineToPWM < 4000){
			//std::cout << CombineToPWM << std::endl;
			motorTarget->at(i) = 4000 + CombineToPWM*4;
			tempMotorHold->at(i) = Combine;
		}
		else{
			retVal = true;
			motorTarget->at(i) = 4000 + (motVals->at(i)-1000)*4;
			tempMotorHold->at(i) = NazeToThrust;
		}
		if(i == 3){
			//std::system("clear");
			//std::cout << "\033[1;1H";
		}
	}
	return retVal;
}

void PWM::run(std::vector<int> *motVals, std::vector<double> *motorLqrAdd, std::vector<double> *combinedMotor, std::vector<int> *aux,std::vector<int> *motorRet){
	//int pw = 1000;
	int s = 100;
	Maestro maestro;
	maestro.setSpeed(0, s);
	maestro.setSpeed(1, s);
	maestro.setSpeed(2, s);
	maestro.setSpeed(3, s);
	maestro.setTarget(0, 4000);
	maestro.setTarget(1, 4000);
	maestro.setTarget(2, 4000);
	maestro.setTarget(3, 4000);
	maestro.setTarget(0, 0);
	maestro.setTarget(1, 0);
	maestro.setTarget(2, 0);
	maestro.setTarget(3, 0);
	maestro.setTarget(0, 4000);
	maestro.setTarget(1, 4000);
	maestro.setTarget(2, 4000);
	maestro.setTarget(3, 4000);
	std::vector<int> motorTarget(4);
	std::vector<double> tempMotorHold(4);
	motorTarget.at(0) = motVals->at(0)*4;
	bool retVal = false;
	//std::system("clear");
	while(aux->at(2) > 1750){
		retVal = combineValues(motVals,motorLqrAdd,&tempMotorHold,&motorTarget);
		retVal = true;
		if(retVal == true){
			motorTarget.at(0) = 4000 + (motVals->at(0)-1000)*4;
			motorTarget.at(1) = 4000 + (motVals->at(1)-1000)*4;
			motorTarget.at(2) = 4000 + (motVals->at(2)-1000)*4;
			motorTarget.at(3) = 4000 + (motVals->at(3)-1000)*4;
			combinedMotor->at(0) = (motVals->at(0) - 1000)*0.0049;
			combinedMotor->at(0) = (motVals->at(0) - 1000)*0.0049;
			combinedMotor->at(0) = (motVals->at(0) - 1000)*0.0049;
			combinedMotor->at(0) = (motVals->at(0) - 1000)*0.0049;
		}
		maestro.setTarget(0, motorTarget.at(0));
		maestro.setTarget(1, motorTarget.at(1));
		maestro.setTarget(2, motorTarget.at(2));
		maestro.setTarget(3, motorTarget.at(3));
		for(int i = 0; i < 4;i++){
			//std::cout << tempMotorHold.at(i) << std::endl;
			//std::cout << motorTarget.at(i) << std::endl;
			combinedMotor->at(i) = tempMotorHold.at(i);
			motorRet->at(i) = motorTarget.at(i);
		}
		//std::system("clear");				
		//std::cout << "\033[1;1H";
	}
	maestro.setTarget(0, 4000);
	maestro.setTarget(1, 4000);
	maestro.setTarget(2, 4000);
	maestro.setTarget(3, 4000);
	//printf("speed: %d * 0.25us / 10ms\n", s);
 	//printf("target: %d * 0.25us\n", pw);


  	//maestro.setSpeed(0, s);
  	//maestro.setTarget(0, pw);

}
