#include <iostream>
#include <cstdlib>

#include "Containers/Controle/Controle.h"
#include "Containers/Registro/Registro.h"
#include "Utils/Serial/Serial.h"
#include "Files/DefinePin.h"


using namespace std;

int main (int argc, char* argv[])  /// < Main function that create and calls for reading and writing in memory
{   
    Serial *serialMotor = new Serial(motorInterrupt, BAUD_RATE);    
    //Controle *controle = new Controle(serialMotor);
    Registro * registro = new Registro(NULL, serialMotor);   

   

    int quit = -1;
    do
    {   
        cin >> quit;
    }
    while (quit != 0);

    //delete controle;
    delete registro;

    return EXIT_SUCCESS;
}