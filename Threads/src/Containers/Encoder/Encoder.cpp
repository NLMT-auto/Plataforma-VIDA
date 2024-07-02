#include "Encoder.h"

Encoder::Encoder()
{
    this->encoderSerial = NULL;
    this->memoryShared = NULL;

    wiringPiSetup();
    pinMode(encoderInterrupt, OUTPUT);
    digitalWrite(encoderInterrupt, LOW);

    this->startActivity();
}

void Encoder::startActivity()
{
    this->encoderSerial = new Serial("ttyUSB0");
    this->memoryShared = new PosixShMem("sharedMemoryEncoder", sizeof(Encoder_data));

    cout << "Start the thread Encoder" << endl;
    ThreadBase::startActivity();
}

Encoder::~Encoder()
{
    this->stopActivity();
}

void Encoder::stopActivity()
{

    ThreadBase::stopActivity();

    delete encoderSerial;

    this->memoryShared = NULL;
    this->encoderSerial = NULL;

    cout << "Stopped thread Encoder" << endl;
}

int Encoder::run()
{

    this->is_running = 1;
    this->is_alive = 1;

    this->tim1.tv_sec = 1;
    this->tim1.tv_nsec = 0;

    while (this->is_alive)
    {       
        digitalWrite(encoderInterrupt, HIGH);
        buffer = encoderSerial->read('\n');
        digitalWrite(encoderInterrupt, LOW);

        istringstream stream(buffer);
        stream >> encoderData.leftPulses;
        stream >> encoderData.rigthPulses;
        stream >> encoderData.backPulses;
        encoderData.time = road_time();

        memoryShared->write(&encoderData, sizeof(Encoder_data));

        nanosleep(&this->tim1, NULL);
    }

    this->is_running = 0;
    pthread_exit(NULL);

    return 1;
}