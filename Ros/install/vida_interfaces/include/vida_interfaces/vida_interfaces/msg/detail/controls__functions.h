// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from vida_interfaces:msg/Controls.idl
// generated code does not contain a copyright notice

#ifndef VIDA_INTERFACES__MSG__DETAIL__CONTROLS__FUNCTIONS_H_
#define VIDA_INTERFACES__MSG__DETAIL__CONTROLS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "vida_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "vida_interfaces/msg/detail/controls__struct.h"

/// Initialize msg/Controls message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vida_interfaces__msg__Controls
 * )) before or use
 * vida_interfaces__msg__Controls__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vida_interfaces
bool
vida_interfaces__msg__Controls__init(vida_interfaces__msg__Controls * msg);

/// Finalize msg/Controls message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vida_interfaces
void
vida_interfaces__msg__Controls__fini(vida_interfaces__msg__Controls * msg);

/// Create msg/Controls message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vida_interfaces__msg__Controls__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vida_interfaces
vida_interfaces__msg__Controls *
vida_interfaces__msg__Controls__create();

/// Destroy msg/Controls message.
/**
 * It calls
 * vida_interfaces__msg__Controls__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vida_interfaces
void
vida_interfaces__msg__Controls__destroy(vida_interfaces__msg__Controls * msg);

/// Check for msg/Controls message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vida_interfaces
bool
vida_interfaces__msg__Controls__are_equal(const vida_interfaces__msg__Controls * lhs, const vida_interfaces__msg__Controls * rhs);

/// Copy a msg/Controls message.
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
vida_interfaces__msg__Controls__copy(
  const vida_interfaces__msg__Controls * input,
  vida_interfaces__msg__Controls * output);

/// Initialize array of msg/Controls messages.
/**
 * It allocates the memory for the number of elements and calls
 * vida_interfaces__msg__Controls__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vida_interfaces
bool
vida_interfaces__msg__Controls__Sequence__init(vida_interfaces__msg__Controls__Sequence * array, size_t size);

/// Finalize array of msg/Controls messages.
/**
 * It calls
 * vida_interfaces__msg__Controls__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vida_interfaces
void
vida_interfaces__msg__Controls__Sequence__fini(vida_interfaces__msg__Controls__Sequence * array);

/// Create array of msg/Controls messages.
/**
 * It allocates the memory for the array and calls
 * vida_interfaces__msg__Controls__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vida_interfaces
vida_interfaces__msg__Controls__Sequence *
vida_interfaces__msg__Controls__Sequence__create(size_t size);

/// Destroy array of msg/Controls messages.
/**
 * It calls
 * vida_interfaces__msg__Controls__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vida_interfaces
void
vida_interfaces__msg__Controls__Sequence__destroy(vida_interfaces__msg__Controls__Sequence * array);

/// Check for msg/Controls message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vida_interfaces
bool
vida_interfaces__msg__Controls__Sequence__are_equal(const vida_interfaces__msg__Controls__Sequence * lhs, const vida_interfaces__msg__Controls__Sequence * rhs);

/// Copy an array of msg/Controls messages.
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
vida_interfaces__msg__Controls__Sequence__copy(
  const vida_interfaces__msg__Controls__Sequence * input,
  vida_interfaces__msg__Controls__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // VIDA_INTERFACES__MSG__DETAIL__CONTROLS__FUNCTIONS_H_
