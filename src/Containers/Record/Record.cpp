#include "Record.h"

Record::Record()
{
    this->memorySharedEncoder = NULL;
    this->memorySharedSteering = NULL;

    // inicializa valor de leitura da memoria compartilhada
    this->encoderData.leftPulses = 0;
    this->encoderData.rigthPulses = 0;
    this->encoderData.backPulses = 0;
    this->lastDataEncoder = road_time();

    this->steeringData.steering = 0;
    this->steeringData.time = road_time();

    this->startActivity();
}

void Record::startActivity()
{
    this->memorySharedEncoder = new PosixShMem("sharedMemoryEncoder", sizeof(Encoder_data));
    this->memorySharedSteering = new PosixShMem("sharedMemorySteering", sizeof(Steering_data));

    cout << "Start the thread Record" << endl;
    ThreadBase::startActivity();
}

Record::~Record()
{
    saveEncoder();
    saveSteering();
    this->stopActivity();
}

void Record::stopActivity()
{
    ThreadBase::stopActivity();

    if (memorySharedEncoder != NULL)
    {
        delete memorySharedEncoder;
    }

    if (memorySharedSteering != NULL)
    {
        delete memorySharedSteering;
    }

    memorySharedEncoder = NULL;
    memorySharedSteering = NULL;

    cout << "Stopped Thread Record" << endl;
}

int Record::run()
{
    this->is_running = 1;
    this->is_alive = 1;

    this->tim1.tv_sec = 0;
    this->tim1.tv_nsec = 10000000L;

    while (this->is_alive)
    {
        memorySharedEncoder->read(&encoderData, sizeof(Encoder_data));
        memorySharedSteering->read(&steeringData, sizeof(Steering_data));

        if (encoderData.time != lastDataEncoder)
        {

            lastDataEncoder = encoderData.time;

            bufferEncoder << encoderData.time << ";"
                          << encoderData.leftPulses << ";"
                          << encoderData.rigthPulses << ";"
                          << encoderData.backPulses << endl;
        }
        ++countEncoder;

        if (steeringData.time != lastDataSteering)
        {

            lastDataSteering = steeringData.time;

            bufferSteering << steeringData.time << ";"
                           << steeringData.steering << endl;
        }
        ++countSteering;

        if ((countEncoder % 100) == 0)
        {
            saveEncoder();
            bufferEncoder.str("");
        }

        if ((countSteering % 100) == 0)
        {
            saveSteering();
            bufferSteering.str("");
        }

        nanosleep(&this->tim1, NULL);
    }

    this->is_running = 0;
    pthread_exit(NULL);

    return 1;
}

void Record::saveEncoder()
{
    outputEncoder.open("../EncoderDataRecorder.txt", ios_base::out | ios_base::app);
    outputEncoder << bufferEncoder.str();
    outputEncoder.close();
}

void Record::saveSteering()
{
    outputSteering.open("../SteeringDataRecorder.txt", ios_base::out | ios_base::app);
    outputSteering << bufferSteering.str();
    outputSteering.close();
}