#include "Control.h"                                //Arquivo de declaração da classe Control
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
//#include <wiringPi.h>                             //Biblioteca de manipulação de GPIO para raspberry/odroid
#include <vector>
#include "../../Utils/road_time.h"
#include "../files/general_defines.h"
#include "../files/control_struct.h"
#include "../../Utils/ThreadBase/ThreadBase.h"
#include <fstream>
//Libraries Encoder
#include "../files/test_struct.h"  


//Steering cotrol
Control::Control()
{
    this->data = new PosixShMem("POTEN_DATA", sizeof(CONTROL_DATA));
    this->startActivity();
}

Control::~Control()
{
    this->stopActivity();
    this->data = NULL;
}

void Control::startActivity()
{
    cout << "Inicializando o a thread de controle" << endl;
    ThreadBase::startActivity();
}

void Control::stopActivity()
{
    ThreadBase::stopActivity();
     printf("Thread de controle desligada");
}

int Control::run()
{

    this->is_running = 1;
    this->is_alive = 1;

    this->tim1.tv_sec = 0;
    this->tim1.tv_nsec = 100000000L;
    
    while(this->is_alive)
    {

        std::cout << "Thread de controle limpa !!!" << std::endl;
        //Precisa adicionar os códigos de controle de sensores e atuadores do arduíno

    }
    this->is_running = 0;
    pthread_exit(NULL);

    return 1;
}



