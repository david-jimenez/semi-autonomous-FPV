#include <iostream>
#include <cstring>
#include <unistd.h>
#include <ctime>
#include "../include/PWM.h"
#include "../include/maestro.h"



PWM::PWM(){}

PWM::~PWM(){}


void PWM::run(){
	int pw = 1000;
	int s = 100;

	printf("speed: %d * 0.25us / 10ms\n", s);
 	printf("target: %d * 0.25us\n", pw);

  	Maestro maestro;
  	maestro.setSpeed(0, s);
  	maestro.setTarget(0, pw);

}
