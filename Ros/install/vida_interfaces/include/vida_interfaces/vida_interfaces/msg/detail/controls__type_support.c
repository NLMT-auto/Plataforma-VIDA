// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vida_interfaces:msg/Controls.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vida_interfaces/msg/detail/controls__rosidl_typesupport_introspection_c.h"
#include "vida_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vida_interfaces/msg/detail/controls__functions.h"
#include "vida_interfaces/msg/detail/controls__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void vida_interfaces__msg__Controls__rosidl_typesupport_introspection_c__Controls_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vida_interfaces__msg__Controls__init(message_memory);
}

void vida_interfaces__msg__Controls__rosidl_typesupport_introspection_c__Controls_fini_function(void * message_memory)
{
  vida_interfaces__msg__Controls__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vida_interfaces__msg__Controls__rosidl_typesupport_introspection_c__Controls_message_member_array[2] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vida_interfaces__msg__Controls, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vida_interfaces__msg__Controls, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vida_interfaces__msg__Controls__rosidl_typesupport_introspection_c__Controls_message_members = {
  "vida_interfaces__msg",  // message namespace
  "Controls",  // message name
  2,  // number of fields
  sizeof(vida_interfaces__msg__Controls),
  vida_interfaces__msg__Controls__rosidl_typesupport_introspection_c__Controls_message_member_array,  // message members
  vida_interfaces__msg__Controls__rosidl_typesupport_introspection_c__Controls_init_function,  // function to initialize message memory (memory has to be allocated)
  vida_interfaces__msg__Controls__rosidl_typesupport_introspection_c__Controls_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vida_interfaces__msg__Controls__rosidl_typesupport_introspection_c__Controls_message_type_support_handle = {
  0,
  &vida_interfaces__msg__Controls__rosidl_typesupport_introspection_c__Controls_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vida_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vida_interfaces, msg, Controls)() {
  if (!vida_interfaces__msg__Controls__rosidl_typesupport_introspection_c__Controls_message_type_support_handle.typesupport_identifier) {
    vida_interfaces__msg__Controls__rosidl_typesupport_introspection_c__Controls_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vida_interfaces__msg__Controls__rosidl_typesupport_introspection_c__Controls_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
