#include "Control.h"


Control::Control()
{
    this->memoriaCompartilhada = NULL;
    this->startActivity();

    //pinMode(0, OUTPUT);
    //digitalWrite(0, HIGH);

    //delay(1000);

    
}

Control::~Control()
{
    this->stopActivity();

    // Delete all shared memory, but should be called once in the main.cpp
    if (this->memoriaCompartilhada)
        delete this->memoriaCompartilhada;

    this->memoriaCompartilhada = NULL;
}

void Control::startActivity()
{
    cout << "Inicializando o a thread de controle" << endl;

    this->memoriaCompartilhada = new PosixShMem("memoriaCompartilhada", sizeof(CONTROL_DATA));

    ThreadBase::startActivity();
}

void Control::stopActivity()
{
    // Delete all shared memory, but should be called once in the main.cpp
    if (this->memoriaCompartilhada)
        delete this->memoriaCompartilhada;

    this->memoriaCompartilhada = NULL;

    ThreadBase::stopActivity();
    printf("Thread de controle desligada");
}

int Control::run()
{

    this->is_running = 1;
    this->is_alive = 1;

    this->tim1.tv_sec = 0;
    this->tim1.tv_nsec = 100000000L;

    while (this->is_alive)
    {
        
        this->myData.time = road_time();        
        this->myData.value_out += 1;

        this->memoriaCompartilhada->write(&this->myData, sizeof(CONTROL_DATA));

        
        nanosleep(&this->tim1, &this->tim2);
    }
    this->is_running = 0;
    pthread_exit(NULL);

    return 1;
}
