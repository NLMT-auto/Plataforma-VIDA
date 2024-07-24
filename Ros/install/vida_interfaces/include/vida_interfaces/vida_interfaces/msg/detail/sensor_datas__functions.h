// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from vida_interfaces:msg/SensorDatas.idl
// generated code does not contain a copyright notice

#ifndef VIDA_INTERFACES__MSG__DETAIL__SENSOR_DATAS__FUNCTIONS_H_
#define VIDA_INTERFACES__MSG__DETAIL__SENSOR_DATAS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "vida_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "vida_interfaces/msg/detail/sensor_datas__struct.h"

/// Initialize msg/SensorDatas message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vida_interfaces__msg__SensorDatas
 * )) before or use
 * vida_interfaces__msg__SensorDatas__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vida_interfaces
bool
vida_interfaces__msg__SensorDatas__init(vida_interfaces__msg__SensorDatas * msg);

/// Finalize msg/SensorDatas message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vida_interfaces
void
vida_interfaces__msg__SensorDatas__fini(vida_interfaces__msg__SensorDatas * msg);

/// Create msg/SensorDatas message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vida_interfaces__msg__SensorDatas__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vida_interfaces
vida_interfaces__msg__SensorDatas *
vida_interfaces__msg__SensorDatas__create();

/// Destroy msg/SensorDatas message.
/**
 * It calls
 * vida_interfaces__msg__SensorDatas__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vida_interfaces
void
vida_interfaces__msg__SensorDatas__destroy(vida_interfaces__msg__SensorDatas * msg);

/// Check for msg/SensorDatas message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vida_interfaces
bool
vida_interfaces__msg__SensorDatas__are_equal(const vida_interfaces__msg__SensorDatas * lhs, const vida_interfaces__msg__SensorDatas * rhs);

/// Copy a msg/SensorDatas message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_vida_interfaces
bool
vida_interfaces__msg__SensorDatas__copy(
  const vida_interfaces__msg__SensorDatas * input,
  vida_interfaces__msg__SensorDatas * output);

/// Initialize array of msg/SensorDatas messages.
/**
 * It allocates the memory for the number of elements and calls
 * vida_interfaces__msg__SensorDatas__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vida_interfaces
bool
vida_interfaces__msg__SensorDatas__Sequence__init(vida_interfaces__msg__SensorDatas__Sequence * array, size_t size);

/// Finalize array of msg/SensorDatas messages.
/**
 * It calls
 * vida_interfaces__msg__SensorDatas__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vida_interfaces
void
vida_interfaces__msg__SensorDatas__Sequence__fini(vida_interfaces__msg__SensorDatas__Sequence * array);

/// Create array of msg/SensorDatas messages.
/**
 * It allocates the memory for the array and calls
 * vida_interfaces__msg__SensorDatas__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vida_interfaces
vida_interfaces__msg__SensorDatas__Sequence *
vida_interfaces__msg__SensorDatas__Sequence__create(size_t size);

/// Destroy array of msg/SensorDatas messages.
/**
 * It calls
 * vida_interfaces__msg__SensorDatas__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vida_interfaces
void
vida_interfaces__msg__SensorDatas__Sequence__destroy(vida_interfaces__msg__SensorDatas__Sequence * array);

/// Check for msg/SensorDatas message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vida_interfaces
bool
vida_interfaces__msg__SensorDatas__Sequence__are_equal(const vida_interfaces__msg__SensorDatas__Sequence * lhs, const vida_interfaces__msg__SensorDatas__Sequence * rhs);

/// Copy an array of msg/SensorDatas messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_vida_interfaces
bool
vida_interfaces__msg__SensorDatas__Sequence__copy(
  const vida_interfaces__msg__SensorDatas__Sequence * input,
  vida_interfaces__msg__SensorDatas__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // VIDA_INTERFACES__MSG__DETAIL__SENSOR_DATAS__FUNCTIONS_H_
