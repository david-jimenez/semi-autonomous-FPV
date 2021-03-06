#include <fstream>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <armadillo>
#include <vector>
#include <ctime>

class kalman{
	public:
	kalman();
	void run(std::vector<double> *stateSpace, std::vector<double> *combinedMotor, std::vector<float> *quadSpecs, std::vector<int> *aux);
	void computePrediction(arma::mat *xp, arma::mat *xc, arma::mat *y,
                       arma::mat *A,  arma::mat *B, arma::mat *C,
                       arma::mat *P, arma::mat *p, arma::mat *K,
                       arma::mat *Q, arma::mat *R, arma::mat *eye,
					   arma::mat *u);
	void setAMatrix(arma::mat *A);
	void setMatrices(arma::mat *A,arma::mat *B,arma::mat *C);
	void setLocalStateSpace(std::vector<double> *stateSpace, arma::mat *xc, std::vector<double> *combinedMotor);
	void updateStateSpace(std::vector<double> *stateSpace, arma::mat *xp, double elapsedTime);
	void convertInput(arma::mat *u, std::vector<double> combinedMotor);
	float a,b,c,m,lp,lr,l,r,Ixx,Iyy,Izz,T1,T2,T3,T4;

};
