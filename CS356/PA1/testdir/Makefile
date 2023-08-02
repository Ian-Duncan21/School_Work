CXXFLAGS=-std=c++17 -Wall

out: main.o
	g++ main.o -o out
	
main.o: main.cc
	g++ -c main.cc
	
clean:
	rm *.o out
