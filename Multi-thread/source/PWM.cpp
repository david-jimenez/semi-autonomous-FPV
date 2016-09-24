#include <iostream>
#include <cstring>
#include <unistd.h>
#include <ctime>
#include "../include/PWM.h"
#include "../include/maestro.h"



PWM::PWM(){}

PWM::~PWM(){}


void PWM::run(std::vector<int> *motVals){
	int pw = 1000;
	int s = 100;
	Maestro maestro;
	maestro.setSpeed(0, s);
	maestro.setSpeed(1, s);
	maestro.setSpeed(2, s);
	maestro.setSpeed(3, s);
	std::vector<int> motorTarget(4);
	motorTarget.at(0) = motVals->at(0)*4;
	std::system("clear");
	while(1){
		motorTarget.at(0) = motVals->at(0) + 3000;
		motorTarget.at(1) = motVals->at(1) + 3000;
		motorTarget.at(2) = motVals->at(2) + 3000;
		motorTarget.at(3) = motVals->at(3) + 3000;
		printf("%d\n",motorTarget.at(0));
		printf("%d\n",motorTarget.at(1));
		printf("%d\n",motorTarget.at(2));
		printf("%d\n",motorTarget.at(3));
		maestro.setTarget(0, motorTarget.at(0));
		maestro.setTarget(1, motorTarget.at(1));
		maestro.setTarget(2, motorTarget.at(2));
		maestro.setTarget(3, motorTarget.at(3));		
		std::cout << "\033[1;1H";
	}

	printf("speed: %d * 0.25us / 10ms\n", s);
 	printf("target: %d * 0.25us\n", pw);


  	maestro.setSpeed(0, s);
  	maestro.setTarget(0, pw);

}
