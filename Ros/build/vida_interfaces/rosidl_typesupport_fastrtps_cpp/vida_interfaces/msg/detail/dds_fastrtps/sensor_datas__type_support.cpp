// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from vida_interfaces:msg/SensorDatas.idl
// generated code does not contain a copyright notice
#include "vida_interfaces/msg/detail/sensor_datas__rosidl_typesupport_fastrtps_cpp.hpp"
#include "vida_interfaces/msg/detail/sensor_datas__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace vida_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vida_interfaces
cdr_serialize(
  const vida_interfaces::msg::SensorDatas & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: left_pulses
  cdr << ros_message.left_pulses;
  // Member: right_pulses
  cdr << ros_message.right_pulses;
  // Member: back_pulses
  cdr << ros_message.back_pulses;
  // Member: steering
  cdr << ros_message.steering;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vida_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  vida_interfaces::msg::SensorDatas & ros_message)
{
  // Member: left_pulses
  cdr >> ros_message.left_pulses;

  // Member: right_pulses
  cdr >> ros_message.right_pulses;

  // Member: back_pulses
  cdr >> ros_message.back_pulses;

  // Member: steering
  cdr >> ros_message.steering;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vida_interfaces
get_serialized_size(
  const vida_interfaces::msg::SensorDatas & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: left_pulses
  {
    size_t item_size = sizeof(ros_message.left_pulses);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: right_pulses
  {
    size_t item_size = sizeof(ros_message.right_pulses);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: back_pulses
  {
    size_t item_size = sizeof(ros_message.back_pulses);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: steering
  {
    size_t item_size = sizeof(ros_message.steering);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vida_interfaces
max_serialized_size_SensorDatas(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: left_pulses
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: right_pulses
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: back_pulses
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: steering
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = vida_interfaces::msg::SensorDatas;
    is_plain =
      (
      offsetof(DataType, steering) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _SensorDatas__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const vida_interfaces::msg::SensorDatas *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SensorDatas__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<vida_interfaces::msg::SensorDatas *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SensorDatas__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const vida_interfaces::msg::SensorDatas *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SensorDatas__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SensorDatas(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SensorDatas__callbacks = {
  "vida_interfaces::msg",
  "SensorDatas",
  _SensorDatas__cdr_serialize,
  _SensorDatas__cdr_deserialize,
  _SensorDatas__get_serialized_size,
  _SensorDatas__max_serialized_size
};

static rosidl_message_type_support_t _SensorDatas__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SensorDatas__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace vida_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_vida_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<vida_interfaces::msg::SensorDatas>()
{
  return &vida_interfaces::msg::typesupport_fastrtps_cpp::_SensorDatas__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vida_interfaces, msg, SensorDatas)() {
  return &vida_interfaces::msg::typesupport_fastrtps_cpp::_SensorDatas__handle;
}

#ifdef __cplusplus
}
#endif
