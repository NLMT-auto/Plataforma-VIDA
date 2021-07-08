#include <iostream>
#include <cstdlib>
#include "Containers/ReadPot/ReadPot.h"
#include "Containers/WriteAng/WriteAng.h"
#include "Containers/Control/Control.h"

using namespace std;

int main (int argc, char* argv[])  /// < Main function that create and calls for reading and writing in memory
{
    ReadPot *write = new ReadPot();
    WriteAng *read = new WriteAng();
    Control *control = new Control();
    int quit =-1;
    do
    {
        cin >> quit;
    } 
    while (quit != 0);
    
    delete write;
    delete read;
    delete control;

    return EXIT_SUCCESS;
}