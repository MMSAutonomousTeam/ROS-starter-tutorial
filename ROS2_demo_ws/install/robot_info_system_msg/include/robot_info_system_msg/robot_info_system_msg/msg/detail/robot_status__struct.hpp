// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_info_system_msg:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INFO_SYSTEM_MSG__MSG__DETAIL__ROBOT_STATUS__STRUCT_HPP_
#define ROBOT_INFO_SYSTEM_MSG__MSG__DETAIL__ROBOT_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'battery_level'
#include "std_msgs/msg/detail/int32__struct.hpp"
// Member 'temperature'
#include "std_msgs/msg/detail/u_int8__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robot_info_system_msg__msg__RobotStatus __attribute__((deprecated))
#else
# define DEPRECATED__robot_info_system_msg__msg__RobotStatus __declspec(deprecated)
#endif

namespace robot_info_system_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotStatus_
{
  using Type = RobotStatus_<ContainerAllocator>;

  explicit RobotStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : battery_level(_init),
    temperature(_init)
  {
    (void)_init;
  }

  explicit RobotStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : battery_level(_alloc, _init),
    temperature(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _battery_level_type =
    std_msgs::msg::Int32_<ContainerAllocator>;
  _battery_level_type battery_level;
  using _temperature_type =
    std_msgs::msg::UInt8_<ContainerAllocator>;
  _temperature_type temperature;

  // setters for named parameter idiom
  Type & set__battery_level(
    const std_msgs::msg::Int32_<ContainerAllocator> & _arg)
  {
    this->battery_level = _arg;
    return *this;
  }
  Type & set__temperature(
    const std_msgs::msg::UInt8_<ContainerAllocator> & _arg)
  {
    this->temperature = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_info_system_msg::msg::RobotStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_info_system_msg::msg::RobotStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_info_system_msg::msg::RobotStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_info_system_msg::msg::RobotStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_info_system_msg::msg::RobotStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_info_system_msg::msg::RobotStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_info_system_msg::msg::RobotStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_info_system_msg::msg::RobotStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_info_system_msg::msg::RobotStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_info_system_msg::msg::RobotStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_info_system_msg__msg__RobotStatus
    std::shared_ptr<robot_info_system_msg::msg::RobotStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_info_system_msg__msg__RobotStatus
    std::shared_ptr<robot_info_system_msg::msg::RobotStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotStatus_ & other) const
  {
    if (this->battery_level != other.battery_level) {
      return false;
    }
    if (this->temperature != other.temperature) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotStatus_

// alias to use template instance with default allocator
using RobotStatus =
  robot_info_system_msg::msg::RobotStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robot_info_system_msg

#endif  // ROBOT_INFO_SYSTEM_MSG__MSG__DETAIL__ROBOT_STATUS__STRUCT_HPP_
