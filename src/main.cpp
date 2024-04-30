#include <iostream>
#include <cstdlib>

#include "Containers/Controle/Controle.h"


using namespace std;

int main (int argc, char* argv[])  /// < Main function that create and calls for reading and writing in memory
{
    Controle *controle = new Controle();   
   

    int quit = -1;
    do
    {   
        cin >> quit;
    }
    while (quit != 0);

    delete controle;

    return EXIT_SUCCESS;
}