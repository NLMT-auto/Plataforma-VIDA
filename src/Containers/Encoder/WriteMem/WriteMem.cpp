#include "WriteMem.h"
#include "../../files/test_struct.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <sstream>
#include <utility>  
#include <math.h>
#include <ctime>

#include <vector>

using namespace std;

int Vetor_velocidades[100];
int cont_aux=0;

int ReadFiles(const char* name) {
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

WriteMem::WriteMem()
{    
    this->data = new PosixShMem("SH_MEM",sizeof(TIMESTAMPED_TEST_DATA));
    this->startActivity();
}

WriteMem::~WriteMem()
{
    this->stopActivity();
}

void WriteMem::startActivity()
{
    ThreadBase::startActivity();
}

void WriteMem::stopActivity()
{
    ThreadBase::stopActivity();
    std::cout << "WRITE" << std::endl;
}

int WriteMem::run()
{
    ReadFiles("M");
    
    this->is_running = 1;
    this->is_alive = 1;
    this->tim1.tv_sec = 0;
    this->tim1.tv_nsec = 100000000L;//10Hz

    TIMESTAMPED_TEST_DATA my_data;
    int my_cont = -1;
    int cont=0;
    double velocity_angular;
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
    this->is_running = 0;
    pthread_exit(NULL);
    
    return EXIT_SUCCESS;
}
