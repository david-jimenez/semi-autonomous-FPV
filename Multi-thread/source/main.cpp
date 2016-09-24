#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <stdio.h>
#include <vector>
#include "../include/server.h"
#include "../include/multiwii.h"
#include "../include/PWM.h"

using namespace std;

#define NUM_THREADS 8

void *server_worker_thread(void *arg){
	/*server testServer;
	testServer.run(6013);
	pthread_exit(NULL);
	*/
	printf("Started Server thread\n");
}

void *multiwii_worker_thread(void *arg){
	printf("Started Multiwii thread\n");
	vector<int> *motVals = reinterpret_cast<vector<int>*>(arg);
	std::cout << "size: " << motVals->size() << std::endl;
	//printf("%d\n",motVals->at(0));
	//printf("%d\n",motVals->at(1));
	//printf("%d\n",motVals->at(2));
	//printf("%d\n",motVals->at(3));
	multiwii Naze;
	Naze.run(motVals);
}

void *mavlink_worker_thread(void *arg){
	printf("Started Mavlink thread\n");
	//TODO: Remember that the flow sensor is backwards on the rig. This must be handled in code
}

void *PWM_worker_thread(void *arg){
	std::vector<int>* motVals = static_cast<std::vector<int>*>(arg);
	//std::cout << motVals->at(0) << std::endl;	
	//std::cout << motVals->at(1) << std::endl;
	//std::cout << motVals->at(2) << std::endl;
	//std::cout << motVals->at(3) << std::endl;
	printf("Started PWM thread\n");
	//std::system("clear");
	/*while(1){
		for(int i = 0; i < 4; i++){
			std::cout << motVals->at(0) << std::endl;
			std::cout << motVals->at(1) << std::endl;
			std::cout << motVals->at(2) << std::endl;
			std::cout << motVals->at(3) << std::endl;
			std::cout << "\033[1;1H";
		}
	}*/
	PWM PWMController;
	PWMController.run(motVals);
}

void *control_worker_thread(void *arg){
	printf("Started Control thread\n");
}

void *pathfind_worker_thread(void *arg){
	printf("Started Pathfind thread\n");
}

int main(){
	
	std::vector<int> motorValues(4);
	motorValues.at(0) = 5;
	motorValues.at(1) = 6;
	motorValues.at(2) = 8;
	motorValues.at(3) = 9;
	
	pthread_t server_thread,multiwii_thread,mavlink_thread,PWM_thread,control_thread,pathfind_thread;
	int server_ret,multiwii_ret,mavlink_ret,PWM_ret,control_ret,pathfind_ret;

	printf("In main: creating thread\n");
	server_ret = pthread_create(&server_thread, NULL, &server_worker_thread, NULL);
	if(server_ret != 0){
		printf("Error: pthread_create() failed \n");
		exit(EXIT_FAILURE);
	}	
	multiwii_ret = pthread_create(&multiwii_thread, NULL, &multiwii_worker_thread, &motorValues);
	if(multiwii_ret != 0){
		printf("Error: pthread_create() failed \n");
		exit(EXIT_FAILURE);
	}
	mavlink_ret = pthread_create(&mavlink_thread, NULL, &mavlink_worker_thread, NULL);
	if(mavlink_ret != 0){
		printf("Error: pthread_create() failed \n");
		exit(EXIT_FAILURE);
	}
	PWM_ret = pthread_create(&PWM_thread, NULL, &PWM_worker_thread, &motorValues);
	if(PWM_ret != 0){
		printf("Error: pthread_create() failed \n");
		exit(EXIT_FAILURE);
	}
	control_ret = pthread_create(&control_thread, NULL, &control_worker_thread, NULL);
	if(control_ret != 0){
		printf("Error: pthread_create() failed \n");
		exit(EXIT_FAILURE);
	}
	pathfind_ret = pthread_create(&pathfind_thread, NULL, &pathfind_worker_thread, NULL);
	if(pathfind_ret != 0){
		printf("Error: pthread_create() failed \n");
		exit(EXIT_FAILURE);
	}
	while(1){}
	pthread_exit(NULL);
}
