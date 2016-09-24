#ifndef __PWM__
#define __PWM__

#include <vector>

class PWM{
	public:
	PWM();
	~PWM();
	void run(std::vector<int> *motVals);
};






#endif
