#include "Serial.h"
// C++ libraires
#include <iostream>
#include <string.h>

// Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()

Serial::Serial()
{
    this->data = new PosixShMem("POTEN_DATA", sizeof(USB_DATA));
    setup("/dev/ttyACM0", 9600); // configura a porta serial
    this->startActivity();
}

Serial::~Serial()
{
    this->stopActivity();//////                  ccccccccccccccccccccccccc;
    this->data = NULL;
}

void Serial::startActivity()
{
    cout << "Inicializando o a thread de comunicação serial" << endl;
    ThreadBase::startActivity();
}

void Serial::stopActivity()
{
    ThreadBase::stopActivity();
     printf("Thread de comunicação serial desligada");
}

void Serial::setup(const char *device, int rate) {  // faz o setup de acordo com a porta e a frequencia de cominicação desejada

  bool verification = false;

  // Open the serial port. Change device path as needed (currently set to an standard FTDI USB-UART cable type device)
  serial_port = open(device, rate);

  // Create new termios struct, we call it 'tty' for convention
  struct termios tty;

  // Read in existing settings, and handle any error
  if(tcgetattr(serial_port, &tty) != 0) {
      printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
  }else{
    std::cout << "Porta iniciada" << std::endl;
  }

  tty.c_cflag &= ~PARENB; // Clear parity bit, disabling parity (most common)
  tty.c_cflag &= ~CSTOPB; // Clear stop field, only one stop bit used in communication (most common)
  tty.c_cflag &= ~CSIZE; // Clear all bits that set the data size 
  tty.c_cflag |= CS8; // 8 bits per byte (most common)
  tty.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control (most common)
  tty.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)

  tty.c_lflag &= ~ICANON;
  tty.c_lflag &= ~ECHO; // Disable echo
  tty.c_lflag &= ~ECHOE; // Disable erasure
  tty.c_lflag &= ~ECHONL; // Disable new-line echo
  tty.c_lflag &= ~ISIG; // Disable interpretation of INTR, QUIT and SUSP
  tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
  tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes

  tty.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)
  tty.c_oflag &= ~ONLCR; // Prevent conversion of newline to carriage return/line feed
  // tty.c_oflag &= ~OXTABS; // Prevent conversion of tabs to spaces (NOT PRESENT ON LINUX)
  // tty.c_oflag &= ~ONOEOT; // Prevent removal of C-d chars (0x004) in output (NOT PRESENT ON LINUX)

  tty.c_cc[VTIME] = 10;    // Wait for up to 1s (10 deciseconds), returning as soon as any data is received.
  tty.c_cc[VMIN] = 0;

  // Set in/out baud rate to be 9600
  cfsetispeed(&tty, B9600);
  cfsetospeed(&tty, B9600);

  // Save tty settings, also checking for error
  if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
      printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
      verification = false;
  }else{
    verification = true;
  }
}

void Serial::writeUSB (int serial_port, char mensagem) {
  /// Write to serial port
  unsigned char msg[] = {mensagem};
  write(serial_port, msg, sizeof(msg));
}
  
int Serial::run () {

  // Read bytes. The behaviour of read() (e.g. does it block?,
  // how long does it block for?) depends on the configuration
  // settings above, specifically VMIN and VTIME
  int num_bytes = read(serial_port, &read_buf, sizeof(read_buf));

     this->is_running = 1;
    this->is_alive = 1;

    this->tim1.tv_sec = 0;
    this->tim1.tv_nsec = 100000000L;
    char read_buf [1];// Allocate memory for read buffer, set size according to your needs
    
    while(this->is_alive)
    {


        // Normally you wouldn't do this memset() call, but since we will just receive
        // ASCII data for this example, we'll set everything to 0 so we can
        // call printf() easily.
        memset(&read_buf, '\0', sizeof(read_buf));

        // n is the number of bytes read. n may be 0 if no bytes were received, and can also be -1 to signal an error.
        if (num_bytes < 0) {
            printf("Error reading: %s", strerror(errno));
            std::cout << "Read não funcionando !!!! " << std::endl;
        }else if (num_bytes == 0) {
            std::cout << "Nada na porta serial :| " << std::endl;
        }
  
        std::cout << "Thread de controle limpa !!!" << std::endl;
        //Precisa adicionar os códigos de controle de sensores e atuadores do arduíno 

        // Here we assume we received ASCII data, but you might be sending raw bytes (in that case, don't try and
        // print it to the screen like this!) what has in the printf is "Read %i bytes. Received message: %s", num_bytes, 
        printf(read_buf);

        

    }
    this->is_running = 0;
    pthread_exit(NULL);

    return 1;
    
}

void Serial::close(int serial_port) {
    
    close(serial_port);
}

