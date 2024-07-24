// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vida_interfaces:msg/SensorDatas.idl
// generated code does not contain a copyright notice

#ifndef VIDA_INTERFACES__MSG__DETAIL__SENSOR_DATAS__STRUCT_HPP_
#define VIDA_INTERFACES__MSG__DETAIL__SENSOR_DATAS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__vida_interfaces__msg__SensorDatas __attribute__((deprecated))
#else
# define DEPRECATED__vida_interfaces__msg__SensorDatas __declspec(deprecated)
#endif

namespace vida_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SensorDatas_
{
  using Type = SensorDatas_<ContainerAllocator>;

  explicit SensorDatas_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left_pulses = 0ll;
      this->right_pulses = 0ll;
      this->back_pulses = 0ll;
      this->steering = 0.0;
    }
  }

  explicit SensorDatas_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left_pulses = 0ll;
      this->right_pulses = 0ll;
      this->back_pulses = 0ll;
      this->steering = 0.0;
    }
  }

  // field types and members
  using _left_pulses_type =
    int64_t;
  _left_pulses_type left_pulses;
  using _right_pulses_type =
    int64_t;
  _right_pulses_type right_pulses;
  using _back_pulses_type =
    int64_t;
  _back_pulses_type back_pulses;
  using _steering_type =
    double;
  _steering_type steering;

  // setters for named parameter idiom
  Type & set__left_pulses(
    const int64_t & _arg)
  {
    this->left_pulses = _arg;
    return *this;
  }
  Type & set__right_pulses(
    const int64_t & _arg)
  {
    this->right_pulses = _arg;
    return *this;
  }
  Type & set__back_pulses(
    const int64_t & _arg)
  {
    this->back_pulses = _arg;
    return *this;
  }
  Type & set__steering(
    const double & _arg)
  {
    this->steering = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vida_interfaces::msg::SensorDatas_<ContainerAllocator> *;
  using ConstRawPtr =
    const vida_interfaces::msg::SensorDatas_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vida_interfaces::msg::SensorDatas_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vida_interfaces::msg::SensorDatas_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vida_interfaces::msg::SensorDatas_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vida_interfaces::msg::SensorDatas_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vida_interfaces::msg::SensorDatas_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vida_interfaces::msg::SensorDatas_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vida_interfaces::msg::SensorDatas_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vida_interfaces::msg::SensorDatas_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vida_interfaces__msg__SensorDatas
    std::shared_ptr<vida_interfaces::msg::SensorDatas_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vida_interfaces__msg__SensorDatas
    std::shared_ptr<vida_interfaces::msg::SensorDatas_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SensorDatas_ & other) const
  {
    if (this->left_pulses != other.left_pulses) {
      return false;
    }
    if (this->right_pulses != other.right_pulses) {
      return false;
    }
    if (this->back_pulses != other.back_pulses) {
      return false;
    }
    if (this->steering != other.steering) {
      return false;
    }
    return true;
  }
  bool operator!=(const SensorDatas_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SensorDatas_

// alias to use template instance with default allocator
using SensorDatas =
  vida_interfaces::msg::SensorDatas_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vida_interfaces

#endif  // VIDA_INTERFACES__MSG__DETAIL__SENSOR_DATAS__STRUCT_HPP_
