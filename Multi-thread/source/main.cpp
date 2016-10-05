#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <stdio.h>
#include <vector>
#include "../include/server.h"
#include "../include/multiwii.h"
#include "../include/PWM.h"
#include "../include/mavlink_control.h"
#include "../include/kalman.h"
#include "../include/lqr.h"

using namespace std;

#define NUM_THREADS 8

struct argumentPass{
	std::vector<int> motorValues = std::vector<int>(4);
	std::vector<int> aux = std::vector<int>(4);
	std::vector<float> attitude = std::vector<float>(3);
	std::vector<double> motorLqrAdd = std::vector<double>(4);
	std::vector<float> flowValues = std::vector<float>(4);
	std::vector<double> stateSpace = std::vector<double>(16);
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
	//multiwii Naze;
	//Naze.run(motorValues,attitude,aux);
}

void *mavlink_worker_thread(void *arg){
	printf("Started Mavlink thread\n");
	argumentPass *Vars = reinterpret_cast<argumentPass*>(arg);
	std::vector<float> *flowValues = &Vars->flowValues;
	std::vector<double> *stateSpace = &Vars->stateSpace;
	//mavlink_control mavlink;
	//mavlink.start(flowValues);
	//TODO: Remember that the flow sensor is backwards on the rig. This must be handled in code
}

void *PWM_worker_thread(void *arg){
	argumentPass *Vars = reinterpret_cast<argumentPass*>(arg);
	printf("Started PWM thread\n");
	std::vector<int> *motorValues = &Vars->motorValues;
	//PWM PWMController;
	//PWMController.run(motorValues);
}

void *control_worker_thread(void *arg){
	argumentPass *Vars = reinterpret_cast<argumentPass*>(arg);
	printf("Started Control thread\n");
	std::vector<double> *stateSpace = &Vars->stateSpace;
	std::vector<double> *motorLqrAdd = &Vars->motorLqrAdd;
	lqr LQR;
	//LQR.run(stateSpace,motorLqrAdd);
}

void *pathfind_worker_thread(void *arg){
	argumentPass *Vars = reinterpret_cast<argumentPass*>(arg);
	printf("Started Pathfind thread\n");
}

void *predict_worker_thread(void *arg){
	argumentPass *Vars = reinterpret_cast<argumentPass*>(arg);
	std::vector<double> *stateSpace = &Vars->stateSpace;
	printf("Started Predict thread\n");
	kalman KFilt;
	KFilt.run(stateSpace);
}

int main(){

	argumentPass threadVars;
	threadVars.aux.at(3) = 1500;

	pthread_t server_thread,multiwii_thread,mavlink_thread,PWM_thread,control_thread,pathfind_thread,predict_thread;
	int server_ret,multiwii_ret,mavlink_ret,PWM_ret,control_ret,pathfind_ret,predict_ret;

	printf("In main: creating thread\n");
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
	pathfind_ret = pthread_create(&pathfind_thread, NULL, &pathfind_worker_thread, &threadVars);
	if(pathfind_ret != 0){
		printf("Error: pthread_create() failed \n");
		exit(EXIT_FAILURE);
	}
	server_ret = pthread_create(&server_thread, NULL, &server_worker_thread, &threadVars);
	if(server_ret != 0){
		printf("Error: pthread_create() failed \n");
		exit(EXIT_FAILURE);
	}	
	multiwii_ret = pthread_create(&multiwii_thread, NULL, &multiwii_worker_thread, &threadVars);
	if(multiwii_ret != 0){
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
	int check = 1000;
	while(check < 1750){
		//std::cout << flowVals.at(2) << std::endl;	
		//std::cout << threadVars.motorValues.at(0) << std::endl;
		//std::cout << threadVars.attitude.at(0) << std::endl;
		//std::cout << threadVars.attitude.at(1) << std::endl;
		//std::cout << threadVars.attitude.at(2) << std::endl;
		//std::cout << threadVars.aux.at(2) << std::endl;
		//check = threadVars.aux.at(2);
		//std::system("clear");
		//std::cout << "\033[1;1H";
		
	}
	pthread_exit(NULL);
}
