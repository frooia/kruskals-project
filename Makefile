all: kruskals

kruskals: 
	g++ -g -o kruskals.o kruskals.cpp

clean:
	rm -f *.o kruskals
