CPP = g++

tty: main.cpp testThread.o server.o
	$(CPP) -pthread -std=c++11 -o $@ $^

testThread.o: testThread.cpp testThread.h
	$(CPP) -std=c++11 -c -o testThread.o testThread.cpp

server.o: server.cpp server.h
	$(CPP) -std=c++11 -c -o server.o server.cpp


clean:
	rm -rf *.o tty
