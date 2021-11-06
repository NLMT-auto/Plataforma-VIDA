#include <iostream>
#include <cstdlib>
#include "Containers/Control/Control.h"
#include "Containers/Encoder/ReadMem/ReadMem.h"

using namespace std;

int main (int argc, char* argv[])  /// < Main function that create and calls for reading and writing in memory
{
    Control *control = new Control();
    Encoder *encoder = new Encoder();
    int quit =-1;
    do
    {
        cin >> quit;
    } 
    while (quit != 0);

    delete control;

    return EXIT_SUCCESS;
}