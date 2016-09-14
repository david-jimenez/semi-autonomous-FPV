CPP = g++

tty: source/main.cpp source/testThread.o source/server.o source/multiwii.o source/msp.o source/mspdata.o source/serial.o
	$(CPP) -std=c++11 -pthread -o $@ $^

source/testThread.o: source/testThread.cpp include/testThread.h
	$(CPP) -std=c++11 -c -o source/testThread.o source/testThread.cpp

source/server.o: source/server.cpp include/server.h
	$(CPP) -std=c++11 -c -o source/server.o source/server.cpp

source/mspdata.o: source/mspdata.cpp include/mspdata.h
	$(CPP) -std=c++11 -c -o source/mspdata.o source/mspdata.cpp

source/msp.o: source/msp.cpp include/msp.h include/msp.h
	$(CPP) -std=c++11 -c -o source/msp.o source/msp.cpp

source/multiwii.o: source/multiwii.cpp include/multiwii.h
	$(CPP) -std=c++11 -c -o source/multiwii.o source/multiwii.cpp

source/serial.o: source/serial.cpp include/serial.h
	$(CPP) -std=c++11 -c -o source/serial.o source/serial.cpp

clean:
	rm -rf *.o tty
