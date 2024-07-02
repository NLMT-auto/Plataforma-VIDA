#include "Control.h"

Control::Control()
{
    this->udp = NULL;
    this->motorSerial = NULL;

    udpData = "NULL";
    lastData = "NULL";

    this->startActivity();
}

void Control::startActivity()
{
    this->udp = new UDP();
    this->motorSerial = new Serial("ttyS1");

    cout << "Start the thread control" << endl;
    ThreadBase::startActivity();
}

Control::~Control()
{
    this->stopActivity();
}

void Control::stopActivity()
{
    ThreadBase::stopActivity();

    delete this->udp;
    delete this->motorSerial;

    this->udp = NULL;
    motorSerial = NULL;

    cout << "Stopped Thread Control" << endl;
}

int Control::run()
{

    this->is_running = 1;
    this->is_alive = 1;

    this->tim1.tv_sec = 0;
    this->tim1.tv_nsec = 10000000L;

    
    while (this->is_alive)
    {
        udpData = udp->read();

        if (udpData != lastData)
        {
            motorSerial->write(udpData);
            lastData = udpData;
        }

        nanosleep(&this->tim1, &this->tim2);
    }

    this->is_running = 0;
    pthread_exit(NULL);

    return 1;
}
