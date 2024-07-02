// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vida_interfaces:msg/Controls.idl
// generated code does not contain a copyright notice

#ifndef VIDA_INTERFACES__MSG__DETAIL__CONTROLS__TRAITS_HPP_
#define VIDA_INTERFACES__MSG__DETAIL__CONTROLS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vida_interfaces/msg/detail/controls__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vida_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Controls & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Controls & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Controls & msg, bool use_flow_style = false)
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
  const vida_interfaces::msg::Controls & msg,
  std::ostream & out, size_t indentation = 0)
{
  vida_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vida_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const vida_interfaces::msg::Controls & msg)
{
  return vida_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vida_interfaces::msg::Controls>()
{
  return "vida_interfaces::msg::Controls";
}

template<>
inline const char * name<vida_interfaces::msg::Controls>()
{
  return "vida_interfaces/msg/Controls";
}

template<>
struct has_fixed_size<vida_interfaces::msg::Controls>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vida_interfaces::msg::Controls>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vida_interfaces::msg::Controls>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VIDA_INTERFACES__MSG__DETAIL__CONTROLS__TRAITS_HPP_
