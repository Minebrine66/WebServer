# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -g

all: server

server:	server.o
	$(CXX) -o server server.o -lm

server.o: server.c 
	$(CXX) $(CXXFLAGS) -c server.cpp

clean:
	rm -rf server server.o