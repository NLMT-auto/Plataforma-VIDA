#include "Control.h"
#include "../potentiometer_struct.h"
#include "../data_struct.h"

#include <cmath>
#include <iostream>

using namespace std; 

Control::Control()
{
    this->potentiometer_data = new PosixShMem("POTENTIOMETER",sizeof(POTENTIOMETER_DATA)); /// < Reads data from the test_struct.h structure
    this->write_data = new PosixShMem("MOTOR",sizeof(WRITE_DATA)); 
    this->startActivity();
}

Control::~Control()
{
    this->stopActivity();
    delete this->potentiometer_data;
}

void Control::startActivity()
{
    ThreadBase::startActivity();
}

void Control::stopActivity()
{
    ThreadBase::stopActivity();
    cout << "READ" << endl;
}

int Control::run()
{
    this->is_running = 1;
    this->is_alive = 1;
    this->tim1.tv_sec = 0;
    this->tim1.tv_nsec = 100000000L;    /// < thread frequency 10Hz

    POTENTIOMETER_DATA my_data;
    WRITE_DATA new_data;

        
    while(this->is_alive)
    {   
        
        this->potentiometer_data->read(&my_data, sizeof(POTENTIOMETER_DATA));  /// < Read the memory
        new_data.potentiometer = my_data.potentiometer;
        new_data.time = my_data.time;
        new_data.velocity = my_data.velocity;               
               
        this->write_data->write(&new_data, sizeof(WRITE_DATA));  /// < Write the memory
        
        nanosleep(&this->tim1, &this->tim2);
    }
    this->is_running = 0;
    pthread_exit(NULL);
    return EXIT_SUCCESS;
}

