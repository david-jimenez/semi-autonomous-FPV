#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <stdio.h>
#include <vector>
#include <fstream>
#include "../include/server.h"
#include "../include/multiwii.h"
#include "../include/PWM.h"
#include "../include/mavlink_control.h"
#include "../include/kalman.h"
#include "../include/lqr.h"
#include <ctime>

using namespace std;

#define NUM_THREADS 8

struct argumentPass{
	std::vector<int> motorValues = std::vector<int>(4);
	std::vector<double> combinedMotor = std::vector<double>(4);
	std::vector<int> aux = std::vector<int>(5);
	std::vector<float> attitude = std::vector<float>(3);
	std::vector<double> motorLqrAdd = std::vector<double>(4);
	std::vector<float> flowValues = std::vector<float>(5);
	std::vector<double> stateSpace = std::vector<double>(16);
	std::vector<float> quadSpecs = std::vector<float>(6);
	std::vector<int> motorTarget = std::vector<int>(4);
	std::vector<pthread_mutex_t> stateMutex = std::vector<pthread_mutex_t>(16);
};

void *server_worker_thread(void *arg){
	//printf("Started Server thread\n");
	//server testServer;
	//testServer.run(6013);
	//pthread_exit(NULL);

}

void *multiwii_worker_thread(void *arg){
	printf("Started Multiwii thread\n");
	argumentPass *Vars = reinterpret_cast<argumentPass*>(arg);
	std::vector<int> *motorValues = &Vars->motorValues;
	std::vector<float> *attitude = &Vars->attitude;
	std::vector<int> *aux = &Vars->aux;
	std::vector<double> *stateSpace = &Vars->stateSpace;
	std::vector<pthread_mutex_t> *stateMutex = &Vars->stateMutex;
	multiwii Naze;
	Naze.run(motorValues,attitude,aux,stateSpace);
}

void *mavlink_worker_thread(void *arg){
	printf("Started Mavlink thread\n");
	argumentPass *Vars = reinterpret_cast<argumentPass*>(arg);
	std::vector<float> *flowValues = &Vars->flowValues;
	std::vector<double> *stateSpace = &Vars->stateSpace;
	std::vector<int> *aux = &Vars->aux;
	std::vector<pthread_mutex_t> *stateMutex = &Vars->stateMutex;
	mavlink_control mavlink;
	mavlink.start(flowValues,stateSpace,aux);
	//TODO: Remember that the flow sensor is backwards on the rig. This must be handled in code
}

void *PWM_worker_thread(void *arg){
	argumentPass *Vars = reinterpret_cast<argumentPass*>(arg);
	printf("Started PWM thread\n");
	std::vector<int> *motorValues = &Vars->motorValues;
	std::vector<double> *combinedMotor = &Vars->combinedMotor;
	std::vector<double> *motorLqrAdd = &Vars->motorLqrAdd;
	std::vector<int> *aux = &Vars->aux;
	std::vector<int> *motorTarget = &Vars->motorTarget;
	PWM PWMController;
	PWMController.run(motorValues, motorLqrAdd, combinedMotor,aux,motorTarget);
}

void *control_worker_thread(void *arg){
	argumentPass *Vars = reinterpret_cast<argumentPass*>(arg);
	printf("Started Control thread\n");
	std::vector<double> *stateSpace = &Vars->stateSpace;
	std::vector<double> *motorLqrAdd = &Vars->motorLqrAdd;
	std::vector<double> *combinedMotor = &Vars->combinedMotor;
	std::vector<float> *quadSpecs = &Vars->quadSpecs;
	std::vector<int> *aux = &Vars->aux;
	lqr LQR;
	LQR.run(stateSpace,motorLqrAdd, combinedMotor,quadSpecs,aux);
}

void *pathfind_worker_thread(void *arg){
	argumentPass *Vars = reinterpret_cast<argumentPass*>(arg);
	std::vector<int> *aux = &Vars->aux;
	printf("Started Pathfind thread\n");
}

void *predict_worker_thread(void *arg){
	argumentPass *Vars = reinterpret_cast<argumentPass*>(arg);
	std::vector<double> *stateSpace = &Vars->stateSpace;
	std::vector<double> *combinedMotor = &Vars->combinedMotor;
	std::vector<float> *quadSpecs = &Vars->quadSpecs;
	std::vector<int> *aux = &Vars->aux;
	printf("Started Predict thread\n");
	kalman KFilt;
	KFilt.run(stateSpace, combinedMotor, quadSpecs,aux);
}

int main(){

//-------------------------------------------------------------------------------
	argumentPass threadVars;
	threadVars.aux.at(4) = 1500;
	for(int i = 0;i < 16; i++){	
		threadVars.stateSpace.at(i) = 0;
	}
	threadVars.quadSpecs.at(0) = 0.691; //Weight in kg
	threadVars.quadSpecs.at(1) = 0.097;//Distance, centre to pitch motor
	threadVars.quadSpecs.at(2) = 0.076;//Distance, centre to roll motor
	threadVars.quadSpecs.at(3) = 3.413727*pow(10,-3);//Ixx
	threadVars.quadSpecs.at(4) = 3.284027*pow(10,-3);//Iyy
	threadVars.quadSpecs.at(5) = 4.047568*pow(10,-3);//Izz

//-------------------------------------------------------------------------------

	pthread_t server_thread,multiwii_thread,mavlink_thread,PWM_thread,control_thread,pathfind_thread,predict_thread;
	int server_ret,multiwii_ret,mavlink_ret,PWM_ret,control_ret,pathfind_ret,predict_ret;

	threadVars.aux.at(2) = 1000;

	printf("In main: creating thread\n");
	multiwii_ret = pthread_create(&multiwii_thread, NULL, &multiwii_worker_thread, &threadVars);
	if(multiwii_ret != 0){
		printf("Error: pthread_create() failed \n");
		exit(EXIT_FAILURE);
	}
	//threadVars.aux.at(2) = 2000;
	std::cout << CLOCKS_PER_SEC << std::endl;
	while(threadVars.aux.at(2) < 1750){
		//std::cout << threadVars.aux.at(2) << std::endl;
	}
	control_ret = pthread_create(&control_thread, NULL, &control_worker_thread, &threadVars);
	if(control_ret != 0){
		printf("Error: pthread_create() failed \n");
		exit(EXIT_FAILURE);
	}
	predict_ret = pthread_create(&predict_thread, NULL, &predict_worker_thread, &threadVars);
	if(control_ret != 0){
		printf("Error: pthread_create() failed \n");
		exit(EXIT_FAILURE);
	}
	server_ret = pthread_create(&server_thread, NULL, &server_worker_thread, &threadVars);
	if(server_ret != 0){
		printf("Error: pthread_create() failed \n");
		exit(EXIT_FAILURE);
	}
	pathfind_ret = pthread_create(&pathfind_thread, NULL, &pathfind_worker_thread, &threadVars);
	if(pathfind_ret != 0){
		printf("Error: pthread_create() failed \n");
		exit(EXIT_FAILURE);
	}	
	mavlink_ret = pthread_create(&mavlink_thread, NULL, &mavlink_worker_thread, &threadVars);
	if(mavlink_ret != 0){
		printf("Error: pthread_create() failed \n");
		exit(EXIT_FAILURE);
	}
	PWM_ret = pthread_create(&PWM_thread, NULL, &PWM_worker_thread, &threadVars);
	if(PWM_ret != 0){
		printf("Error: pthread_create() failed \n");
		exit(EXIT_FAILURE);
	}

//-------------------------------------------------------------------------------
	int check = 1000;
	double thrustTemp;
	//threadVars.aux.at(2) = 1900;
	clock_t time;
	int clockInc = 0;
	ofstream myFile;
	myFile.open ("Results/results.csv");
	myFile << "Time,x,y,z,pitch,roll,yaw,xd,yd,zd,pitchd,rolld,yawd,T1,T2,T3,T4,";
	myFile << "mVals1,mVals2,mVals3,mVals4,mTarg1,mTarg2,mTarg3,mTarg4,";
	myFile << "mTargDiv1,mTargDiv2,mTargDiv3,mTargDiv4,\n";
	while(threadVars.aux.at(2) > 1750){
	//while(threadVars.aux.at(2) > 1400){
	//threadVars.aux.at(2) = 1500;
		if(clockInc == 10){myFile << clock() << ",";}
		for(int i = 0;i < 12;i++){
			//std::cout << threadVars.stateSpace.at(i) << std::endl;
			if(clockInc == 10){myFile << threadVars.stateSpace.at(i) << ",";}
		}
		for(int i = 12;i < 16;i++){
			thrustTemp = threadVars.stateSpace.at(i) + threadVars.motorLqrAdd.at(i-12);
			if(clockInc == 10){myFile << thrustTemp << ",";}
			//std::cout << thrustTemp  << std::endl;
		}
		//for(int i = 0;i < 4;i++){
			//std::cout << threadVars.motorValues.at(i) << "      ";
			//std::cout << threadVars.motorTarget.at(i) << "      ";
			//std::cout << (threadVars.motorTarget.at(i)/4) - 1000 << std::endl;
			//if(clockInc == 10){myFile << threadVars.motorValues.at(i) << ",";}
			//if(clockInc == 10){myFile << threadVars.motorValues.at(i) << ",";}
		//}
		for(int i = 0;i < 4;i++){
			//std::cout << threadVars.motorValues.at(i) << "      ";
			//std::cout << threadVars.motorTarget.at(i) << "      ";
			//std::cout << (threadVars.motorTarget.at(i)/4) - 1000 << std::endl;
			if(clockInc == 10){myFile << threadVars.motorTarget.at(i) << ",";}
		}
		for(int i = 0;i < 4;i++){
			//std::cout << threadVars.motorValues.at(i) << "      ";
			//std::cout << threadVars.motorTarget.at(i) << "      ";
			//std::cout << (threadVars.motorTarget.at(i)/4) - 1000 << std::endl;
			//if(clockInc == 10){myFile << (threadVars.motorTarget.at(i)/4) - 1000 << ",";}
			if(clockInc == 10){myFile << threadVars.motorLqrAdd.at(i) << ",";}
		}
		if(clockInc == 10){myFile << "\n"; clockInc = 0;}
		clockInc++;
		//std::system("clear");
		//std::cout << "\033[1;1H";
		//threadVars.aux.at(2) = 2000;
		
	}
	myFile.close();
	pthread_join(predict_thread, NULL);
	std::cout << "Predict Thread Closed" << std::endl;
	pthread_join(control_thread, NULL);
	std::cout << "Control Thread Closed" << std::endl;
	pthread_join(PWM_thread, NULL);
	std::cout << "PWM Thread Closed" << std::endl;
	pthread_join(mavlink_thread, NULL);
	std::cout << "mavlink Thread Closed" << std::endl;
	threadVars.aux.at(4) = 1000;
	pthread_join(multiwii_thread, NULL);
	std::cout << "multiwii Thread Closed" << std::endl;
	pthread_join(pathfind_thread, NULL);
	std::cout << "Pathfind Thread Closed" << std::endl;
	pthread_join(server_thread, NULL);
	std::cout << "Server Thread Closed" << std::endl;
	


}
