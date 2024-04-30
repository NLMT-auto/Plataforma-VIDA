#include <iostream>
#include <cstdlib>
#include "Containers/Registro/Registro.h"
#include "Containers/Control/Control.h"
#include "Utils/Serial/Serial.h"

using namespace std;

int main (int argc, char* argv[])  /// < Main function that create and calls for reading and writing in memory
{
    Serial *serial = new Serial(14, 15, 10, 9600);
    
    int i = 0;
    while(i<1000){
        string x = "hellor arudino " + to_string(i);
        serial->envia(x);
        delay(50);
        i++;
    }
    
    // Registro *registro = new Registro();

    int quit = -1;
    do
    {   
        cin >> quit;
    }
    while (quit != 0);

    //delete registro;

    return EXIT_SUCCESS;
}