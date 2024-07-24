#include "Record.h"

Record::Record(string name) : Node(name)
{
    subscriber = this->create_subscription<vida_interfaces::msg::SensorDatas>("sensorData", 10, bind(&Record::sensorDataCallBack, this, _1));
    RCLCPP_INFO(this->get_logger(), "record has been started");
}

Record::~Record()
{
    saveSensors();
}

void Record::sensorDataCallBack(const vida_interfaces::msg::SensorDatas::SharedPtr msg)
{

    auto timestamp = this->get_clock()->now();
    auto time_t_now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    stringstream ss;
    ss << std::put_time(std::localtime(&time_t_now), "%Y-%m-%d %H:%M:%S");

    BufferDataRecived << ss.str()<< ";"
                      << msg->left_pulses << ";"
                      << msg->right_pulses << ";"
                      << msg->back_pulses << ";"
                      << msg->steering << endl;

    ++count;

    if ((count % 10) == 0)
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