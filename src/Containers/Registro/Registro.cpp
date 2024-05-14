#include "Registro.h"

Registro::Registro()
{   
    this->serialEncoder = NULL;
    this->serialMotor = NULL;
    this->memoriaCompartilhada = NULL;
    this->startActivity();
}

Registro::Registro(Serial *serialEncoder, Serial *serialMotor)
{   
    this->serialEncoder = serialEncoder;
    this->serialMotor = serialMotor;
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
    cout << "Inicializando o a thread de registro" << endl;

    if(serialMotor == NULL)
    {
        serialMotor = new Serial(motorInterrupt, BAUD_RATE);
    }

    if(serialEncoder == NULL)
    {
        //serialEncoder = new Serial(encoderInterrupt, BAUD_RATE);
    }
    this->memoriaCompartilhada = new PosixShMem("memoriaCompartilhada", sizeof(encoderData));
    ThreadBase::startActivity();
}

void Registro::stopActivity()
{       
    delete serialMotor;
    delete serialEncoder;

    serialMotor = NULL;
    serialMotor = NULL;
    
    if (this->memoriaCompartilhada)
        delete this->memoriaCompartilhada;

    this->memoriaCompartilhada = NULL;

    ThreadBase::stopActivity();
    printf("Thread de controle desligada");
}

int Registro::run(){

    this->is_running = 1;
    this->is_alive = 1;

    this->tim1.tv_sec = 3;
    this->tim1.tv_nsec = 0;   

   
    while (this->is_alive)
    {
        string aux;
        
        aux = serialMotor->read('\n');
        cout<<aux<<endl;

        nanosleep(&this->tim1, &this->tim2);
        
    }

    this->is_running = 0;
    pthread_exit(NULL);

    return 1;
};