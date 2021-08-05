#include "Control.h"
#include "../Steering/Steering_struct.h"
#include "../Potentiometer/Potentiometer_struct.h"
#include "../files/test_struct.h"
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <sstream>
#include <utility>  
#include <math.h>
#include <ctime>
#include <wiringPi.h>
#include <vector>
#include "../../Utils/road_time.h"
#include "../files/general_defines.h"

//Encoder control
using namespace std;

wiringPiSetup();

WriteMem::WriteMem()
{
    this->data = new PosixShMem("SH_MEM",sizeof(TIMESTAMPED_TEST_DATA));
    this->startActivity();
}

WriteMem::~WriteMem()
{
    this->stopActivity();
}

void WriteMem::startActivity()
{
    ThreadBase::startActivity();
}

void WriteMem::stopActivity()
{
    ThreadBase::stopActivity();
    std::cout << "WRITE" << std::endl;
}

int WriteMem::run()
{
  
	this->is_running = 1;
	this->is_alive = 1;
	this->tim1.tv_sec = 0;
	this->tim1.tv_nsec = 500000000L;//20Hz

	TIMESTAMPED_TEST_DATA my_data;
    int my_cont = -1;                           //machine process counter. 
    int cont=0;                                 //if controler
    double velocity_angular;                    //Saves the angular velocity value. 

    void pinMode(PINOSENSOR, INPUT);

    clock_t t1, t0,t3;                          //Variables for time manipulation. 
    double t2;                                      
    int parametro=1;                            //Allow parameter to calculate time and angular velocity. 
    t0=clock();
    t1=clock();

	road_time_t previous_time = road_time(); // microseconds ex. 100287238913721
	
	road_time_t current_time;
	
	int previous_state = digitalRead(PINOSENSOR);
	int current_state;
	
	long long unsigned int enc_counter = 0;

    while(this->is_alive)
    {    
		current_state = digitalRead(PINOSENSOR);
		
        if(previous_state != current_state)
		{
			++enc_counter;
			
			previous_state = current_state;
			
			current_time = road_time();
			
			velocity_angular = 2*PI*MIN_ANGLE/((double)(current_time - previous_time)/1000000.0);		//rad/s

            previous_time = current_time;
			
			my_data.velocidade = velocity_angular*RADIUS;
			
			my_data.time1 = current_time;
			
			my_data.data.contador = enc_counter;
        }
        
		
		this->data->write(&my_data, sizeof(TIMESTAMPED_TEST_DATA));             //Writes linear velocity values to shared memory. 
		//std:: cout<< "Escrita"<< std:: endl;
		
		nanosleep(&this->tim1, &this->tim2);
       
    }
    this->is_running = 0;
    pthread_exit(NULL);

    return 1;
}
//Steering cotrol
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

//Steering control 2

