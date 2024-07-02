// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vida_interfaces:msg/Controls.idl
// generated code does not contain a copyright notice

#ifndef VIDA_INTERFACES__MSG__DETAIL__CONTROLS__STRUCT_HPP_
#define VIDA_INTERFACES__MSG__DETAIL__CONTROLS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__vida_interfaces__msg__Controls __attribute__((deprecated))
#else
# define DEPRECATED__vida_interfaces__msg__Controls __declspec(deprecated)
#endif

namespace vida_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Controls_
{
  using Type = Controls_<ContainerAllocator>;

  explicit Controls_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0ll;
      this->y = 0ll;
    }
  }

  explicit Controls_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0ll;
      this->y = 0ll;
    }
  }

  // field types and members
  using _x_type =
    int64_t;
  _x_type x;
  using _y_type =
    int64_t;
  _y_type y;

  // setters for named parameter idiom
  Type & set__x(
    const int64_t & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const int64_t & _arg)
  {
    this->y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vida_interfaces::msg::Controls_<ContainerAllocator> *;
  using ConstRawPtr =
    const vida_interfaces::msg::Controls_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vida_interfaces::msg::Controls_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vida_interfaces::msg::Controls_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vida_interfaces::msg::Controls_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vida_interfaces::msg::Controls_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vida_interfaces::msg::Controls_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vida_interfaces::msg::Controls_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vida_interfaces::msg::Controls_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vida_interfaces::msg::Controls_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vida_interfaces__msg__Controls
    std::shared_ptr<vida_interfaces::msg::Controls_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vida_interfaces__msg__Controls
    std::shared_ptr<vida_interfaces::msg::Controls_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Controls_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    return true;
  }
  bool operator!=(const Controls_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Controls_

// alias to use template instance with default allocator
using Controls =
  vida_interfaces::msg::Controls_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vida_interfaces

#endif  // VIDA_INTERFACES__MSG__DETAIL__CONTROLS__STRUCT_HPP_
