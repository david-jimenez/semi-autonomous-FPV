#include <iostream>
#include <cstdlib>
#include <pthread.h>


class server{
	public:
	server();
	virtual void run(int portno);
	virtual void error(const char *msg);
};
