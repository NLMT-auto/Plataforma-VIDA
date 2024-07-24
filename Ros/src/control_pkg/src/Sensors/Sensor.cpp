#include "Sensors.h"

Sensors::Sensors(string name) : Node(name)
{
    this->declare_parameter("frequency_publish", 100.0);
    frequencyPublish = this->get_parameter("frequencyPublish").as_double();

    sensorSerial = new Serial("ttyUSB0");

    wiringPiSetup();
    pinMode(encoderInterrupt, OUTPUT);
    digitalWrite(encoderInterrupt, LOW);

    publisher = this->create_publisher<vida_interfaces::msg::SensorData>("sensorData", 10);
    timer = this->create_wall_timer(chrono::nanoseconds((int)(1e9 / frequencyPublish)), bind(&Sensors::readSensors, this));
    RCLCPP_INFO(this->get_logger(), "sensors has been started");
}

Sensors::~Sensors()
{
    delete sensorSerial;
}

void Sensors::readSensors()
{
    digitalWrite(encoderInterrupt, HIGH);
    dataRecived = sensorSerial->read('\n');
    digitalWrite(encoderInterrupt, LOW);

    auto msg = vida_interfaces::msg::SensorData;

    istringstream stream(buffer);
    stream >> msg.leftPulses
                  stream >>
        msg.rigthPulses;
    stream >> msg.backPulses;
    stream >> msg.steering;

    publisher->publish(msg);
}

int main(int argc, char **argv)
{
    init(argc, argv);                            // inicializado o ROS
    auto node = make_shared<Sensors>("sensors"); // criação do nó usando ponteiro compartilhado e o nomeando
    spin(node);                                  // gira o nó (o mantem vivo até ctrl + c)
    shutdown();                                  // desliga o nó
    return 0;
}