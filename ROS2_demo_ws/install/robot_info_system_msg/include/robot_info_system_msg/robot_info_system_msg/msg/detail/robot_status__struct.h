// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_info_system_msg:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INFO_SYSTEM_MSG__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_
#define ROBOT_INFO_SYSTEM_MSG__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'battery_level'
#include "std_msgs/msg/detail/int32__struct.h"
// Member 'temperature'
#include "std_msgs/msg/detail/u_int8__struct.h"

/// Struct defined in msg/RobotStatus in the package robot_info_system_msg.
typedef struct robot_info_system_msg__msg__RobotStatus
{
  std_msgs__msg__Int32 battery_level;
  std_msgs__msg__UInt8 temperature;
} robot_info_system_msg__msg__RobotStatus;

// Struct for a sequence of robot_info_system_msg__msg__RobotStatus.
typedef struct robot_info_system_msg__msg__RobotStatus__Sequence
{
  robot_info_system_msg__msg__RobotStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_info_system_msg__msg__RobotStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INFO_SYSTEM_MSG__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_
