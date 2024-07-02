// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vida_interfaces:msg/Controls.idl
// generated code does not contain a copyright notice

#ifndef VIDA_INTERFACES__MSG__DETAIL__CONTROLS__STRUCT_H_
#define VIDA_INTERFACES__MSG__DETAIL__CONTROLS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Controls in the package vida_interfaces.
typedef struct vida_interfaces__msg__Controls
{
  int64_t x;
  int64_t y;
} vida_interfaces__msg__Controls;

// Struct for a sequence of vida_interfaces__msg__Controls.
typedef struct vida_interfaces__msg__Controls__Sequence
{
  vida_interfaces__msg__Controls * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vida_interfaces__msg__Controls__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VIDA_INTERFACES__MSG__DETAIL__CONTROLS__STRUCT_H_
