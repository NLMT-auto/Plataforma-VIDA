// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vida_interfaces:msg/SensorDatas.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vida_interfaces/msg/detail/sensor_datas__rosidl_typesupport_introspection_c.h"
#include "vida_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vida_interfaces/msg/detail/sensor_datas__functions.h"
#include "vida_interfaces/msg/detail/sensor_datas__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void vida_interfaces__msg__SensorDatas__rosidl_typesupport_introspection_c__SensorDatas_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vida_interfaces__msg__SensorDatas__init(message_memory);
}

void vida_interfaces__msg__SensorDatas__rosidl_typesupport_introspection_c__SensorDatas_fini_function(void * message_memory)
{
  vida_interfaces__msg__SensorDatas__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vida_interfaces__msg__SensorDatas__rosidl_typesupport_introspection_c__SensorDatas_message_member_array[4] = {
  {
    "left_pulses",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vida_interfaces__msg__SensorDatas, left_pulses),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "right_pulses",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vida_interfaces__msg__SensorDatas, right_pulses),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "back_pulses",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vida_interfaces__msg__SensorDatas, back_pulses),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "steering",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vida_interfaces__msg__SensorDatas, steering),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vida_interfaces__msg__SensorDatas__rosidl_typesupport_introspection_c__SensorDatas_message_members = {
  "vida_interfaces__msg",  // message namespace
  "SensorDatas",  // message name
  4,  // number of fields
  sizeof(vida_interfaces__msg__SensorDatas),
  vida_interfaces__msg__SensorDatas__rosidl_typesupport_introspection_c__SensorDatas_message_member_array,  // message members
  vida_interfaces__msg__SensorDatas__rosidl_typesupport_introspection_c__SensorDatas_init_function,  // function to initialize message memory (memory has to be allocated)
  vida_interfaces__msg__SensorDatas__rosidl_typesupport_introspection_c__SensorDatas_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vida_interfaces__msg__SensorDatas__rosidl_typesupport_introspection_c__SensorDatas_message_type_support_handle = {
  0,
  &vida_interfaces__msg__SensorDatas__rosidl_typesupport_introspection_c__SensorDatas_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vida_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vida_interfaces, msg, SensorDatas)() {
  if (!vida_interfaces__msg__SensorDatas__rosidl_typesupport_introspection_c__SensorDatas_message_type_support_handle.typesupport_identifier) {
    vida_interfaces__msg__SensorDatas__rosidl_typesupport_introspection_c__SensorDatas_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vida_interfaces__msg__SensorDatas__rosidl_typesupport_introspection_c__SensorDatas_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
