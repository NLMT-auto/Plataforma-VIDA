#include "Steering.h"
#include "Steering_struct.h"
#include "../Gpio/Gpio.h"
#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h> 

Steering::Steering(int pin1, int pin2, int pwm): pin1(pin1), pin2(pin2), pwm(pwm)
{
    this->steering_data = new PosixShMem("STEERING", sizeof(Timestamped_STEERING_DATA));
    this->startActivity();
}

Steering::~Steering()
{
    this->stopActivity();
	delete this->steering_data;
    this->steering_data = NULL;
}

void Steering::startActivity()
{
    pinMode(this->pin1,OUTPUT);
    pinMode(this->pin2,OUTPUT);
    pinMode(this->pwm,OUTPUT);
    softPwmCreate(this->pwm,0,255);
    ThreadBase::startActivity();
}

void Steering::stopActivity()
{
    ThreadBase::stopActivity();
    Gpio::lockGpio();
    digitalWrite(this->pin1,0);
    digitalWrite(this->pin2,0);
    softPwmWrite(this->pwm,0);
    Gpio::unlockGpio();
    printf("Steering\n");
}

int Steering::run()
{
    this->is_running = 1;
    this->is_alive = 1;

    this->tim1.tv_sec = 0;
    this->tim1.tv_nsec = 100000000L;

    Timestamped_STEERING_DATA m_data;
    road_time();
    while(this->is_alive)
    {
		this->steering_data->read(&m_data,sizeof(Timestamped_STEERING_DATA));
        Gpio::lockGpio();
        digitalWrite(this->pin1,m_data.direction);
        digitalWrite(this->pin2,!m_data.direction);
        softPwmWrite(this->pwm,m_data.speed);
        Gpio::unlockGpio();
        nanosleep(&this->tim1, &this->tim2);
    }
    this->is_running = 0;
    pthread_exit(NULL);

    return 1;
}
