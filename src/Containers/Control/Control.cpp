#include "Control.h"                                //Arquivo de declaração da classe Control
#include "../Estecamento/Utils_poten/poten_struct.h"
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
#include "../../Utils/ThreadBase/ThreadBase.h"
#include <fstream>

//Encoder control
using namespace std;

//wiringPiSetup();

Encoder::Encoder()
{
    this->data = new PosixShMem("SH_MEM",sizeof(TIMESTAMPED_TEST_DATA));
    this->startActivity();
    cout << "thread Encoder funcionando" << endl;
}

Encoder::~Encoder()
{
    this->stopActivity();
}

void Encoder::startActivity()
{
    ThreadBase::startActivity();
}

void Encoder::stopActivity()
{
    ThreadBase::stopActivity();
    std::cout << "Thread de controle do Encoder foi desligada" << std::endl;
}

int Encoder::run()
{
    
	this->is_running = 1;
	this->is_alive = 1;
	this->tim1.tv_sec = 0;
	this->tim1.tv_nsec = 500000000L;//20Hz

	TIMESTAMPED_TEST_DATA my_data;
    int my_cont = -1;                           //machine process counter. 
    int cont=0;                                 //if controler
    double velocity_angular;                    //Saves the angular velocity value. 

    //void pinMode(PINOSENSOR, INPUT);

    clock_t t1, t0,t3;                          //Variables for time manipulation. 
    double t2;                                      
    int parametro=1;                            //Allow parameter to calculate time and angular velocity. 
    t0=clock();
    t1=clock();

	road_time_t previous_time = road_time(); // microseconds ex. 100287238913721
	
	road_time_t current_time;

    ifstream arqEst;
    arqEst.open("Arquivo_dados_controle_encoder.txt");
    int valor_est = 0;

    if(arqEst.is_open()){

        int previous_state = 0;
        int current_state;
        
        long long unsigned int enc_counter = 0;

        while(this->is_alive)
        {    
            //cout << "\nthread Encoder funcionando" << endl;

            arqEst >> valor_est;
            current_state = valor_est;
            
            if(previous_state != current_state)
            {
                ++enc_counter;
                
                previous_state = current_state;
                
                current_time = road_time();
                
                velocity_angular = 2*PI*MIN_ANGLE/((double)(current_time - previous_time)/1000000.0);		//rad/s

                previous_time = current_time;
                
                my_data.velocidade = velocity_angular*RADIUS;
                
                my_data.time1 = current_time;
                
                my_data.data.contador = enc_counter;
            }
            
            this->data->write(&my_data, sizeof(TIMESTAMPED_TEST_DATA));             //Writes linear velocity values to shared memory. 
            std:: cout<< "\nEncoder"<< std:: endl;
            
            nanosleep(&this->tim1, &this->tim2);
        
    }
    }else{

        cout << "Nao foi possivel abrir o arquivo de teste com os dados para o esterçamento, checa se ele foi feito !!!" << endl;
    
    }

    this->is_running = 0;
    pthread_exit(NULL);

    return 1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Steering cotrol
Control::Control()
{
    this->dataCtrl = new PosixShMem("POTEN_DATA", sizeof(POTEN_DATA));
    this->startActivity();
}

Control::~Control()
{
    this->stopActivity();
    this->dataCtrl = NULL;
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

    POTEN_DATA potentiometer;

    double required_angle = 5; // Ângulo solcitado para virar -> usado como referência para o movimento
    
    while(this->is_alive)
    {

        this->dataCtrl->read(&potentiometer, sizeof(POTEN_DATA));  // leitura do valor lido no potenciometro  
            
            
            double var = (potentiometer.value_poten_in/CONST_TRANSF_TENSAO_UM)*CONST_TRANSF_TENSAO_DOIS;  // transormação da tensão lida no potenciômetro em angulo
            potentiometer.value_poten_out = var;

            double giro_qnt = required_angle - var;

            potentiometer.value_poten_out = (giro_qnt/CONST_TRANSF_TENSAO_DOIS)*CONST_TRANSF_TENSAO_UM;

            potentiometer.time = road_time();   //contador de tempo

            //receber os dados de controle 

            double dados_controle = 0; //recebe o ângulo desejado do controle para realizar as correções

            double diferenca = dados_controle - var; //Verifica a diferemça entre o ângulo desejado e o âmgulo atual

            double atuador = 0; //variável que recebe o valor convertido para atuar no motor

            //Atua no motor - Parte de escrita do potenciômetro

            if (diferenca < 0) // significa que a direção do esterçamento está mais a esquerda que o necessário
            {
                // atuador =  (diferenca/CONST_TRANSF_TENSAO_UM)*CONST_TRANSF_TENSAO_DOIS); // Transformação de angulo para tensâo
                //atua em um pino determinado da GPIO
            }else if (diferenca = 0)
            {
                cout << "O carro está na direção certa" << endl;
            }
            else if (diferenca > 0)
            {
                // atuador = (diferenca/CONST_TRANSF_TENSAO_UM)*CONST_TRANSF_TENSAO_DOIS); // Transformação de angulo para tensâo
                //atua em um pino determinado da GPIO
            }

    }
    this->is_running = 0;
    pthread_exit(NULL);

    return 1;
}