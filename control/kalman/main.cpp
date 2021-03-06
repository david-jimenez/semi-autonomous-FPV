#include <fstream>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <armadillo>
#include <ctime>
#include <octave/oct.h>
#include <octave/octave.h>
#include <octave/parse.h>
#include <octave/toplev.h>

float a,b,m,l,r,Ixx,Iyy,Izz,T1,T2,T3,T4;
Matrix a_matrix;
Matrix b_matrix;
Matrix q_matrix;
Matrix r_matrix;
Matrix k_matrix;
octave_value_list in;
octave_value_list out;

#define g 9.8
#define M_PI 3.14159265358979323846
#define TolZero 2.2204e-14

void setAMatrix(arma::mat *A){

    A->at(6,3) = cos(a)*((T1/m)+(T2/m)+(T3/m)+(T4/m));
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
    A->at(8,15) = cos(a)/m;

}

void setMatrices(arma::mat *A,arma::mat *B,arma::mat *C){
    A->at(0,6) = 1;
    A->at(1,7) = 1;
    A->at(2,8) = 1;
    A->at(3,9) = 1;
    A->at(4,10) = 1;
    A->at(5,11) = 1;
    A->at(6,3) = cos(a)*((T1/m)+(T2/m)+(T3/m)+(T4/m));
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
    A->at(8,15) = cos(a)/m;

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

	A->at(13,13) = -10;
	A->at(13,13) = -10;
	A->at(13,13) = -10;
	A->at(13,13) = -10;

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

void computePrediction(arma::mat *xp, arma::mat *xc, arma::mat *y,
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

/*void lqrold(arma::mat *A, arma::mat *B, arma::mat *Q, arma::mat *R){

	//A->print("A");
	//B->print("B");
	//Q->print("Q");
	arma::mat DINV(4,4,arma::fill::eye);
	arma::mat H12 = -*B * DINV * B->t();
	arma::mat H21 = -*Q;
	//DINV.print("DINV");
	//H12.print("h12");
	//H21.print("h21");
	arma::mat H = join_cols(join_rows(*A,(H12 + H12.t())/2),join_rows((H21 + H21.t())/2,-A->t()));
	H.print("H");
	/*arma::mat mu(32,32,arma::fill::zeros);
	for(int i = 0; i < 32; i++){
		for(int j = 0; j < 32; j++) {
			mu.at(i,j) = H.at(i,i);
		}
	}
	arma::mat mut = mu + mu.t();
	for(int i = 0; i < 32; i++){
		for(int j = 0; j < 32; j++) {
			if(std::abs(M.at(i,j)) < TolZero*mut.at(i,j)){
				mut.at(i,j) = 0;
			}
		}
	}
	arma::mat U;
	arma::mat S;
	schur(S,H);
	S.print("S");

}*/


void computeControl(arma::mat *xp, arma::mat *xc, arma::mat *y,
                       arma::mat *A,  arma::mat *B, arma::mat *C,
                       arma::mat *P, arma::mat *p, arma::mat *K,
                       arma::mat *Q, arma::mat *R, arma::mat *eye,
					   arma::mat *u){
	
	//std::cout << "test" << std::endl;
	//clock_t begin = clock();

	for(octave_idx_type i = 0; i < 16; i++){
		for(octave_idx_type j = 0; j < 16; j++){
			a_matrix(i,j) = A->at(i,j);
		}	
	}
	
	//clock_t end = clock();
	//double elapsed_secs = double(end - begin)/CLOCKS_PER_SEC;
	//std::cout << elapsed_secs << std::endl;	
	//begin = clock();

	for(octave_idx_type i = 0; i < 16; i++){
		for(octave_idx_type j = 0; j < 4; j++){
			b_matrix(i,j) = B->at(i,j);
		}	
	}

	//end = clock();
	//elapsed_secs = double(end - begin)/CLOCKS_PER_SEC;
	//std::cout << elapsed_secs << std::endl;	
	//begin = clock();
	
	in(0) = a_matrix;
	in(1) = b_matrix;
	in(2) = q_matrix;
	in(3) = r_matrix;
	//std::cout << "test" << std::endl;
	out = feval("runLqr",in,1);
	//std::cout << "test2" << std::endl;
	k_matrix = out(0).matrix_value();
	
	//end = clock();
	//elapsed_secs = double(end - begin)/CLOCKS_PER_SEC;
	//std::cout << elapsed_secs << std::endl;	
	//begin = clock();

	for(octave_idx_type i = 0; i < 4; i++){
		for(octave_idx_type j = 0; j < 16; j++){
			K->at(i,j) = k_matrix(i,j);
		}	
	}

	//end = clock();
	//elapsed_secs = double(end - begin)/CLOCKS_PER_SEC;
	//std::cout << elapsed_secs << std::endl;	

	//std::cout << "test" << std::endl;
	

}

int main(int argc, char *argv[])
{

	string_vector arg(2);
  	arg(0) = "";
  	arg(1) = "--silent";
	octave_main (2, arg.c_str_vec (), 1);	

	a_matrix = Matrix(16,16);
	b_matrix = Matrix(16,4);	
	q_matrix = Matrix(16,16);
	r_matrix = Matrix(4,4);	
	

	a = 0;
	b = 0;    
	a = M_PI*a/180;
    b = M_PI*b/180;
    m = 0.62;
    l = 0.15;
    r = 0.5;
    Ixx = 3.02*pow(10,-3);
    Iyy = 3.02*pow(10,-3);
    Izz = 3.02*pow(10,-3);
    T1 = 0.01;
    T2 = 0.01;
    T3 = 0.01;
    T4 = 0.01;
    arma::mat A(16,16,arma::fill::zeros);
    arma::mat B(16,4,arma::fill::zeros);
    arma::mat C(16,16,arma::fill::zeros);
    arma::mat xc(16,1,arma::fill::zeros);
    arma::mat xd(16,1,arma::fill::zeros);
    arma::mat xp(16,1,arma::fill::zeros);
	//arma::mat u(4,1,arma::fill::zeros);
	arma::mat u;    
	arma::mat yt(16,2,arma::fill::zeros);
    arma::mat R(16,16,arma::fill::eye);
    arma::mat Q(16,16,arma::fill::eye);
    arma::mat P(16,16,arma::fill::eye);
    arma::mat p(16,16,arma::fill::eye);
    arma::mat eye(16,16,arma::fill::eye);
	arma::mat y;
    arma::mat K(4,16,arma::fill::zeros);
    arma::mat x;

	for(octave_idx_type i = 0; i < 16; i++){
		for(octave_idx_type j = 0; j < 16; j++){
			q_matrix(i,j) = Q.at(i,j);
		}	
	}

	for(octave_idx_type i = 0; i < 4; i++){
		for(octave_idx_type j = 0; j < 4; j++){
			r_matrix(i,j) = R.at(i,j);
		}	
	}

    setMatrices(&A,&B,&C);
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
	clock_t begin = clock();
	//A.print("A");
	//B.print("B");
	//Q.print("Q");
	//R.print("R");
    //computePrediction(&xp,&xc,&y,&A,&B,&C,&P,&p,&K,&Q,&R,&eye,&u);
	xc.print("xc");
	computeControl(&xp,&xc,&y,&A,&B,&C,&P,&p,&K,&Q,&R,&eye,&u);	
	clock_t end = clock();
	elapsed_secs = double(end - begin)/CLOCKS_PER_SEC;
	std::cout << elapsed_secs << std::endl;
	//printf("%f",elapsed_secs);	
	u = -K * (xc-xd);
	u.print("u");
	computePrediction(&xp,&xc,&y,&A,&B,&C,&P,&p,&K,&Q,&R,&eye,&u);
	xp.print("xp");
	xc = xp;
	computeControl(&xp,&xc,&y,&A,&B,&C,&P,&p,&K,&Q,&R,&eye,&u);
	u.print("u2");
	computePrediction(&xp,&xc,&y,&A,&B,&C,&P,&p,&K,&Q,&R,&eye,&u);
	xp.print("xp2:");
    /*A.print("A:");
    B.print("B:");
    C.print("C:");
    xc.print("xt:");
    xd.print("xd:");
    yt.print("yt:");*/

}
