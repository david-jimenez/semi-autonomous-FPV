#ifndef __PWM__
#define __PWM__

#include <vector>

class PWM{
	public:
	PWM();
	~PWM();
	void run(std::vector<int> *motVals, std::vector<double> *motorLqrAdd, std::vector<double> *combinedMotor, std::vector<int> *aux,std::vector<int> *motorRet);
	bool combineValues(std::vector<int> *motVals, std::vector<double> *motorLqrAdd, std::vector<double> *tempMotorHold, std::vector<int> *motorTarget);
};






#endif
