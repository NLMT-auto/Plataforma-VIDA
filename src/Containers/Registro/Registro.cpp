#include "Registro.h"
#include "../../Utils/Serial/Serial.h"
#include "../DefinePin.h"


Registro::Registro()
{
    this->memoriaCompartilhada = NULL;
    this->startActivity();
}

Registro::~Registro()
{
    this->stopActivity();

    // Delete all shared memory, but should be called once in the main.cpp
    if (this->memoriaCompartilhada)
    {
        delete this->memoriaCompartilhada;
    }

    this->memoriaCompartilhada = NULL;
}

void Registro::startActivity()
{   
    //this->memoriaCompartilhada = new PosixShMem("memoriaCompartilhada", sizeof(pessoa));
    ThreadBase::startActivity();
}

void Registro::stopActivity()
{
    ThreadBase::stopActivity();
    printf("Thread de controle desligada");
}

int Registro::run(){

    this->is_running = 1;
    this->is_alive = 1;

    this->tim1.tv_sec = 0;
    this->tim1.tv_nsec = 100000000L;   

   
    while (this->is_alive)
    {
        
    }

    this->is_running = 0;
    pthread_exit(NULL);

    return 1;
}