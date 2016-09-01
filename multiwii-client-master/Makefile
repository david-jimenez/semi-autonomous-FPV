CPP = g++

tty: main.cpp serial.o msp.o mspdata.o
	$(CPP) -std=c++11 -o $@ $^

mspdata.o: mspdata.cpp mspdata.h
	$(CPP) -std=c++11 -c -o mspdata.o mspdata.cpp

msp.o: msp.cpp msp.h mspdata.h
	$(CPP) -std=c++11 -c -o msp.o msp.cpp

serial.o: serial.cpp serial.h
	$(CPP) -std=c++11 -c -o serial.o serial.cpp

clean:
	rm -rf *.o tty
