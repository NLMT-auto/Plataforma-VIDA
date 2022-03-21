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
//Libraries Encoder
#include "../files/test_struct.h"  




//Encoder control
int Vetor_velocidades[100];
int cont_aux=0;

//wiringPiSetup();

int ReadFiles(const char* name) {       //Função de leitura de arquivo usado na escrita da função da Write memory
    int aux;
    fstream Arquivo(name, ios::in);
    if (!Arquivo) {
        cout << "Error to read the file " << name << endl;                //Caso não exista o arquivo retorna error
        return (1);
    }  
    while (Arquivo>>aux){
        cont_aux++;
    }
    Arquivo.clear();// Limpo para o proximo uso
    Arquivo.seekg(0,ios::beg);// posiciono o arquivo para o inicio
    
        for(int i=0;i<cont_aux;i++){
            Arquivo >> aux;
            Vetor_velocidades[i]=aux;
        }

    Arquivo.close();
}

Encoder::Encoder()
{
    this->data = new PosixShMem("SH_MEM",sizeof(TIMESTAMPED_TEST_DATA));
    this->startActivity();
    std::cout << "thread Encoder funcionando" << endl;
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

    ReadFiles("M");

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
            std:: cout<< "\nFuncionando (Thread de controle)"<< std:: endl;
            
            nanosleep(&this->tim1, &this->tim2);
            }   

            //Escrita da função

            clock_t t1, t0,t3,t6,t7;
            double t2;
            int parametro=1;
            t6=clock();
            t6= difftime(t6,t6);
            t0=clock();
            t0= difftime(t0,t0);
            cout<<"t0: "<<t0<<endl;
            while(this->is_alive)
            {   
                
                if(cont<cont_aux){
                    
                if(Vetor_velocidades[cont]==1){
                    
                    t1=clock() -t6;
                    
                    cout<<"t1: "<<t1<<endl;
                    parametro=1;
                }else if(Vetor_velocidades[cont]==0){
                    
                    t6=clock() -t1;
                    cout<<"t6: "<<t6<<endl;
                    //t6= clock() -t1;
                    if(parametro==1){
                        
                        t3=difftime(t1, t0);
                        //double( clock() - startTime ) / (double)CLOCKS_PER_SEC
                        t2= ((double)t3)/(double)CLOCKS_PER_SEC;
                        velocity_angular= (0.17453/t2);
                        t0=t1;
                        cout<<"t0: "<<t0 <<endl; 
                    }
                    
                    my_data.time1 = t2;
                    my_data.velocidade = velocity_angular*5;
                    parametro=0;
                
                } 
                cont++;
                }else{

                    my_data.velocidade = 0;
                }
                    my_data.data.contador = my_cont++;
                    this->data->write(&my_data, sizeof(TIMESTAMPED_TEST_DATA));
                    //std:: cout<< "Escrita"<< std:: endl;
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



