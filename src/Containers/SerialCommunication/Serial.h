#ifndef SERIAL_H
#define SERIAL_H
#include "../../Utils/PosixShMem/PosixShMem.h"
#include "../../Utils/ThreadBase/ThreadBase.h"
#include <string>
#include <stdio.h>
#include <iostream>

//Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()

using namespace std;
class Serial: public ThreadBase
{
public:
     Serial();
    ~Serial();

private:

// lembretes -> A thred de leitura tem q ficar ativa todo o tempo enviando dados para a memória compartilhada
// A parte de escrita deve ser chamada somente quando necessário enviar alguma informação para os controladores, tudo deve funcionar usando o esquema de semáforos

    //variables
    PosixShMem *data;
    

    //methods
    void startActivity() override;
    void stopActivity() override;
    int run() override;
    int setup(const char *device, int rate);
    void close(int serial_port);
    void readUSB(const char *device, int rate, int serial_port); 
    void writeUSB(int serial_port, char mensagem); 

    
    
};
#endif