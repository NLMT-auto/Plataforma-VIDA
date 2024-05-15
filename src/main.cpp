#include <iostream>
#include <cstdlib>

#include "Containers/Controle/Controle.h"
#include "Containers/Registro/Registro.h"
#include "Utils/Serial/Serial.h"
#include "Files/DefinePin.h"


using namespace std;

int main (int argc, char* argv[])  /// < Main function that create and calls for reading and writing in memory
{      
    Controle *controle = new Controle();
    //Registro * registro = new Registro(NULL, serialMotor);

    11;

    int quit = -1;
    do
    {   
        cin >> quit;
    }
    while (quit != 0);

    delete controle;
    //delete registro;

    return EXIT_SUCCESS;
}