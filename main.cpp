#include <iostream>
#include <cstdlib>
#include "Containers/Control/Control.h"
#include "Containers/ReadPot/ReadPot.h"
#include "Containers/WriteAng/WriteAng.h"

using namespace std;

int main (int argc, char* argv[])  /// < Main function that create and calls for reading and writing in memory
{
    Control *read_write = new Control();
    ReadPot *write = new ReadPot();
    WriteAng *read = new WriteAng();
    int quit =-1;
    do
    {
        cin >> quit;
    } 
    while (quit != 0);
    delete read_write;
    delete write;
    delete read;

    return EXIT_SUCCESS;
}