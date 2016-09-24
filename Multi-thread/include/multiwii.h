#ifndef __MULTIWII__
#define __MULTIWII__

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <ctime>

#include "serial.h"
#include "msp.h"
#include "mspdata.h"

class multiwii{
	public:
	multiwii();
	template<class T>
	bool get(MSP& msp, T& t);
	template<class T>
	void out(MSP& msp, std::ostream& o);
	virtual void rcTest(MSP& msp);
	virtual void accCalTest(MSP& msp);
	virtual void run(std::vector<int> *motVals);
};

#endif
