// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from robot_info_system_msg:msg/RobotStatus.idl
// generated code does not contain a copyright notice
#include "robot_info_system_msg/msg/detail/robot_status__rosidl_typesupport_fastrtps_cpp.hpp"
#include "robot_info_system_msg/msg/detail/robot_status__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Int32 &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Int32 &);
size_t get_serialized_size(
  const std_msgs::msg::Int32 &,
  size_t current_alignment);
size_t
max_serialized_size_Int32(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs

namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::UInt8 &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::UInt8 &);
size_t get_serialized_size(
  const std_msgs::msg::UInt8 &,
  size_t current_alignment);
size_t
max_serialized_size_UInt8(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs


namespace robot_info_system_msg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robot_info_system_msg
cdr_serialize(
  const robot_info_system_msg::msg::RobotStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: battery_level
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.battery_level,
    cdr);
  // Member: temperature
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.temperature,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robot_info_system_msg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  robot_info_system_msg::msg::RobotStatus & ros_message)
{
  // Member: battery_level
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.battery_level);

  // Member: temperature
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.temperature);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robot_info_system_msg
get_serialized_size(
  const robot_info_system_msg::msg::RobotStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: battery_level

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.battery_level, current_alignment);
  // Member: temperature

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.temperature, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robot_info_system_msg
max_serialized_size_RobotStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: battery_level
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Int32(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: temperature
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_UInt8(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = robot_info_system_msg::msg::RobotStatus;
    is_plain =
      (
      offsetof(DataType, temperature) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _RobotStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const robot_info_system_msg::msg::RobotStatus *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RobotStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robot_info_system_msg::msg::RobotStatus *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RobotStatus__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robot_info_system_msg::msg::RobotStatus *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RobotStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_RobotStatus(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _RobotStatus__callbacks = {
  "robot_info_system_msg::msg",
  "RobotStatus",
  _RobotStatus__cdr_serialize,
  _RobotStatus__cdr_deserialize,
  _RobotStatus__get_serialized_size,
  _RobotStatus__max_serialized_size
};

static rosidl_message_type_support_t _RobotStatus__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RobotStatus__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace robot_info_system_msg

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robot_info_system_msg
const rosidl_message_type_support_t *
get_message_type_support_handle<robot_info_system_msg::msg::RobotStatus>()
{
  return &robot_info_system_msg::msg::typesupport_fastrtps_cpp::_RobotStatus__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robot_info_system_msg, msg, RobotStatus)() {
  return &robot_info_system_msg::msg::typesupport_fastrtps_cpp::_RobotStatus__handle;
}

#ifdef __cplusplus
}
#endif
