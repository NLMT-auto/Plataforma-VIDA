#include "poten.h"
#include <iostream>
#include <math.h>
#include "poten_struct.h"
#include <fstream>
//#include <wiringPi.h>

using namespace std;

//wiringPiSetup();

poten::poten()
{
    this->poten_data = new PosixShMem("POTEN_DATA", sizeof(POTEN_DATA));
    this->startActivity();
}

poten::~poten()
{
    this->poten_data = NULL;
    this->stopActivity();
}

void poten::startActivity()
{
    ThreadBase::startActivity();
}

void poten::stopActivity()
{
    ThreadBase::stopActivity();
     printf("Parou a poten\n");
}

int poten::run(){

    this->is_running = 1;
    this->is_alive = 1;
    this->tim1.tv_sec = 0;
    this->tim1.tv_nsec = 100000000L;//10Hz

    fstream arq;
    arq.open("arquivoPoten.txt", ios::in);
    float tensao = 0;

    POTEN_DATA mydata;
    POTEN_DATA mydataEscrita;

   // void pinMode(mydata.analogpin, INPUT);

   if (arq.is_open()){

       //cout << "ABRIU O ARQUIVO" << endl;

    while(this->is_alive){

        // mydata.value_poten_in = analogRead(mydata.analogin);                    //Leitura do valor de tensão do potenciômetro

        arq >> tensao;
        mydata.value_poten_in = tensao;
        //cout << "\n Valor de tensão: " << mydata.value_poten_in << endl;

        //Passando para a SheredMemory

        
        mydata.time = road_time();
        this->poten_data->write(&mydata,sizeof(POTEN_DATA));
        nanosleep(&this->tim1, &this->tim2);
    }

   }else{
       cout << "Nao foi possivel abrir o arquivo" << endl;
   }
    this->is_running = 0;
    pthread_exit(NULL);
    arq.close();

    return 1;
}