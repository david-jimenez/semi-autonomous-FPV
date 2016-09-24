#include <iostream>
#include <octave/oct.h>
#include <octave/octave.h>
#include <octave/parse.h>
#include <octave/toplev.h>

int
main (void)
{
  string_vector argv (2);
  argv(0) = "";
  argv(1) = "--silent";

  octave_main (2, argv.c_str_vec (), 1);

  octave_idx_type n = 2;
  octave_value_list in;

  for (octave_idx_type i = 0; i < n; i++)
    in(i) = octave_value (5 * (i + 2));

  octave_value_list out = feval ("gcd", in, 1);

	Matrix a_matrix = Matrix (4, 4);
	Matrix b_matrix = Matrix (4, 2);
	Matrix q_matrix = Matrix (4, 4);
	Matrix r_matrix = Matrix (2, 2);
	for(octave_idx_type i = 0; i < 4; i++){
		for(octave_idx_type j = 0; j < 4; j++){
		a_matrix(i,j) = 0;
		q_matrix(i,j) = 0;
		b_matrix(i,j/2) = 0;
		}
		
	}
	a_matrix(0,2) = 1;
	a_matrix(1,3) = 1;
	a_matrix(3,1) = 10;	
	b_matrix(2) = 1;
	b_matrix(3) = 1;
	q_matrix(0,0) = 1;
	q_matrix(1,1) = 1;
	q_matrix(2,2) = 1;
	q_matrix(3,3) = 1;
	q_matrix(0,2) = 0;
	r_matrix(0,0) = 1;
	r_matrix(0,1) = 0;
	r_matrix(1,0) = 0;
	r_matrix(1,1) = 1;
	std::cout << "test" << std::endl;
	octave_value_list lqrIn;
	std::cout << "test2" << std::endl;
	lqrIn(0) = a_matrix;
	lqrIn(1) = b_matrix;
	lqrIn(2) = q_matrix;
	lqrIn(3) = r_matrix;
	std::cout << "test3" << std::endl;
	octave_value_list out2 = feval ("runLqr", lqrIn,1);
	std::cout << "test4" << std::endl;

  if (! error_state && out.length () > 0)
    std::cout << "GCD of ["
              << in(0).int_value ()
              << ", "
              << in(1).int_value ()
              << "] is " << out(0).int_value ()
              << std::endl;
  else
    std::cout << "invalid\n";

  clean_up_and_exit (0);
}
