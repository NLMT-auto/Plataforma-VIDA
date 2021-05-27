#include <iostream>
#include <cstdlib>
#include "Containers/ReadPot/ReadPot.h"
#include "Containers/WriteAng/WriteAng.h"

using namespace std;

int main (int argc, char* argv[])  /// < Main function that create and calls for reading and writing in memory
{
    ReadPot *write = new ReadPot();
    WriteAng *read = new WriteAng();
    int quit =-1;
    do
    {
        cin >> quit;
    } 
    while (quit != 0);
    
    delete write;
    delete read;

    return EXIT_SUCCESS;
}