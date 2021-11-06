#include "SetPoint.h"
#include "../../files/test_struct.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <sstream>
#include <utility>  
#include <math.h>
#include <time.h>
#include <vector>

using namespace std;


SetPoint::SetPoint()
{    
    this->data = new PosixShMem("SH_MEM",sizeof(TIMESTAMPED_TEST_DATA));
    this->startActivity();
}

SetPoint::~SetPoint()
{
    this->stopActivity();
}

void SetPoint::startActivity()
{
    ThreadBase::startActivity();
}

void SetPoint::stopActivity()
{
    ThreadBase::stopActivity();
    std::cout << "SET_POINT" << std::endl;
}

int SetPoint::run()
{

    
    this->is_running = 1;
    this->is_alive = 1;
    this->tim1.tv_sec = 0;
    this->tim1.tv_nsec = 100000000L;//10Hz

    TIMESTAMPED_TEST_DATA my_data2;
   
    
    while(this->is_alive)
    {   
            
       this->data->read(&my_data2, sizeof(TIMESTAMPED_TEST_DATA));
        //std::cout<<" SetPoint: "<<my_data2.//velocidade<<std::endl;
        nanosleep(&this->tim1, &this->tim2);
              
    }
    this->is_running = 0;
    pthread_exit(NULL);
    
    return EXIT_SUCCESS;
}