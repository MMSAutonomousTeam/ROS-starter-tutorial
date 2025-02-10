// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_info_system_msg:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INFO_SYSTEM_MSG__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_
#define ROBOT_INFO_SYSTEM_MSG__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_info_system_msg/msg/detail/robot_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'battery_level'
#include "std_msgs/msg/detail/int32__traits.hpp"
// Member 'temperature'
#include "std_msgs/msg/detail/u_int8__traits.hpp"

namespace robot_info_system_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: battery_level
  {
    out << "battery_level: ";
    to_flow_style_yaml(msg.battery_level, out);
    out << ", ";
  }

  // member: temperature
  {
    out << "temperature: ";
    to_flow_style_yaml(msg.temperature, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: battery_level
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery_level:\n";
    to_block_style_yaml(msg.battery_level, out, indentation + 2);
  }

  // member: temperature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temperature:\n";
    to_block_style_yaml(msg.temperature, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace robot_info_system_msg

namespace rosidl_generator_traits
{

[[deprecated("use robot_info_system_msg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_info_system_msg::msg::RobotStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_info_system_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_info_system_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const robot_info_system_msg::msg::RobotStatus & msg)
{
  return robot_info_system_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robot_info_system_msg::msg::RobotStatus>()
{
  return "robot_info_system_msg::msg::RobotStatus";
}

template<>
inline const char * name<robot_info_system_msg::msg::RobotStatus>()
{
  return "robot_info_system_msg/msg/RobotStatus";
}

template<>
struct has_fixed_size<robot_info_system_msg::msg::RobotStatus>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Int32>::value && has_fixed_size<std_msgs::msg::UInt8>::value> {};

template<>
struct has_bounded_size<robot_info_system_msg::msg::RobotStatus>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Int32>::value && has_bounded_size<std_msgs::msg::UInt8>::value> {};

template<>
struct is_message<robot_info_system_msg::msg::RobotStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_INFO_SYSTEM_MSG__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_
