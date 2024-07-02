#include "Steering.h"

Steering::Steering()
{
    this->serialSensors = NULL;
    this->memoryShared = NULL;
    this->startActivity();

    wiringPiSetup();
    pinMode(steeringInterrupt, OUTPUT);
    digitalWrite(steeringInterrupt, LOW);
}

void Steering::startActivity()
{

    this->serialSensors = new Serial("ttyUSB1");
    this->memoryShared = new PosixShMem("sharedMemorySteering", sizeof(Steering_data));

    cout << "Start the thread Sterring" << endl;
    ThreadBase::startActivity();
}

Steering::~Steering()
{
    this->stopActivity();
}

void Steering::stopActivity()
{

    ThreadBase::stopActivity();

    delete serialSensors;

    this->memoryShared = NULL;
    this->serialSensors = NULL;

    cout << "Stopped thread Steering" << endl;
}

int Steering::run()
{

    this->is_running = 1;
    this->is_alive = 1;

    this->tim1.tv_sec = 1;
    this->tim1.tv_nsec = 0;

    while (this->is_alive)
    {
        digitalWrite(steeringInterrupt, HIGH);
        buffer = serialSensors->read('\n');
        digitalWrite(steeringInterrupt, LOW);

        istringstream stream(buffer);
        stream >> steeringData.steering;
        steeringData.time = road_time();

        memoryShared->write(&steeringData, sizeof(Steering_data));

        nanosleep(&this->tim1, NULL);
    }

    this->is_running = 0;
    pthread_exit(NULL);

    return 1;
}