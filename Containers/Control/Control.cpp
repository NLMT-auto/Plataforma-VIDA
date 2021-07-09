#include "Control.h"
#include "../shmem_struct.h"

#include <iostream>
#include <stdint.h>
#include <cmath>
#include <wiringPi.h>

using namespace std; 

Control::Control()
{
    this->shmem_data = new PosixShMem("SHMEM",sizeof(SHMEM_DATA));
    this->startActivity();
    this->last_pot = 0.0;
    this->last_time = 0.0;

}

Control::~Control()
{
    this->stopActivity();
    // verificar se existe antes de deletar
    if(this->shmem_data){
        delete this->shmem_data;
    }

    this->shmem_data = NULL;
    
     
}

void Control::startActivity()
{
    ThreadBase::startActivity();
    
}

void Control::stopActivity()
{
    ThreadBase::stopActivity();
    cout << "CONTROL." << endl;
}

int Control::run()
{
    this->is_running = 1;
    this->is_alive = 1;
    this->tim1.tv_sec = 0;
    this->tim1.tv_nsec = 100000000L;    /// < thread frequency 10Hz

    SHMEM_DATA my_data;
    
    while(this->is_alive)
    {   
        this->shmem_data->read(&my_data, sizeof(SHMEM_DATA));  /// < Read the memory                     
                                        
        std::cout << "Oi do controle !!!" << endl;
        
        nanosleep(&this->tim1, &this->tim2); 
        
    }
    
    this->is_running = 0;
    pthread_exit(NULL);
    return EXIT_SUCCESS;
}

