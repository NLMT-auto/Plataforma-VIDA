#include "PotenWhrite.h"
#include <iostream>
#include <math.h>
#include "../Utils_poten/poten_struct.h"
#include <fstream>
//#include <wiringPi.h>

using namespace std;

//wiringPiSetup();

PotenWhrite::PotenWhrite()
{
    this->poten_whrite = new PosixShMem("POTEN_DATA", sizeof(POTEN_DATA));
    this->startActivity();
}

PotenWhrite::~PotenWhrite()
{
    this->poten_whrite = NULL;
    this->stopActivity();
}

void PotenWhrite::startActivity()
{
    cout << "Iniciando a escrita no potenciômetro" << endl;
    ThreadBase::startActivity();
}

void PotenWhrite::stopActivity()
{
    ThreadBase::stopActivity();
     printf("Escrita no potenciômetro desligada\n");
}

int PotenWhrite::run(){

    this->is_running = 1;
    this->is_alive = 1;
    this->tim1.tv_sec = 0;
    this->tim1.tv_nsec = 100000000L;//10Hz

    POTEN_DATA mydata;

   // void pinMode(mydata.analogpin, INPUT);

    while(this->is_alive){

        //Pegando os valores da Shared memory -> recebe o valor de angulo e tensão solicitado e transmite para o motor

        this->poten_whrite->read(&mydata, sizeof(POTEN_DATA));
            nanosleep(&this->tim1, &this->tim2);

            cout << endl;
            cout << "valor do angulo: " << mydata.angle_requested << endl;
            cout << "valor de tensão: " << mydata.value_poten_out << endl;
            cout << endl;

            mydata.time = road_time();

    }

    this->is_running = 0;
    pthread_exit(NULL);

    return 1;
}