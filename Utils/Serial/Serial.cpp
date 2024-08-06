#include "Serial.h"

Serial::Serial(string port)
{
    string aux = "/dev/" + port;
    port = aux;

    this->serialport = serialOpen(port.c_str(), BAUD_RATE);    
}

Serial::~Serial()
{
    serialClose(serialport);
}

void Serial::write(string s)
{
    serialPrintf(serialport, "%s\n", s.c_str());
}

string Serial::read(char c)
{
    char receivedChar[256];
    int index = 0;

    bool end = false;
    auto start = chrono::high_resolution_clock::now();
    do
    {
        // Verifica se há dados disponíveis para leitura
        if (serialDataAvail(serialport))
        {
            char incomingByte = serialGetchar(serialport); // Lê um byte da porta serial

            // Se encontrou um caractere de término de linha
            if (incomingByte == '\n' || incomingByte == c)
            {
                receivedChar[index] = '\0'; // Adiciona um terminador de string ao final
                end = true;
            }

            else
            {
                receivedChar[index++] = incomingByte; // Armazena o byte no buffer e incrementa o índice
            }
        }

        auto now = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::milliseconds>(now - start).count();

        if (elapsed > 1000)
        {
            receivedChar[index++] = '-';
            receivedChar[index++] = '1';
            receivedChar[index] = '\0';
            end = true;
        }

    } while (!end);
    
    return receivedChar;
}
