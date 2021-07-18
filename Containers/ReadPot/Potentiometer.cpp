#include "Potentiometer.h"
#include "Potentiometer_struct.h"
#include "../Gpio.h"
#include "ads1115.h"
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>

Potentiometer::Potentiometer(int deviceAddr, int channel): deviceAddr(deviceAddr), channel(channel)
{
    this->potentiometer_data = new PosixShMem("POTENTIOMETER", sizeof(Timestamped_POTENTIOMETER_DATA));
    this->startActivity();
}

Potentiometer::~Potentiometer()
{
    this->stopActivity();
	delete this->potentiometer_data;
    this->potentiometer_data = NULL;
}

void Potentiometer::startActivity()
{
    this->openI2CBus((char*)"/dev/i2c-1");    
    ThreadBase::startActivity();
}

void Potentiometer::stopActivity()
{
    ThreadBase::stopActivity();
    printf("Potentiometer\n");
}

int Potentiometer::run()
{
    this->is_running = 1;
    this->is_alive = 1;

    this->tim1.tv_sec = 0;
    this->tim1.tv_nsec = 100000000L;

    Timestamped_POTENTIOMETER_DATA m_data;
    uint16_t value;

    while(this->is_alive)
    {
        Gpio::lockGpio();
        value = this->readVoltage();
        Gpio::unlockGpio();

		this->potentiometer_data->read(&m_data,sizeof(Timestamped_POTENTIOMETER_DATA));
		m_data.time = road_time();
		m_data.potentiometer = value;
		this->potentiometer_data->write(&m_data,sizeof(Timestamped_POTENTIOMETER_DATA));
		nanosleep(&this->tim1, &this->tim2);
    }
    this->is_running = 0;
    pthread_exit(NULL);

    return 1;
}

void Potentiometer::openI2CBus(char* bus)
{
    if((this->i2cFile = open(bus, O_RDWR)) < 0)
	{
		printf("Failed to open the bus.\n");
	}
}

void Potentiometer::setI2CSLAVE(int deviceAddr)
{
	if(ioctl(this->i2cFile, I2C_SLAVE, deviceAddr) < 0)
	{
		printf("Failed to set I2C_SLAVE at address: 0x%x. \n", deviceAddr);
	}
}

void Potentiometer::configDevice(unsigned int config)
{
	this->writeBuf[0] = 0x01;
	this->writeBuf[1] = config >> 8;
	this->writeBuf[2] = config && 0xFF;
	write(this->i2cFile, this->writeBuf, 3);
	usleep(25);
}
uint16_t Potentiometer::readVoltage()
{
    this->setI2CSLAVE(this->deviceAddr);

	unsigned char readBuf[2] = {0};
	uint16_t analogVal;
	unsigned int config = 0;
	
	config = 	CONFIG_REG_OS_SINGLE		|
				CONFIG_REG_PGA_6_144V 		|
				CONFIG_REG_MODE_SINGLE 		|
				CONFIG_REG_DR_128SPS 		|
				CONFIG_REG_CMODE_TRAD 		|
				CONFIG_REG_CPOL_ACTIV_LOW 	|
				CONFIG_REG_CLATCH_NONLATCH 	|
				CONFIG_REG_CQUE_NONE;
				
	switch (this->channel) {
		case 0:
			config |= CONFIG_REG_MUX_CHAN_0;
			break;
		case 1:
			config |= CONFIG_REG_MUX_CHAN_1;
			break;
		case 2:
			config |= CONFIG_REG_MUX_CHAN_2;
			break;
		case 3:
			config |= CONFIG_REG_MUX_CHAN_3;
			break;
		default:
			printf("Give a channel between 0-3\n");
	}
	this->configDevice(config);
	usleep(135000);
	writeBuf[0] = 0x00;
	write(i2cFile, writeBuf, 1);

	if(read(i2cFile, readBuf, 2) != 2) // read data and check error
	{
		printf("Error : Input/Output Error \n");
	}
	else
	{
		analogVal = readBuf[0] << 8 | readBuf[1];
	}

	if(analogVal >= 32768)
	{
		analogVal = 0;
	}
	return analogVal;
}
