// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vida_interfaces:msg/Controls.idl
// generated code does not contain a copyright notice

#ifndef VIDA_INTERFACES__MSG__DETAIL__CONTROLS__BUILDER_HPP_
#define VIDA_INTERFACES__MSG__DETAIL__CONTROLS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vida_interfaces/msg/detail/controls__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vida_interfaces
{

namespace msg
{

namespace builder
{

class Init_Controls_y
{
public:
  explicit Init_Controls_y(::vida_interfaces::msg::Controls & msg)
  : msg_(msg)
  {}
  ::vida_interfaces::msg::Controls y(::vida_interfaces::msg::Controls::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vida_interfaces::msg::Controls msg_;
};

class Init_Controls_x
{
public:
  Init_Controls_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Controls_y x(::vida_interfaces::msg::Controls::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Controls_y(msg_);
  }

private:
  ::vida_interfaces::msg::Controls msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vida_interfaces::msg::Controls>()
{
  return vida_interfaces::msg::builder::Init_Controls_x();
}

}  // namespace vida_interfaces

#endif  // VIDA_INTERFACES__MSG__DETAIL__CONTROLS__BUILDER_HPP_
