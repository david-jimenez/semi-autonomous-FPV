#include <fstream>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <armadillo>
#include <ctime>
#include "kalman.h"

float a,b,m,l,r,Ixx,Iyy,Izz,T1,T2,T3,T4;

#define g 9.8
#define M_PI 3.14159265358979323846
#define TolZero 2.2204e-14
#define papapa 321

kalman::kalman(){


}

void kalman::setAMatrix(arma::mat *A){	
	
	A->at(6,3) = (cos(a)*sin(c) - cos(c)*sin(a)*sin(b))*((T1/m)+(T2/m)+(T3/m)+(T4/m));
	A->at(6,4) = (cos(a)*cos(b)*cos(c))*((T1/m)+(T2/m)+(T3/m)+(T4/m));
	A->at(6,5) = (cos(c)*sin(a)-cos(a)*sin(b)*sin(c))*((T1/m)+(T2/m)+(T3/m)+(T4/m));
    A->at(6,12) = (sin(a)*sin(c)+cos(a)*cos(c)*sin(b))/m;
    A->at(6,13) = A->at(6,12);
    A->at(6,14) = A->at(6,12);
    A->at(6,15) = A->at(6,12);
    A->at(7,3) = -(cos(a)*cos(c) + sin(a)*sin(b)*sin(c))*((T1/m)+(T2/m)+(T3/m)+(T4/m));
	A->at(7,4) = (cos(a)*cos(b)*sin(c))*((T1/m)+(T2/m)+(T3/m)+(T4/m));
	A->at(7,5) = (sin(a)*sin(c)+cos(a)*cos(c)*sin(b))*((T1/m)+(T2/m)+(T3/m)+(T4/m));
    A->at(7,12) = (cos(a)*sin(b)*sin(c)-cos(c)*sin(a))/m;
    A->at(7,13) = A->at(7,12);
    A->at(7,14) = A->at(7,12);
    A->at(7,15) = A->at(7,12);
    A->at(8,3) = (-sin(a)*cos(b)*(T1+T2+T3+T4))/m;
	A->at(8,4) = (-cos(a)*sin(b)*(T1+T2+T3+T4))/m;
    A->at(8,12) = (cos(a)*cos(b))/m;
    A->at(8,13) = A->at(8,12);
    A->at(8,14) = A->at(8,12);
    A->at(8,15) = A->at(8,12);	
}

void kalman::setMatrices(arma::mat *A,arma::mat *B,arma::mat *C){
    A->at(0,6) = 1;
    A->at(1,7) = 1;
    A->at(2,8) = 1;
    A->at(3,9) = 1;
    A->at(4,10) = 1;
    A->at(5,11) = 1;

    A->at(9,12) = lp/Ixx;
    A->at(9,13) = -lp/Ixx;
    A->at(9,14) = lp/Ixx;
    A->at(9,15) = -lp/Ixx;

    A->at(10,12) = -lr/Iyy;
    A->at(10,13) = -lr/Iyy;
    A->at(10,14) = lr/Iyy;
    A->at(10,15) = lr/Iyy;

    A->at(11,12) = (l/Ixx)*r;
    A->at(11,13) = (-l/Ixx)*r;
    A->at(11,14) = (-l/Ixx)*r;
    A->at(11,15) = (l/Ixx)*r;
	
	A->at(12,12) = 1;
	A->at(13,13) = 1;
	A->at(14,14) = 1;
	A->at(15,15) = 1;

    B->at(12,0) = 1.5;
    B->at(13,1) = 1.5;
    B->at(14,2) = 1.5;
    B->at(15,3) = 1.5;

	C->at(0,0) = 1;
	C->at(1,1) = 1;
	C->at(2,2) = 1;
	C->at(3,3) = 1;
	C->at(4,4) = 1;
	C->at(5,5) = 1;
	C->at(6,6) = 1;
	C->at(7,7) = 1;

}

void kalman::setLocalStateSpace(std::vector<double> *stateSpace, arma::mat *xc, std::vector<double> *combinedMotor){

	for(int i = 0;i < 12; i++){
		xc->at(i) = stateSpace->at(i);
	}
	for(int i = 12; i < 16; i++){
		xc->at(i) = combinedMotor->at(i-12);
	}

}

void kalman::updateStateSpace(std::vector<double> *stateSpace, arma::mat *xp, double elapsedTime){
	double temp, blargh;
	for(int i = 0;i < 2;i++){
		temp = stateSpace->at(i) + xp->at(i)*elapsedTime;
		stateSpace->at(i) = temp;
	}
}

void kalman::computePrediction(arma::mat *xp, arma::mat *xc, arma::mat *y,
                       arma::mat *A,  arma::mat *B, arma::mat *C,
                       arma::mat *P, arma::mat *p, arma::mat *K,
                       arma::mat *Q, arma::mat *R, arma::mat *eye,
					   arma::mat *u)
{
    using namespace arma;
	//xp for state prediction, xc for current state
	//A->print("A");
	//B->print("B");
	//std::cout << a << std::endl;
	//std::cout << b << std::endl;
	//std::cout << c << std::endl;
    *xp = *A * *xc + *B * *u;
	//xp->print("xp");
	//xc->print("xc");
    *p = *A * *P * (A->t()) + *Q;
    *K = *p * *C * (arma::pinv(*C * *p * (C->t())+*R));
	*y = *C * *xp;
	//*xp = *xp + *K * (*y - *C * *xc);	
	//C->print("C");
	//y->print("y");
	//K->print("K");
	//xp->print("xp"); 
	*P = (*eye - *K * *C) * *p;

}

void kalman::convertInput(arma::mat *u, std::vector<double> combinedMotor){
	
}

void kalman::run(std::vector<double> *stateSpace, std::vector<double> *combinedMotor, std::vector<float> *quadSpecs, std::vector<int> *aux)
{
	/*a = 0; // Roll
	b = 0; // Pitch
	c = 0;
	a = M_PI*a/180;
    b = M_PI*b/180;
	c = M_PI*c/180;
	T1 = 1.519;
    T2 = 1.519;
    T3 = 1.519;
    T4 = 1.519;*/    
	//m = 0.62;
    l = 0.15;
    r = 0.5;
    //Ixx = 3.02*pow(10,-3);
    //Iyy = 3.02*pow(10,-3);
    //Izz = 3.02*pow(10,-3);

	m = quadSpecs->at(0);
	lp = quadSpecs->at(1);
	lr = quadSpecs->at(2);
	Ixx = quadSpecs->at(3);
	Iyy = quadSpecs->at(4);
	Izz = quadSpecs->at(5);
    
    arma::mat A(16,16,arma::fill::zeros);
    arma::mat B(16,4,arma::fill::zeros);
    arma::mat C(16,16,arma::fill::eye);
    arma::mat xc(16,1,arma::fill::zeros);
    arma::mat xd(16,1,arma::fill::zeros);
    arma::mat xp(16,1,arma::fill::zeros);
	arma::mat u(4,1,arma::fill::zeros);
    arma::mat yt(16,2,arma::fill::zeros);
    arma::mat R(16,16,arma::fill::eye);
    arma::mat Q(16,16,arma::fill::eye);
    arma::mat P(16,16,arma::fill::eye);
    arma::mat p(16,16,arma::fill::eye);
    arma::mat eye(16,16,arma::fill::eye);
	arma::mat y;
    arma::mat K;
    arma::mat x;

	/*setLocalStateSpace(stateSpace,&xc);
	a = xc.at(4);
	b = xc.at(3);
	c = xc.at(5);
	T1 = xc.at(12);
	T2 = xc.at(13);
	T3 = xc.at(14);
	T4 = xc.at(15);
	setAMatrix(&A);*/

    setMatrices(&A,&B,&C);

	//xc.at(0) = 1;
	//xc.at(1) = 1;
	//xc.at(2) = 1;
	//xc.at(6) = 5;
	//xc.at(7) = 1;
	//xc.at(8) = 5;
	//xc.at(12) = T1;
	//xc.at(13) = T2;
	//xc.at(14) = T3;
	//xc.at(15) = T4;

	//u.at(0) = 1;
	//u.at(1) = 1;
	//u.at(2) = 1;
	//u.at(3) = 1;

	//xc.print("xc:");
	clock_t begin,end;
	double elapsed_secs;
	begin = clock();
	while(aux->at(2) > 1750){
		setLocalStateSpace(stateSpace,&xc,combinedMotor);
		a = xc.at(4);
		b = xc.at(3);
		c = xc.at(5);
		T1 = xc.at(12);
		T2 = xc.at(13);
		T3 = xc.at(14);
		T4 = xc.at(15);
		setAMatrix(&A);
		//a = -xc.at(1);`
    	computePrediction(&xp,&xc,&y,&A,&B,&C,&P,&p,&K,&Q,&R,&eye,&u);	
		end = clock();
		//xp.print("xp");
		elapsed_secs = double(end - begin)/CLOCKS_PER_SEC;
		begin = clock();
		//std::cout << elapsed_secs <<std::endl;
		//arma::mat temp;
		//temp = xp*elapsed_secs;
		//temp.print("temp");
		//xc += xp*elapsed_secs;
		updateStateSpace(stateSpace,&xp,elapsed_secs);
	}
	//xp.print("xp:");
	//xc.print("xc");
	/*c = M_PI/2;
	setAMatrix(&A);
	computePrediction(&xp,&xc,&y,&A,&B,&C,&P,&p,&K,&Q,&R,&eye,&u);
	xp.print("xp:");
	c = M_PI;
	setAMatrix(&A);
	computePrediction(&xp,&xc,&y,&A,&B,&C,&P,&p,&K,&Q,&R,&eye,&u);
	xp.print("xp:");
	c = 3*M_PI/2;
	setAMatrix(&A);
	computePrediction(&xp,&xc,&y,&A,&B,&C,&P,&p,&K,&Q,&R,&eye,&u);
	xp.print("xp:");*/

    /*A.print("A:");
    B.print("B:");
    C.print("C:");
    xc.print("xt:");
    xd.print("xd:");
    yt.print("yt:");*/

}
