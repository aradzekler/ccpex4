CXX=clang++-5.0
CXXFLAGS=-std=c++17 

all: Board.o Exceptions.o Coordinates.o Value.o

Board.o: Board.cpp Board.hpp
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o

Exceptions.o: Exceptions.cpp Exceptions.hpp
	$(CXX) $(CXXFLAGS) -c Exceptions.cpp -o Exceptions.o

Coordinate.o: Coordinates.cpp Coordinates.hpp
	$(CXX) $(CXXFLAGS) -c Coordinates.cpp -o Coordinates.o

Cell.o: Value.cpp Value.hpp
	$(CXX) $(CXXFLAGS) -c Value.cpp -o Value.o
clean:
	rm *.o 
