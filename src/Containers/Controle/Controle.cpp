#include "DefinePin.h"
#include "Controle.h"


Controle::Controle(){
    this->udp = NULL;
    this->motorSerial = NULL;
    this->startActivity();
}

Controle::~Controle(){
    this->stopActivity();
}

void Controle::startActivity() {

    cout << "Inicializando o a thread de controle" << endl;

    this->udp = new UDP();
    this->motorSerial = new Serial(motorInterrupt, BAUD_RATE);

    ThreadBase::startActivity();
}

void Controle::stopActivity() {

    delete this->udp;
    delete this->motorSerial;
    this->udp = NULL;
    this->motorSerial = NULL;

    ThreadBase::stopActivity();
    printf("Thread de controle desligada");
}

int Controle::run() {

    this->is_running = 1;
    this->is_alive = 1;

    this->tim1.tv_sec = 0;
    this->tim1.tv_nsec = 100000000L;

    while (this->is_alive)
    {
        motorSerial->write(udp->read());

        nanosleep(&this->tim1, &this->tim2);
    }

    this->is_running = 0;
    pthread_exit(NULL);

    return 1;
}
