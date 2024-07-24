#include "Record.h"

Record::Record(string name) : Node(name)
{
    subscriber = this->create_subscription<vida_interfaces::msg::SensorData>("sensorData", 10, bind(&Control::sensorDataCallBack, this, _1));
    RCLCPP_INFO(this->get_logger(), "record has been started");
}

Record::~Record()
{
    saveSensors();
}

void Control::callbackControls(const vida_interfaces::msg::Controls::SharedPtr msg)
{
    BufferDataRecived << this->get_clock() << ";"
                      << msg->leftPulses << ";"
                      << msg->rigthPulses << ";"
                      << msg->backPulses << ";"
                      << msg->steering << endl;

    ++count;

    if ((count % 100) == 0)
    {
        saveSensors();
        BufferDataRecived.str("");
    }
}

void Record::saveSensors()
{
    outputSensors.open("../EncoderDataRecorder.txt", ios_base::out | ios_base::app);
    outputSensors << BufferDataRecived.str();
    outputSensors.close();
}

int main(int argc, char **argv)
{
    init(argc, argv);                          // inicializado o ROS
    auto node = make_shared<Record>("record"); // criação do nó usando ponteiro compartilhado e o nomeando
    spin(node);                                // gira o nó (o mantem vivo até ctrl + c)
    shutdown();                                // desliga o nó
    return 0;
}