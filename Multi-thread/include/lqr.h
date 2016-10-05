#include <fstream>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <armadillo>
#include <ctime>
#include <Python.h>

class lqr{
	public:
	lqr();
	void run(std::vector<double> *stateSpace, std::vector<double> *motorLqrAdd, std::vector<int> *combinedMotor);
	void computeControl(arma::mat *xp, arma::mat *xc, arma::mat *y,
                       arma::mat *A,  arma::mat *B, arma::mat *C,
                       arma::mat *P, arma::mat *p, arma::mat *K,
                       arma::mat *Q, arma::mat *R, arma::mat *eye,
					   arma::mat *u);
	void setAMatrix(arma::mat *A);
	void setLocalStateSpace(std::vector<double> *stateSpace);
	void setMatrices(arma::mat *A,arma::mat *B,arma::mat *C);
	void convertInput(arma::mat *u, std::vector<int> combinedMotor);
	float a,b,c,m,l,r,Ixx,Iyy,Izz,T1,T2,T3,T4;

};
