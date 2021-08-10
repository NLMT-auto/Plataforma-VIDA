#include "poten.h"
#include <iostream>
#include <math.h>
#include "poten_struct.h"
//#include <wiringPi.h>

using namespace std;

//wiringPiSetup();

poten::poten(){

    this->poten_data = new PosixShMem("SH_mem", sizeof(POTEN_DATA));
    this->startActivity();
}

poten::~poten(){
    delete poten_data;
    this->stopActivity();
}

int poten::run(){

    this->is_running = 1;
    this->is_alive = 1;
    this->tim1.tv_sec = 0;
    this->tim1.tv_nsec = 100000000L;//10Hz

    POTEN_DATA mydata;

   // void pinMode(mydata.analogpin, INPUT);

    while(this->is_alive){

       // mydata.value_poten_in = analogRead(mydata.analogin);                    //Leitura do valor de tensão do potenciômetro

        //Passando para a SheredMemory

        this->poten_data->read(&mydata,sizeof(POTEN_DATA));
        mydata.time = road_time();
        mydata.value_poten_out = (mydata.value_poten_in/27300.0)*255;           //Conversão do valor de tensão para graus
        this->poten_data->write(&mydata,sizeof(POTEN_DATA));
        nanosleep(&this->tim1, &this->tim2);
    }
    this->is_running = 0;
    pthread_exit(NULL);

    return 1;
}