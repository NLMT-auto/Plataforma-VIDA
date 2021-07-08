CC=g++
CFLAGS = -c -Wall -DRAPIDJON_HAS_STDSTRING=1
LINKER_FLAGS = -lpthread -lrt
INCLUDES = -I..

CONTAINERS = Containers
	READPOT = ${CONTAINERS}/ReadPot
	WRITEANG = ${CONTAINERS}/WriteAng
	CONTROL = ${CONTAINERS}/Control

UTILS = Utils
	POSIXSHMEM = $(UTILS)/PosixShMem
	THREADBASE = $(UTILS)/ThreadBase
all: main

main: ReadPot.o WriteAng.o PosixShMem.o Control.o ThreadBase.o main.o
	$(CC) ReadPot.o WriteAng.o PosixShMem.o Control.o ThreadBase.o main.o -o TesteThread $(LINKER_FLAGS)
	rm -rf *.o

ThreadBase.o: $(THREADBASE)/ThreadBase.cpp
	$(CC) $(INCLUDES) $(CFLAGS) $(THREADBASE)/ThreadBase.cpp

PosixShMem.o: $(POSIXSHMEM)/PosixShMem.cpp
	$(CC) $(INCLUDES) $(CFLAGS) $(POSIXSHMEM)/PosixShMem.cpp

ReadPot.o: $(READPOT)/ReadPot.cpp
	$(CC) $(INCLUDES) $(CFLAGS) $(READPOT)/ReadPot.cpp

WriteAng.o: $(WRITEANG)/WriteAng.cpp
	$(CC) $(INCLUDES) $(CFLAGS) $(WRITEANG)/WriteAng.cpp

Control.o: $(CONTROL)/Control.cpp
	$(CC) $(INCLUDES) $(CFLAGS) $(CONTROL)/Control.cpp
