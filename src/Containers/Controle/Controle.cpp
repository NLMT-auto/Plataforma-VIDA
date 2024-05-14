#include "Controle.h"


Controle::Controle(){
    this->udp = NULL; 
    this->serialMotor = NULL;   
    this->startActivity();
}

Controle::Controle(Serial *serialMotor){
    this->udp = NULL; 
    this->serialMotor = serialMotor;   
    this->startActivity();
}

Controle::~Controle(){
    this->stopActivity();
}

void Controle::startActivity() {

    cout << "Inicializando o a thread de controle" << endl;

    this->udp = new UDP();

    if(serialMotor == NULL)
    {  
        serialMotor = new Serial(motorInterrupt, BAUD_RATE);
    }


    ThreadBase::startActivity();
}

void Controle::stopActivity() {

    delete this->udp;
    delete serialMotor;
    
    this->udp = NULL;
    serialMotor = NULL;

    ThreadBase::stopActivity();
    printf("Thread de controle desligada");
}

int Controle::run() {

    this->is_running = 1;
    this->is_alive = 1;

    this->tim1.tv_sec = 0;
    this->tim1.tv_nsec = 10L;

    

   while (this->is_alive)
    {
        serialMotor->write(udp->read());        
        nanosleep(&this->tim1, &this->tim2);
    }

    this->is_running = 0;
    pthread_exit(NULL);

    return 1;
}
