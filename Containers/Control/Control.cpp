#include "Control.h"
#include "../Steering/Steering_struct.h"
#include "../Potentiometer/Potentiometer_struct.h"
#include <stdio.h> 

Control::Control()
{
    this->steering_data = new PosixShMem("STERING", sizeof(Timestamped_STEERING_DATA));
    this->potentiometer_data = new PosixShMem("POTENTIOMETER", sizeof(Timestamped_POTENTIOMETER_DATA));
    this->startActivity();
}

Control::~Control()
{
    this->stopActivity();
    this->steering_data = NULL;
    this->potentiometer_data = NULL;
}

void Control::startActivity()
{
    ThreadBase::startActivity();
}

void Control::stopActivity()
{
    ThreadBase::stopActivity();
     printf("Control\n");
}

int Control::run()
{
    this->is_running = 1;
    this->is_alive = 1;

    this->tim1.tv_sec = 0;
    this->tim1.tv_nsec = 100000000L;

    Timestamped_STEERING_DATA steering;
    Timestamped_POTENTIOMETER_DATA potentiometer;
    
    while(this->is_alive)
    {
        this->potentiometer_data->read(&potentiometer,sizeof(Timestamped_POTENTIOMETER_DATA));
        
        steering.direction = false;
        steering.speed = (potentiometer.potentiometer/27300.0)*255;
        steering.time = road_time();
        this->steering_data->write(&steering,sizeof(Timestamped_STEERING_DATA));
		nanosleep(&this->tim1, &this->tim2);
    }
    this->is_running = 0;
    pthread_exit(NULL);

    return 1;
}
