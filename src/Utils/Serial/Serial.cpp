#include "Serial.h"

Serial::Serial(int interrupt, int baudRate)
{    
    this->serialport = serialOpen("/dev/ttyS1", baudRate); 
    this->interrupt = interrupt;
    //wiringPiSetup();    
    //pinMode(interrupt, OUTPUT);
    //digitalWrite(interrupt, LOW);
    
}

Serial::~Serial(){
    serialClose(serialport);
}

void Serial::write(string s){ 
    serialPrintf(serialport, "%s\n",s.c_str());     
}

string Serial::read(char c)
{

    //digitalWrite(interrupt, HIGH);
    
    char receivedChar[256];
    int indice = 0;
    
    bool fim = false;
    do
    {           
      if (serialDataAvail(serialport)) { // Verifica se há dados disponíveis para leitura
           
            char incomingByte = serialGetchar(serialport); // Lê um byte da porta serial

            if (incomingByte == '\n' || incomingByte == c) { // Se encontrou um caractere de término de linha
                receivedChar[indice] = '\0'; // Adiciona um terminador de string ao final     
                fim = true;                       
            } 
            else {
                receivedChar[indice++] = incomingByte; // Armazena o byte no buffer e incrementa o índice
            }
        }
    }while(!fim);

    //digitalWrite(interrupt, LOW);
    
    return receivedChar;
}

