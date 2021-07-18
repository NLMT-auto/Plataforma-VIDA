CC=g++
CFLAGS = -c -Wall -DRAPIDJON_HAS_STDSTRING=1
LINKER_FLAGS = -lpthread -lrt
INCLUDES = -I..

CONTAINERS = Containers
	POTENTIOMETER = ${CONTAINERS}/Potentiometer
	Steering = ${CONTAINERS}/Steering
	CONTROL = ${CONTAINERS}/Control
	GPIO = ${CONTAINERS}/Gpio

UTILS = Utils
	POSIXSHMEM = $(UTILS)/PosixShMem
	THREADBASE = $(UTILS)/ThreadBase
all: main

main: Potentiometer.o PosixShMem.o Control.o Gpio.o Steering.o ThreadBase.o main.o
	$(CC) Potentiometer.o PosixShMem.o Control.o Gpio.o Steering.o ThreadBase.o main.o -o TesteThread $(LINKER_FLAGS)
	rm -rf *.o

ThreadBase.o: $(THREADBASE)/ThreadBase.cpp
	$(CC) $(INCLUDES) $(CFLAGS) $(THREADBASE)/ThreadBase.cpp

PosixShMem.o: $(POSIXSHMEM)/PosixShMem.cpp
	$(CC) $(INCLUDES) $(CFLAGS) $(POSIXSHMEM)/PosixShMem.cpp

Potentiometer.o: $(POTENTIOMETER)/Potentiometer.cpp
	$(CC) $(INCLUDES) $(CFLAGS) $(POTENTIOMETER)/Potentiometer.cpp

Control.o: $(CONTROL)/Control.cpp
	$(CC) $(INCLUDES) $(CFLAGS) $(CONTROL)/Control.cpp

Gpio.o: $(GPIO)/Gpio.cpp
	$(CC) $(INCLUDES) $(CFLAGS) $(GPIO)/Gpio.cpp

Steering.o: $(STEERING)/Steering.cpp
	$(CC) $(INCLUDES) $(CFLAGS) $(STEERING)/Steering.cpp