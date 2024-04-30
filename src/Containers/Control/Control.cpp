#include "Control.h" //Arquivo de declaração da classe Control
#include "../files/test_struct.h"
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <sstream>
#include <utility>
#include <math.h>
#include <ctime>
// #include <wiringPi.h>                             //Biblioteca de manipulação de GPIO para raspberry/odroid
#include <vector>
#include "../../Utils/road_time.h"
#include "../files/general_defines.h"
#include "../files/control_struct.h"
#include "../../Utils/ThreadBase/ThreadBase.h"
#include <fstream>
// Libraries Encoder
#include "../files/test_struct.h"

// Steering cotrol
Control::Control()
{
    this->controlData = NULL;
    this->startActivity();
}

Control::~Control()
{
    this->stopActivity();

    // Delete all shared memory, but should be called once in the main.cpp
    if (this->controlData)
        delete this->controlData;

    this->controlData = NULL;
}

void Control::startActivity()
{
    cout << "Inicializando o a thread de controle" << endl;

    this->controlData = new PosixShMem("ControlData", sizeof(CONTROL_DATA));

    ThreadBase::startActivity();
}

void Control::stopActivity()
{
    // Delete all shared memory, but should be called once in the main.cpp
    if (this->controlData)
        delete this->controlData;

    this->controlData = NULL;

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
        this->myData.value_out = this->myData.value_out + 1.0;

        this->controlData->write(&this->myData, sizeof(CONTROL_DATA));

        CONTROL_DATA myData2;

        this->controlData->read(&myData2, sizeof(CONTROL_DATA));

        std::cout
            << "Thread de controle = " << myData2.time << "    Valor = " << myData2.value_out << std::endl;
        // Precisa adicionar os códigos de controle de sensores e atuadores do arduíno

        nanosleep(&this->tim1, &this->tim2);
    }
    this->is_running = 0;
    pthread_exit(NULL);

    return 1;
}
