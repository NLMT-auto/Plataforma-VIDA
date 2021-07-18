#include "Gpio.h"
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

sem_t *Gpio::sem_pt = NULL;

Gpio::Gpio()
{
    wiringPiSetup();

    if((Gpio::sem_pt = sem_open("Semaphore_GPIO", O_RDWR, 0)) == SEM_FAILED)
	{
		if((Gpio::sem_pt = sem_open("Semaphore_GPIO", O_CREAT | O_RDWR, 0666, 1)) == SEM_FAILED)
		{
			perror("IPC error: sem_open_Semaphore_GPIO");
			exit(EXIT_FAILURE);
		}
	}
    this->encoder = new Encoder(27,20);
    this->motor = new Motor(4,5,6);
    this->potentiometer = new Potentiometer(0x48,0);
}

Gpio::~Gpio()
{
    delete this->motor;
    delete this->potentiometer;
    this->motor = NULL;
    this->potentiometer = NULL;
    if (Gpio::sem_pt)
    {
	    if(sem_close(Gpio::sem_pt) == -1)
        {
	        perror("IPC error: sem_close_Semaphore_GPIO");
        }
    }
    Gpio::sem_pt = NULL;
}

void Gpio::lockGpio()
{
    if (sem_wait(Gpio::sem_pt) == -1)
	{
		perror("IPC error: sem_wait_Semaphore_GPIO");
	}
}

void Gpio::unlockGpio()
{
    if (sem_post(Gpio::sem_pt) == -1)
	{
		perror("IPC error: sem_post_Semaphore_GPIO");
	}
}
