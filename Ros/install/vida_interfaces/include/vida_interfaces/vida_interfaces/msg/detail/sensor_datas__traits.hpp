// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vida_interfaces:msg/SensorDatas.idl
// generated code does not contain a copyright notice

#ifndef VIDA_INTERFACES__MSG__DETAIL__SENSOR_DATAS__TRAITS_HPP_
#define VIDA_INTERFACES__MSG__DETAIL__SENSOR_DATAS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vida_interfaces/msg/detail/sensor_datas__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vida_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SensorDatas & msg,
  std::ostream & out)
{
  out << "{";
  // member: left_pulses
  {
    out << "left_pulses: ";
    rosidl_generator_traits::value_to_yaml(msg.left_pulses, out);
    out << ", ";
  }

  // member: right_pulses
  {
    out << "right_pulses: ";
    rosidl_generator_traits::value_to_yaml(msg.right_pulses, out);
    out << ", ";
  }

  // member: back_pulses
  {
    out << "back_pulses: ";
    rosidl_generator_traits::value_to_yaml(msg.back_pulses, out);
    out << ", ";
  }

  // member: steering
  {
    out << "steering: ";
    rosidl_generator_traits::value_to_yaml(msg.steering, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SensorDatas & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: left_pulses
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_pulses: ";
    rosidl_generator_traits::value_to_yaml(msg.left_pulses, out);
    out << "\n";
  }

  // member: right_pulses
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_pulses: ";
    rosidl_generator_traits::value_to_yaml(msg.right_pulses, out);
    out << "\n";
  }

  // member: back_pulses
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "back_pulses: ";
    rosidl_generator_traits::value_to_yaml(msg.back_pulses, out);
    out << "\n";
  }

  // member: steering
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "steering: ";
    rosidl_generator_traits::value_to_yaml(msg.steering, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SensorDatas & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace vida_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use vida_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vida_interfaces::msg::SensorDatas & msg,
  std::ostream & out, size_t indentation = 0)
{
  vida_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vida_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const vida_interfaces::msg::SensorDatas & msg)
{
  return vida_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vida_interfaces::msg::SensorDatas>()
{
  return "vida_interfaces::msg::SensorDatas";
}

template<>
inline const char * name<vida_interfaces::msg::SensorDatas>()
{
  return "vida_interfaces/msg/SensorDatas";
}

template<>
struct has_fixed_size<vida_interfaces::msg::SensorDatas>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vida_interfaces::msg::SensorDatas>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vida_interfaces::msg::SensorDatas>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VIDA_INTERFACES__MSG__DETAIL__SENSOR_DATAS__TRAITS_HPP_
