// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from vida_interfaces:msg/SensorDatas.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "vida_interfaces/msg/detail/sensor_datas__struct.h"
#include "vida_interfaces/msg/detail/sensor_datas__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool vida_interfaces__msg__sensor_datas__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[46];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("vida_interfaces.msg._sensor_datas.SensorDatas", full_classname_dest, 45) == 0);
  }
  vida_interfaces__msg__SensorDatas * ros_message = _ros_message;
  {  // left_pulses
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_pulses");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->left_pulses = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // right_pulses
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_pulses");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->right_pulses = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // back_pulses
    PyObject * field = PyObject_GetAttrString(_pymsg, "back_pulses");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->back_pulses = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // steering
    PyObject * field = PyObject_GetAttrString(_pymsg, "steering");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->steering = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * vida_interfaces__msg__sensor_datas__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SensorDatas */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("vida_interfaces.msg._sensor_datas");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SensorDatas");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  vida_interfaces__msg__SensorDatas * ros_message = (vida_interfaces__msg__SensorDatas *)raw_ros_message;
  {  // left_pulses
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->left_pulses);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_pulses", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_pulses
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->right_pulses);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_pulses", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // back_pulses
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->back_pulses);
    {
      int rc = PyObject_SetAttrString(_pymessage, "back_pulses", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // steering
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->steering);
    {
      int rc = PyObject_SetAttrString(_pymessage, "steering", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
