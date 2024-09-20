# author: Quincy Cambrel

# Compiler
CXX = g++

# CDS-351 recommended compiler flags
CXXFLAGS = -g -std=c++20 -Wall -Wextra -Wpedantic -Wshadow

# Phony targets to avoid filename conflicts
.PHONY: all clean 

hello.x: hello.o
	$(CXX) hello.o -o hello.x

hello.o: hello.cpp
	$(CXX) $(CXXFLAGS) -c hello.cpp

clean:
	rm -f *.o *.x
