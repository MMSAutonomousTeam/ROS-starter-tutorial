// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_info_system_msg:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INFO_SYSTEM_MSG__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_
#define ROBOT_INFO_SYSTEM_MSG__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_info_system_msg/msg/detail/robot_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_info_system_msg
{

namespace msg
{

namespace builder
{

class Init_RobotStatus_temperature
{
public:
  explicit Init_RobotStatus_temperature(::robot_info_system_msg::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  ::robot_info_system_msg::msg::RobotStatus temperature(::robot_info_system_msg::msg::RobotStatus::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_info_system_msg::msg::RobotStatus msg_;
};

class Init_RobotStatus_battery_level
{
public:
  Init_RobotStatus_battery_level()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotStatus_temperature battery_level(::robot_info_system_msg::msg::RobotStatus::_battery_level_type arg)
  {
    msg_.battery_level = std::move(arg);
    return Init_RobotStatus_temperature(msg_);
  }

private:
  ::robot_info_system_msg::msg::RobotStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_info_system_msg::msg::RobotStatus>()
{
  return robot_info_system_msg::msg::builder::Init_RobotStatus_battery_level();
}

}  // namespace robot_info_system_msg

#endif  // ROBOT_INFO_SYSTEM_MSG__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_
