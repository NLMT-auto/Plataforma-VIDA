#include "Sensors.h"

Sensors::Sensors(string name) : Node(name)
{
    this->declare_parameter("frequency_publish", 2.0);
    frequencyPublish = this->get_parameter("frequency_publish").as_double();

    sensorSerial = new Serial("ttyACM0");

    wiringPiSetup();
    pinMode(sensorInterrupt, OUTPUT);
    digitalWrite(sensorInterrupt, LOW);

    publisher = this->create_publisher<vida_interfaces::msg::SensorDatas>("sensorData", 10);
    timer = this->create_wall_timer(chrono::nanoseconds((int)(1e9 / frequencyPublish)), bind(&Sensors::readSensors, this));
    RCLCPP_INFO(this->get_logger(), "sensors has been started");
}

Sensors::~Sensors()
{
    delete sensorSerial;
}

void Sensors::readSensors()
{
    digitalWrite(sensorInterrupt, HIGH);
    dataRecived = sensorSerial->read('\n');
    digitalWrite(sensorInterrupt, LOW);

    auto msg = vida_interfaces::msg::SensorDatas();

    sscanf(dataRecived.c_str(), "%ld %ld %ld %le", &msg.left_pulses, &msg.right_pulses, &msg.back_pulses, &msg.steering);

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