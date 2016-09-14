#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include "../include/server.h"
#include "../include/multiwii.h"

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
	multiwii Naze;
	Naze.run();
}

void *mavlink_worker_thread(void *arg){
	printf("Started Mavlink thread\n");
}

void *PWM_worker_thread(void *arg){
	printf("Started PWM thread\n");
}

void *control_worker_thread(void *arg){
	printf("Started Control thread\n");
}

void *pathfind_worker_thread(void *arg){
	printf("Started Pathfind thread\n");
}

int main(){
	
	pthread_t server_thread,multiwii_thread,mavlink_thread,PWM_thread,control_thread,pathfind_thread;
	int server_ret,multiwii_ret,mavlink_ret,PWM_ret,control_ret,pathfind_ret;

	printf("In main: creating thread\n");
	server_ret = pthread_create(&server_thread, NULL, &server_worker_thread, NULL);
	if(server_ret != 0){
		printf("Error: pthread_create() failed \n");
		exit(EXIT_FAILURE);
	}	
	multiwii_ret = pthread_create(&multiwii_thread, NULL, &multiwii_worker_thread, NULL);
	if(multiwii_ret != 0){
		printf("Error: pthread_create() failed \n");
		exit(EXIT_FAILURE);
	}
	mavlink_ret = pthread_create(&mavlink_thread, NULL, &mavlink_worker_thread, NULL);
	if(mavlink_ret != 0){
		printf("Error: pthread_create() failed \n");
		exit(EXIT_FAILURE);
	}
	PWM_ret = pthread_create(&PWM_thread, NULL, &PWM_worker_thread, NULL);
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
	pthread_exit(NULL);
}
