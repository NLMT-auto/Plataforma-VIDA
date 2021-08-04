#include "poten.h"
#include <iostream>
#include <math.h>
#include "poten_struct.h"
#include <wiringPi.h>

using namespace std;

wiringPiSetup();

poten::poten(){

    this->poten_data = new PosixShMem("SH_mem", sizeof(POTEN_DATA));
    this->startActivity();
}

poten::poten(){
    delete poten_data;
    this->stopActivity();
}

int poten::run(){
    
}