#include <iostream>
#include <fstream>
#include <stdint.h>

using namespace std;

void WriteFile(){
    fstream my_file;
    float ang = 0; 
    my_file.open("my_control.txt", ios::out);
    if(!my_file)
    {
        cout << "No such file" << endl;
    } 
    else
    {
        for(int i = 12; i<266; i++)
        {   
            ang = (i*6.28)/254;
            my_file << ang << endl;
        }
        for(int i=271; i>16; i--)
        {
            ang = (i*6.28)/254;
            my_file << ang << endl;
        }
        for(int i = 12; i<266; i++)
        {   
            ang = (i*6.28)/254;
            my_file << ang << endl;
        }
        for(int i=271; i>16; i--)
        {
            ang = (i*6.28)/254;
            my_file << ang << endl;
        }
                                 
    }
    
}

void ReadFile(){
    int val;
    fstream my_file;
    my_file.open("my_file.txt", ios::in);
    if(my_file.is_open()) 
    {
        while (!my_file.eof())
        {
            my_file >> val;
            cout << val << endl;   
        }    
    }
    else
    {
        cout << "No such file" << endl;
    }
   
    
}

int main()
{   
    WriteFile();
    ReadFile();

    return 0;
}

