# Compiler
CC = gcc

# Compiler flags
CCFLAGS = -Wall -Wextra -g

all: server

server:	server.o
	$(CC) -o server server.o -lm

server.o: server.cpp 
	$(CC) $(CCFLAGS) -c server.cpp

clean:
	rm -rf server server.o