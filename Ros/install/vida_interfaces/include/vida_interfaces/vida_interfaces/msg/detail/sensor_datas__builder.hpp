// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vida_interfaces:msg/SensorDatas.idl
// generated code does not contain a copyright notice

#ifndef VIDA_INTERFACES__MSG__DETAIL__SENSOR_DATAS__BUILDER_HPP_
#define VIDA_INTERFACES__MSG__DETAIL__SENSOR_DATAS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vida_interfaces/msg/detail/sensor_datas__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vida_interfaces
{

namespace msg
{

namespace builder
{

class Init_SensorDatas_steering
{
public:
  explicit Init_SensorDatas_steering(::vida_interfaces::msg::SensorDatas & msg)
  : msg_(msg)
  {}
  ::vida_interfaces::msg::SensorDatas steering(::vida_interfaces::msg::SensorDatas::_steering_type arg)
  {
    msg_.steering = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vida_interfaces::msg::SensorDatas msg_;
};

class Init_SensorDatas_back_pulses
{
public:
  explicit Init_SensorDatas_back_pulses(::vida_interfaces::msg::SensorDatas & msg)
  : msg_(msg)
  {}
  Init_SensorDatas_steering back_pulses(::vida_interfaces::msg::SensorDatas::_back_pulses_type arg)
  {
    msg_.back_pulses = std::move(arg);
    return Init_SensorDatas_steering(msg_);
  }

private:
  ::vida_interfaces::msg::SensorDatas msg_;
};

class Init_SensorDatas_right_pulses
{
public:
  explicit Init_SensorDatas_right_pulses(::vida_interfaces::msg::SensorDatas & msg)
  : msg_(msg)
  {}
  Init_SensorDatas_back_pulses right_pulses(::vida_interfaces::msg::SensorDatas::_right_pulses_type arg)
  {
    msg_.right_pulses = std::move(arg);
    return Init_SensorDatas_back_pulses(msg_);
  }

private:
  ::vida_interfaces::msg::SensorDatas msg_;
};

class Init_SensorDatas_left_pulses
{
public:
  Init_SensorDatas_left_pulses()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SensorDatas_right_pulses left_pulses(::vida_interfaces::msg::SensorDatas::_left_pulses_type arg)
  {
    msg_.left_pulses = std::move(arg);
    return Init_SensorDatas_right_pulses(msg_);
  }

private:
  ::vida_interfaces::msg::SensorDatas msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vida_interfaces::msg::SensorDatas>()
{
  return vida_interfaces::msg::builder::Init_SensorDatas_left_pulses();
}

}  // namespace vida_interfaces

#endif  // VIDA_INTERFACES__MSG__DETAIL__SENSOR_DATAS__BUILDER_HPP_
