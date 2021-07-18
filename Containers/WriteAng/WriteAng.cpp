#include "WriteAng.h"
#include "../shmem_struct.h"

#include <iostream>
#include <stdint.h>

using namespace std; 

WriteAng::WriteAng()
{
    this->shmem_data = new PosixShMem("SHMEM",sizeof(SHMEM_DATA));
    this->startActivity();
 
}

WriteAng::~WriteAng()
{
   this->stopActivity();
    // verificar se existe antes de deletar
    if(this->shmem_data){
        delete this->shmem_data;
    }

    this->shmem_data = NULL; 
}

void WriteAng::startActivity()
{
    ThreadBase::startActivity();
    
}

void WriteAng::stopActivity()
{
    ThreadBase::stopActivity();
    cout << "WRITE." << endl;
}

int WriteAng::run()
{
    this->is_running = 1;
    this->is_alive = 1;
    this->tim1.tv_sec = 0;
    this->tim1.tv_nsec = 100000000L;    /// < thread frequency 10Hz

    SHMEM_DATA my_data;
        
    
   
    while(this->is_alive)
    {   
        this->shmem_data->read(&my_data, sizeof(SHMEM_DATA));  /// < Read the memory

        cout << "POSIÇÃO: " << my_data.potentiometer << "  | TEMPO: " << my_data.time <<  "  | VELOCIDADE: " << my_data.velocity << endl;                      
                                        
        nanosleep(&this->tim1, &this->tim2); 
        
    }
    
    this->is_running = 0;
    pthread_exit(NULL);
    return EXIT_SUCCESS;
}

