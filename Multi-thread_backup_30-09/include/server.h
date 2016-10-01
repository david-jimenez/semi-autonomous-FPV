#ifndef __SERVER__
#define __SERVER__

#include <iostream>
#include <cstdlib>
#include <pthread.h>


class server{
	public:
	server();
	virtual void run(int portno);
	virtual void error(const char *msg);
};

#endif
