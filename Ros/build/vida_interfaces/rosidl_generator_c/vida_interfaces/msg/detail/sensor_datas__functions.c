// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vida_interfaces:msg/SensorDatas.idl
// generated code does not contain a copyright notice
#include "vida_interfaces/msg/detail/sensor_datas__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
vida_interfaces__msg__SensorDatas__init(vida_interfaces__msg__SensorDatas * msg)
{
  if (!msg) {
    return false;
  }
  // left_pulses
  // right_pulses
  // back_pulses
  // steering
  return true;
}

void
vida_interfaces__msg__SensorDatas__fini(vida_interfaces__msg__SensorDatas * msg)
{
  if (!msg) {
    return;
  }
  // left_pulses
  // right_pulses
  // back_pulses
  // steering
}

bool
vida_interfaces__msg__SensorDatas__are_equal(const vida_interfaces__msg__SensorDatas * lhs, const vida_interfaces__msg__SensorDatas * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // left_pulses
  if (lhs->left_pulses != rhs->left_pulses) {
    return false;
  }
  // right_pulses
  if (lhs->right_pulses != rhs->right_pulses) {
    return false;
  }
  // back_pulses
  if (lhs->back_pulses != rhs->back_pulses) {
    return false;
  }
  // steering
  if (lhs->steering != rhs->steering) {
    return false;
  }
  return true;
}

bool
vida_interfaces__msg__SensorDatas__copy(
  const vida_interfaces__msg__SensorDatas * input,
  vida_interfaces__msg__SensorDatas * output)
{
  if (!input || !output) {
    return false;
  }
  // left_pulses
  output->left_pulses = input->left_pulses;
  // right_pulses
  output->right_pulses = input->right_pulses;
  // back_pulses
  output->back_pulses = input->back_pulses;
  // steering
  output->steering = input->steering;
  return true;
}

vida_interfaces__msg__SensorDatas *
vida_interfaces__msg__SensorDatas__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vida_interfaces__msg__SensorDatas * msg = (vida_interfaces__msg__SensorDatas *)allocator.allocate(sizeof(vida_interfaces__msg__SensorDatas), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vida_interfaces__msg__SensorDatas));
  bool success = vida_interfaces__msg__SensorDatas__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vida_interfaces__msg__SensorDatas__destroy(vida_interfaces__msg__SensorDatas * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vida_interfaces__msg__SensorDatas__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vida_interfaces__msg__SensorDatas__Sequence__init(vida_interfaces__msg__SensorDatas__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vida_interfaces__msg__SensorDatas * data = NULL;

  if (size) {
    data = (vida_interfaces__msg__SensorDatas *)allocator.zero_allocate(size, sizeof(vida_interfaces__msg__SensorDatas), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vida_interfaces__msg__SensorDatas__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vida_interfaces__msg__SensorDatas__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
vida_interfaces__msg__SensorDatas__Sequence__fini(vida_interfaces__msg__SensorDatas__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      vida_interfaces__msg__SensorDatas__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

vida_interfaces__msg__SensorDatas__Sequence *
vida_interfaces__msg__SensorDatas__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vida_interfaces__msg__SensorDatas__Sequence * array = (vida_interfaces__msg__SensorDatas__Sequence *)allocator.allocate(sizeof(vida_interfaces__msg__SensorDatas__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vida_interfaces__msg__SensorDatas__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vida_interfaces__msg__SensorDatas__Sequence__destroy(vida_interfaces__msg__SensorDatas__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vida_interfaces__msg__SensorDatas__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vida_interfaces__msg__SensorDatas__Sequence__are_equal(const vida_interfaces__msg__SensorDatas__Sequence * lhs, const vida_interfaces__msg__SensorDatas__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vida_interfaces__msg__SensorDatas__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vida_interfaces__msg__SensorDatas__Sequence__copy(
  const vida_interfaces__msg__SensorDatas__Sequence * input,
  vida_interfaces__msg__SensorDatas__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vida_interfaces__msg__SensorDatas);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vida_interfaces__msg__SensorDatas * data =
      (vida_interfaces__msg__SensorDatas *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vida_interfaces__msg__SensorDatas__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vida_interfaces__msg__SensorDatas__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vida_interfaces__msg__SensorDatas__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
