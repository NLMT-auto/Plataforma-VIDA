CC=g++
CFLAGS = -c -Wall -DRAPIDJON_HAS_STDSTRING=1
LINKER_FLAGS = -lpthread -lrt
INCLUDES = -I..

CONTAINERS = Containers
	POTENTIOMETER = ${CONTAINERS}/Potentiometer
	Steering = ${CONTAINERS}/Steering
	CONTROL = ${CONTAINERS}/Control
	POTEN = ${CONTAINERS}/poten
	READMEM =$(CONTAINERS)/ReadMem

UTILS = Utils
	POSIXSHMEM = $(UTILS)/PosixShMem
	THREADBASE = $(UTILS)/ThreadBase
all: main

main: ReadMem.o PosixShMem.o Control.o poten.o ThreadBase.o main.o
	$(CC) ReadMem.o PosixShMem.o Control.o poten.o ThreadBase.o main.o -o vida $(LINKER_FLAGS)
	rm -rf *.o

ThreadBase.o: $(THREADBASE)/ThreadBase.cpp
	$(CC) $(INCLUDES) $(CFLAGS) $(THREADBASE)/ThreadBase.cpp

PosixShMem.o: $(POSIXSHMEM)/PosixShMem.cpp
	$(CC) $(INCLUDES) $(CFLAGS) $(POSIXSHMEM)/PosixShMem.cpp

Control.o: $(CONTROL)/Control.cpp
	$(CC) $(INCLUDES) $(CFLAGS) $(CONTROL)/Control.cpp

poten.o: $(POTEN)/poten.cpp
	$(CC) $(INCLUDES) $(CFLAGS) $(POTEN)/poten.cpp

ReadMem.o: $(READMEM)/ReadMem.cpp
	$(CC) $(INCLUDES) $(CFLAGS) $(READMEM)/ReadMem.cpp