// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vida_interfaces:msg/SensorDatas.idl
// generated code does not contain a copyright notice

#ifndef VIDA_INTERFACES__MSG__DETAIL__SENSOR_DATAS__STRUCT_H_
#define VIDA_INTERFACES__MSG__DETAIL__SENSOR_DATAS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/SensorDatas in the package vida_interfaces.
typedef struct vida_interfaces__msg__SensorDatas
{
  int64_t left_pulses;
  int64_t right_pulses;
  int64_t back_pulses;
  double steering;
} vida_interfaces__msg__SensorDatas;

// Struct for a sequence of vida_interfaces__msg__SensorDatas.
typedef struct vida_interfaces__msg__SensorDatas__Sequence
{
  vida_interfaces__msg__SensorDatas * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vida_interfaces__msg__SensorDatas__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VIDA_INTERFACES__MSG__DETAIL__SENSOR_DATAS__STRUCT_H_
