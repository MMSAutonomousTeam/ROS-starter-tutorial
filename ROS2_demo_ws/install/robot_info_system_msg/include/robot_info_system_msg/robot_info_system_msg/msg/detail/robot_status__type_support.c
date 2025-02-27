// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from robot_info_system_msg:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "robot_info_system_msg/msg/detail/robot_status__rosidl_typesupport_introspection_c.h"
#include "robot_info_system_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "robot_info_system_msg/msg/detail/robot_status__functions.h"
#include "robot_info_system_msg/msg/detail/robot_status__struct.h"


// Include directives for member types
// Member `battery_level`
#include "std_msgs/msg/int32.h"
// Member `battery_level`
#include "std_msgs/msg/detail/int32__rosidl_typesupport_introspection_c.h"
// Member `temperature`
#include "std_msgs/msg/u_int8.h"
// Member `temperature`
#include "std_msgs/msg/detail/u_int8__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robot_info_system_msg__msg__RobotStatus__rosidl_typesupport_introspection_c__RobotStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robot_info_system_msg__msg__RobotStatus__init(message_memory);
}

void robot_info_system_msg__msg__RobotStatus__rosidl_typesupport_introspection_c__RobotStatus_fini_function(void * message_memory)
{
  robot_info_system_msg__msg__RobotStatus__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember robot_info_system_msg__msg__RobotStatus__rosidl_typesupport_introspection_c__RobotStatus_message_member_array[2] = {
  {
    "battery_level",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_info_system_msg__msg__RobotStatus, battery_level),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "temperature",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_info_system_msg__msg__RobotStatus, temperature),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robot_info_system_msg__msg__RobotStatus__rosidl_typesupport_introspection_c__RobotStatus_message_members = {
  "robot_info_system_msg__msg",  // message namespace
  "RobotStatus",  // message name
  2,  // number of fields
  sizeof(robot_info_system_msg__msg__RobotStatus),
  robot_info_system_msg__msg__RobotStatus__rosidl_typesupport_introspection_c__RobotStatus_message_member_array,  // message members
  robot_info_system_msg__msg__RobotStatus__rosidl_typesupport_introspection_c__RobotStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  robot_info_system_msg__msg__RobotStatus__rosidl_typesupport_introspection_c__RobotStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robot_info_system_msg__msg__RobotStatus__rosidl_typesupport_introspection_c__RobotStatus_message_type_support_handle = {
  0,
  &robot_info_system_msg__msg__RobotStatus__rosidl_typesupport_introspection_c__RobotStatus_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robot_info_system_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_info_system_msg, msg, RobotStatus)() {
  robot_info_system_msg__msg__RobotStatus__rosidl_typesupport_introspection_c__RobotStatus_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Int32)();
  robot_info_system_msg__msg__RobotStatus__rosidl_typesupport_introspection_c__RobotStatus_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, UInt8)();
  if (!robot_info_system_msg__msg__RobotStatus__rosidl_typesupport_introspection_c__RobotStatus_message_type_support_handle.typesupport_identifier) {
    robot_info_system_msg__msg__RobotStatus__rosidl_typesupport_introspection_c__RobotStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robot_info_system_msg__msg__RobotStatus__rosidl_typesupport_introspection_c__RobotStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
