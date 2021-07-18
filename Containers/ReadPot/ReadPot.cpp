#include "ReadPot.h"
#include "../shmem_struct.h"

#include <iostream>
#include <stdint.h>
#include <cmath>

using namespace std; 

ReadPot::ReadPot()
{
    this->shmem_data = new PosixShMem("SHMEM",sizeof(SHMEM_DATA));
    this->startActivity();
    this->last_pot = 0.0;
    this->last_time = 0.0;

}

ReadPot::~ReadPot()
{
    this->stopActivity();
    // verificar se existe antes de deletar
    if(this->shmem_data){
        delete this->shmem_data;
    }

    this->shmem_data = NULL;
    
     
}

void ReadPot::startActivity()
{
    ThreadBase::startActivity();
    
}

void ReadPot::stopActivity()
{
    ThreadBase::stopActivity();
    cout << "READ." << endl;
}

int ReadPot::run()
{
    this->is_running = 1;
    this->is_alive = 1;
    this->tim1.tv_sec = 0;
    this->tim1.tv_nsec = 50000000L;    /// < thread frequency 20Hz

    SHMEM_DATA my_data;
    
    float ang;
    float vel;
    float volt = 0.0;
    float x_ang = 0.0;
    road_time_t x_time;
    road_time_t time_pot;
    
               
    while(this->is_alive)
    {         
        
        time_pot = road_time();
         
        if(last_time != 0)
        {   
            volt = volt + 0.1;
            ang = (volt*2*M_PI)/5.0;
            vel = ((ang-last_pot)/(time_pot-last_time))*1000000;

            x_ang = (ang+last_pot)/2;
            x_time = (time_pot+last_time)/2;

        
            my_data.time = x_time;
            my_data.potentiometer = x_ang;
            my_data.velocity = vel;
            this->shmem_data->write(&my_data, sizeof(SHMEM_DATA));  /// < Write the memory

            
            last_pot = ang;
                                        
        }
       

        last_time = time_pot;

        nanosleep(&this->tim1, &this->tim2);           
                            
    }
    
    this->is_running = 0;
    pthread_exit(NULL);
    return EXIT_SUCCESS;
}

