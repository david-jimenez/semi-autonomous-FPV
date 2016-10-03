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

    if(a == 0){a += 0.0001;}
	if(b == 0){b += 0.0001;}
	if(c == 0){c += 0.0001;}
	if(a == M_PI/2){a += 0.0001;}
	if(b == M_PI/2){b += 0.0001;}
	if(c == M_PI/2){c += 0.0001;}
	if(a == M_PI){a += 0.0001;}
	if(b == M_PI){b += 0.0001;}
	if(c == M_PI){c += 0.0001;}
	if(a == 3*M_PI/2){a += 0.0001;}
	if(b == 3*M_PI/2){b += 0.0001;}
	if(c == 3*M_PI/2){c += 0.0001;}

    A->at(6,3) = sin(c)*cos(a)*((T1/m)+(T2/m)+(T3/m)+(T4/m));
	A->at(6,5) = cos(c)*sin(a)*((T1/m)+(T2/m)+(T3/m)+(T4/m));
    A->at(6,12) = (sin(a)*sin(c))/m;
    A->at(6,13) = (sin(a)*sin(c))/m;
    A->at(6,14) = (sin(a)*sin(c))/m;
    A->at(6,15) = (sin(a)*sin(c))/m;
    A->at(7,4) = cos(c)*cos(b)*((T1/m)+(T2/m)+(T3/m)+(T4/m));
	A->at(7,5) = -sin(c)*sin(b)*((T1/m)+(T2/m)+(T3/m)+(T4/m));
    A->at(7,12) = (cos(c)*sin(b))/m;
    A->at(7,13) = (cos(c)*sin(b))/m;
    A->at(7,14) = (cos(c)*sin(b))/m;
    A->at(7,15) = (cos(c)*sin(b))/m;
    A->at(8,3) = (-sin(a)*cos(b)*(T1+T2+T3+T4))/m;
	A->at(8,4) = (-cos(a)*sin(b)*(T1+T2+T3+T4))/m;
    A->at(8,12) = (cos(a)*cos(b))/m;
    A->at(8,13) = (cos(a)*cos(b))/m;
    A->at(8,14) = (cos(a)*cos(b))/m;
    A->at(8,15) = (cos(a)*cos(b))/m;

}

void kalman::setMatrices(arma::mat *A,arma::mat *B,arma::mat *C){
    A->at(0,6) = 1;
    A->at(1,7) = 1;
    A->at(2,8) = 1;
    A->at(3,9) = 1;
    A->at(4,10) = 1;
    A->at(5,11) = 1;
    /*A->at(6,3) = cos(a)*((T1/m)+(T2/m)+(T3/m)+(T4/m));
    A->at(6,12) = sin(a)/m;
    A->at(6,13) = sin(a)/m;
    A->at(6,14) = sin(a)/m;
    A->at(6,15) = sin(a)/m;
    A->at(7,4) = cos(b)*((T1/m)+(T2/m)+(T3/m)+(T4/m));
    A->at(7,12) = sin(b)/m;
    A->at(7,13) = sin(b)/m;
    A->at(7,14) = sin(b)/m;
    A->at(7,15) = sin(b)/m;
    A->at(8,3) = (-sin(a)*(T1+T2+T3+T4))/m;
    A->at(8,12) = cos(a)/m;
    A->at(8,13) = cos(a)/m;
    A->at(8,14) = cos(a)/m;
    A->at(8,15) = cos(a)/m;*/

    A->at(9,12) = l/Ixx;
    A->at(9,13) = l/Ixx;
    A->at(9,14) = -l/Ixx;
    A->at(9,15) = -l/Ixx;

    A->at(10,12) = l/Iyy;
    A->at(10,13) = -l/Iyy;
    A->at(10,14) = l/Iyy;
    A->at(10,15) = -l/Iyy;

    A->at(11,12) = (-l/Ixx)*r;
    A->at(11,13) = (l/Ixx)*r;
    A->at(11,14) = (l/Ixx)*r;
    A->at(11,15) = (-l/Ixx)*r;

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
	//xp->print("xp");
    *xp = *A * *xc + *B * *u;
	//xp->print("xp");
    *p = *A * *P * (A->t()) + *Q;
    *K = *p * *C * (arma::pinv(*C * *p * (C->t())+*R));
	*y = *C * *xc;
	*xp = *xp + *K * (*y - *C * *xc);	
	//C->print("C");
	//y->print("y");
	//K->print("K");
	//xp->print("xp"); 
	*P = (*eye - *K * *C) * *p;

}

void kalman::run(std::vector<double> *stateSpace)
{
	a = 30;
	b = 30;    
	a = M_PI*a/180;
    b = M_PI*b/180;
    m = 0.62;
    l = 0.15;
    r = 0.5;
    Ixx = 3.02*pow(10,-3);
    Iyy = 3.02*pow(10,-3);
    Izz = 3.02*pow(10,-3);
    T1 = 1.519;
    T2 = 1.519;
    T3 = 1.519;
    T4 = 1.519;
    arma::mat A(16,16,arma::fill::zeros);
    arma::mat B(16,4,arma::fill::zeros);
    arma::mat C(16,16,arma::fill::zeros);
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

    setMatrices(&A,&B,&C);
	setAMatrix(&A);
	xc.at(6) = 0;
	xc.at(7) = 0;
	xc.at(8) = 5;
	xc.at(12) = T1;
	xc.at(13) = T2;
	xc.at(14) = T3;
	xc.at(15) = T4;

	u.at(0) = 1;
	u.at(1) = 1;
	u.at(2) = 1;
	u.at(3) = 1;

	clock_t begin = clock();
    computePrediction(&xp,&xc,&y,&A,&B,&C,&P,&p,&K,&Q,&R,&eye,&u);	
	clock_t end = clock();
	double elapsed_secs = double(end - begin)/CLOCKS_PER_SEC;
	printf("%f",elapsed_secs);	

    /*A.print("A:");
    B.print("B:");
    C.print("C:");
    xc.print("xt:");
    xd.print("xd:");
    yt.print("yt:");*/

}
