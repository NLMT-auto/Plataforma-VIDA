#include "WriteAng.h"
#include "../data_struct.h"

#include <iostream>
#include <fstream>
#include <stdint.h>

using namespace std; 

WriteAng::WriteAng()
{
    this->write_data = new PosixShMem("MOTOR", sizeof(WRITE_DATA));
    this->startActivity();
 
}

WriteAng::~WriteAng()
{
    this->stopActivity();
    delete this->write_data;
    this->write_data = NULL; 
}

void WriteAng::startActivity()
{
    ThreadBase::startActivity();
    
}

void WriteAng::stopActivity()
{
    ThreadBase::stopActivity();
    cout << "POTEN." << endl;
}

int WriteAng::run()
{
    this->is_running = 1;
    this->is_alive = 1;
    this->tim1.tv_sec = 0;
    this->tim1.tv_nsec = 100000000L;    /// < thread frequency 10Hz

    WRITE_DATA new_data;
    
   
    while(this->is_alive)
    {   
        this->write_data->read(&new_data, sizeof(WRITE_DATA));  /// < Write the memory

        cout <<   " ÂNGULO: "  << new_data.potentiometer << " |  TEMPO: " << new_data.time << " |  VELOCIDADE: " << new_data.velocity << endl;
    }
    this->is_running = 0;
    pthread_exit(NULL);
    return EXIT_SUCCESS;
}

