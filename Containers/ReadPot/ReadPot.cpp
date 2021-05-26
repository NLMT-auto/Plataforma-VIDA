#include "ReadPot.h"
#include "../potentiometer_struct.h"

#include <iostream>
#include <stdint.h>
#include <cmath>

using namespace std; 

ReadPot::ReadPot()
{
    this->potentiometer_data = new PosixShMem("POTENTIOMETER",sizeof(POTENTIOMETER_DATA));
    this->startActivity();
 
}

ReadPot::~ReadPot()
{
    this->stopActivity();
    delete this->potentiometer_data;
    this->potentiometer_data = NULL; 
}

void ReadPot::startActivity()
{
    ThreadBase::startActivity();
    
}

void ReadPot::stopActivity()
{
    ThreadBase::stopActivity();
    cout << "POTEN." << endl;
}

int ReadPot::run()
{
    this->is_running = 1;
    this->is_alive = 1;
    this->tim1.tv_sec = 0;
    this->tim1.tv_nsec = 50000000L;    /// < thread frequency 20Hz

    POTENTIOMETER_DATA my_data;
    
    int volt[2];
    double ang[2];
    double vel;
    double v_ang[2];
    double v_time[2];
    double m_ang;
    double m_time;
    int v_volt[233];

    for(int j=0; j<234; j++){
        v_volt[j] = j;
    }
    int j=0;           
    while(this->is_alive && j<234)
    {   
        
        int i=0;
        volt[i] = v_volt[j];
        ang[i] = (volt[i]*2*M_PI)/233;
        v_ang[i] = ang[i];
        v_time[i] = road_time();
        j++;
        i++;
        volt[i] = v_volt[j];
        ang[i] = (volt[i]*2*M_PI)/233;
        v_ang[i] = ang[i];
        v_time[i] = road_time();
        j++;
        i++;
        
        vel = (v_ang[i]-v_ang[i-1])/((v_time[i]-v_time[i-1])/1000000);

        m_ang = (v_ang[1]+v_ang[0])/2;
        m_time = (v_time[1]+v_time[0])/2;

        my_data.time = road_time();
        my_data.potentiometer = m_ang;
        my_data.velocity = vel;                         
        this->potentiometer_data->write(&my_data, sizeof(POTENTIOMETER_DATA));  /// < Write the memory
        nanosleep(&this->tim1, &this->tim2);
                
    }
    
    this->is_running = 0;
    pthread_exit(NULL);
    return EXIT_SUCCESS;
}

