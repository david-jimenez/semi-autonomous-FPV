#include <fstream>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <armadillo>
#include <ctime>
//#include <Python.h>
//#include <numpy/arrayobject.h>
//#include <boost/python.hpp>
#include "lqr.h"

#define g 9.8
#define M_PI 3.14159265358979323846
#define TolZero 2.2204e-14

lqr::lqr(){}

void lqr::setAMatrix(arma::mat *A){

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

    /*A->at(6,3) = (-cos(a)*cos(b)*cos(c))*((T1/m)+(T2/m)+(T3/m)+(T4/m));
	A->at(6,4) = (cos(b)*sin(c)+cos(c)*sin(a)*sin(b))*((T1/m)+(T2/m)+(T3/m)+(T4/m));
	A->at(6,5) = (sin(b)*cos(c)+cos(b)*sin(a)*sin(c))*((T1/m)+(T2/m)+(T3/m)+(T4/m));
    A->at(6,12) = (sin(b)*sin(c)-cos(b)*cos(c)*sin(a))/m;
    A->at(6,13) = A->at(6,12);
    A->at(6,14) = A->at(6,12);
    A->at(6,15) = A->at(6,12);
    A->at(7,3) = (-cos(a)*cos(b)*sin(c))*((T1/m)+(T2/m)+(T3/m)+(T4/m));
	A->at(7,4) = -(cos(b)*cos(c)-sin(a)*sin(b)*sin(c))*((T1/m)+(T2/m)+(T3/m)+(T4/m));
	A->at(7,5) = (sin(b)*sin(c)-cos(b)*cos(c)*sin(a))*((T1/m)+(T2/m)+(T3/m)+(T4/m));
    A->at(7,12) = -(cos(c)*sin(b)-cos(b)*sin(a)*sin(c))/m;
    A->at(7,13) = A->at(7,12);
    A->at(7,14) = A->at(7,12);
    A->at(7,15) = A->at(7,12);
    A->at(8,3) = (-sin(a)*sin(b)*(T1+T2+T3+T4))/m;
	A->at(8,4) = (cos(a)*cos(b)*(T1+T2+T3+T4))/m;
    A->at(8,12) = (cos(a)*sin(b))/m;
    A->at(8,13) = A->at(8,12);
    A->at(8,14) = A->at(8,12);
    A->at(8,15) = A->at(8,12);*/

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

void lqr::setLocalStateSpace(std::vector<double> *stateSpace){

	a = stateSpace->at(4);
	b = stateSpace->at(5);
	c = stateSpace->at(6);
	T1 = stateSpace->at(12);
	T2 = stateSpace->at(13);
	T3 = stateSpace->at(14);
	T4 = stateSpace->at(15);

}

void lqr::setMatrices(arma::mat *A,arma::mat *B,arma::mat *C){
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
    A->at(9,13) = -l/Ixx;
    A->at(9,14) = l/Ixx;
    A->at(9,15) = -l/Ixx;

    A->at(10,12) = -l/Iyy;
    A->at(10,13) = -l/Iyy;
    A->at(10,14) = l/Iyy;
    A->at(10,15) = l/Iyy;

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


void lqr::computeControl(arma::mat *xp, arma::mat *xc, arma::mat *y,
                       arma::mat *A,  arma::mat *B, arma::mat *C,
                       arma::mat *P, arma::mat *p, arma::mat *K,
                       arma::mat *Q, arma::mat *R, arma::mat *eye,
					   arma::mat *u){
	
	
	A->save("CSV/A.csv", arma::csv_ascii);
	B->save("CSV/B.csv", arma::csv_ascii);
	Q->save("CSV/Q.csv", arma::csv_ascii);
	R->save("CSV/R.csv", arma::csv_ascii);
	
	//clock_t begin = clock();
	PyRun_SimpleString("pythLqr.LQR()");
	//double elapsed_secs = double(clock() - begin)/CLOCKS_PER_SEC;
	//std::cout << elapsed_secs << std::endl;
	//P->load("P.csv", arma::csv_ascii);
	//*K = R->i() * B->t() * *P;
	//Change to retrieving X, offload more computation to armadillo
	K->load("CSV/K.csv", arma::csv_ascii);
	//K->print("K:");
	
}

void lqr::run(std::vector<double> *stateSpace, std::vector<double> *motorLqrAdd)
{

	a = 1;
	b = 90; 
	c = 0;   
	a = M_PI*a/180;
    b = M_PI*b/180;
    m = 0.62;
    l = 0.15;
    r = 0.5;
    Ixx = 3.02*pow(10,-3);
    Iyy = 3.02*pow(10,-3);
    Izz = 3.02*pow(10,-3);
    T1 = 1.5;
    T2 = 1.5;
    T3 = 1.5;
    T4 = 1.5;
    arma::mat A(16,16,arma::fill::zeros);
    arma::mat B(16,4,arma::fill::zeros);
    arma::mat C(16,16,arma::fill::zeros);
    arma::mat xc(16,1,arma::fill::zeros);
    arma::mat xd(16,1,arma::fill::zeros);
    arma::mat xp(16,1,arma::fill::zeros);
	//arma::mat u(4,1,arma::fill::zeros);
	arma::mat u;    
	arma::mat yt(16,2,arma::fill::zeros);
    arma::mat R(4,4,arma::fill::eye);
    arma::mat Q(16,16,arma::fill::eye);
    arma::mat P(16,16,arma::fill::eye);
    arma::mat p(16,16,arma::fill::eye);
    arma::mat eye(16,16,arma::fill::eye);
	arma::mat y;
    arma::mat K(4,16,arma::fill::zeros);
    arma::mat x;

    setMatrices(&A,&B,&C);
	setAMatrix(&A);
	xc.at(6) = 0;
	xc.at(7) = 0;
	xc.at(8) = 0;
	xc.at(12) = T1;
	xc.at(13) = T2;
	xc.at(14) = T3;
	xc.at(15) = T4;

	xd = xc;
	xd.at(2) = 1;

	//u.at(0) = 1;
	//u.at(1) = 1;
	//u.at(2) = 1;
	//u.at(3) = 1;

	double elapsed_secs; 
	R = R*10;
	Py_Initialize();
	PyRun_SimpleString("import sys; sys.path.append('.')");
	PyRun_SimpleString("import pythLqr;");
	clock_t begin,end;
	begin = clock();
	while(1){
		computeControl(&xp,&xc,&y,&A,&B,&C,&P,&p,&K,&Q,&R,&eye,&u);
		end = clock();	
		elapsed_secs = double(end - begin)/CLOCKS_PER_SEC;
		begin = clock();
		//u = -K * (xc-xd);
		u = -K * (xd-xc);
		u.print("u");	
	}
	//std::cout << elapsed_secs << std::endl;
	Py_Finalize();	
	//printf("%f",elapsed_secs);	
    /*A.print("A:");
    B.print("B:");
    C.print("C:");
    xc.print("xt:");
    xd.print("xd:");
    yt.print("yt:");*/

}
