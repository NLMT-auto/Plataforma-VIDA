#include <iostream>
#include <cstdlib>
#include "Containers/Control/Control.h"
#include "Containers/ReadMem/ReadMem.h"

using namespace std;

int main (int argc, char* argv[])  /// < Main function that create and calls for reading and writing in memory
{
    //ReadMem *read = new ReadMem();
    int quit =-1;
    do
    {
        cin >> quit;
    } 
    while (quit != 0);

    //delete read;

    return EXIT_SUCCESS;
}