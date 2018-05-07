CXX=clang++-5.0
CXXFLAGS=-std=c++17 

all: Board.o Exceptions.o Coordinates.o Value.o

Board.o: Board.cpp Board.hpp
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o

IllegalCharException.o: IllegalCharException.cpp IllegalCharException.hpp
	$(CXX) $(CXXFLAGS) -c IllegalCharException.cpp -o IllegalCharException.o

IllegalCoordinateException.o: IllegalCoordinateException.cpp IllegalCoordinateException.hpp
	$(CXX) $(CXXFLAGS) -c IllegalCoordinateException.cpp -o IllegalCoordinateException.o

Coordinates.o: Coordinates.cpp Coordinates.hpp
	$(CXX) $(CXXFLAGS) -c Coordinates.cpp -o Coordinates.o

Value.o: Value.cpp Value.hpp
	$(CXX) $(CXXFLAGS) -c Value.cpp -o Value.o
clean:
	rm *.o 
