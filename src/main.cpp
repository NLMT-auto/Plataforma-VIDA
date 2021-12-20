#include <iostream>
#include <cstdlib>
#include "Containers/Control/Control.h"
#include "Containers/Encoder/ReadMem/ReadMem.h"
#include "Containers/Estecamento/poten/poten.h"

using namespace std;

int main (int argc, char* argv[])  /// < Main function that create and calls for reading and writing in memory
{
    Control *control = new Control();
    Encoder *encoder = new Encoder();
    poten *pot = new poten();

    int quit =-1;
    do
    {
        cin >> quit;
    } 
    while (quit != 0);

    delete control;
    delete encoder;
    delete pot;

    return EXIT_SUCCESS;
}