// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robot_info_system_msg:msg/RobotStatus.idl
// generated code does not contain a copyright notice
#include "robot_info_system_msg/msg/detail/robot_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `battery_level`
#include "std_msgs/msg/detail/int32__functions.h"
// Member `temperature`
#include "std_msgs/msg/detail/u_int8__functions.h"

bool
robot_info_system_msg__msg__RobotStatus__init(robot_info_system_msg__msg__RobotStatus * msg)
{
  if (!msg) {
    return false;
  }
  // battery_level
  if (!std_msgs__msg__Int32__init(&msg->battery_level)) {
    robot_info_system_msg__msg__RobotStatus__fini(msg);
    return false;
  }
  // temperature
  if (!std_msgs__msg__UInt8__init(&msg->temperature)) {
    robot_info_system_msg__msg__RobotStatus__fini(msg);
    return false;
  }
  return true;
}

void
robot_info_system_msg__msg__RobotStatus__fini(robot_info_system_msg__msg__RobotStatus * msg)
{
  if (!msg) {
    return;
  }
  // battery_level
  std_msgs__msg__Int32__fini(&msg->battery_level);
  // temperature
  std_msgs__msg__UInt8__fini(&msg->temperature);
}

bool
robot_info_system_msg__msg__RobotStatus__are_equal(const robot_info_system_msg__msg__RobotStatus * lhs, const robot_info_system_msg__msg__RobotStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // battery_level
  if (!std_msgs__msg__Int32__are_equal(
      &(lhs->battery_level), &(rhs->battery_level)))
  {
    return false;
  }
  // temperature
  if (!std_msgs__msg__UInt8__are_equal(
      &(lhs->temperature), &(rhs->temperature)))
  {
    return false;
  }
  return true;
}

bool
robot_info_system_msg__msg__RobotStatus__copy(
  const robot_info_system_msg__msg__RobotStatus * input,
  robot_info_system_msg__msg__RobotStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // battery_level
  if (!std_msgs__msg__Int32__copy(
      &(input->battery_level), &(output->battery_level)))
  {
    return false;
  }
  // temperature
  if (!std_msgs__msg__UInt8__copy(
      &(input->temperature), &(output->temperature)))
  {
    return false;
  }
  return true;
}

robot_info_system_msg__msg__RobotStatus *
robot_info_system_msg__msg__RobotStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_info_system_msg__msg__RobotStatus * msg = (robot_info_system_msg__msg__RobotStatus *)allocator.allocate(sizeof(robot_info_system_msg__msg__RobotStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robot_info_system_msg__msg__RobotStatus));
  bool success = robot_info_system_msg__msg__RobotStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robot_info_system_msg__msg__RobotStatus__destroy(robot_info_system_msg__msg__RobotStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robot_info_system_msg__msg__RobotStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robot_info_system_msg__msg__RobotStatus__Sequence__init(robot_info_system_msg__msg__RobotStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_info_system_msg__msg__RobotStatus * data = NULL;

  if (size) {
    data = (robot_info_system_msg__msg__RobotStatus *)allocator.zero_allocate(size, sizeof(robot_info_system_msg__msg__RobotStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robot_info_system_msg__msg__RobotStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robot_info_system_msg__msg__RobotStatus__fini(&data[i - 1]);
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
robot_info_system_msg__msg__RobotStatus__Sequence__fini(robot_info_system_msg__msg__RobotStatus__Sequence * array)
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
      robot_info_system_msg__msg__RobotStatus__fini(&array->data[i]);
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

robot_info_system_msg__msg__RobotStatus__Sequence *
robot_info_system_msg__msg__RobotStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_info_system_msg__msg__RobotStatus__Sequence * array = (robot_info_system_msg__msg__RobotStatus__Sequence *)allocator.allocate(sizeof(robot_info_system_msg__msg__RobotStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robot_info_system_msg__msg__RobotStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robot_info_system_msg__msg__RobotStatus__Sequence__destroy(robot_info_system_msg__msg__RobotStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robot_info_system_msg__msg__RobotStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robot_info_system_msg__msg__RobotStatus__Sequence__are_equal(const robot_info_system_msg__msg__RobotStatus__Sequence * lhs, const robot_info_system_msg__msg__RobotStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robot_info_system_msg__msg__RobotStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robot_info_system_msg__msg__RobotStatus__Sequence__copy(
  const robot_info_system_msg__msg__RobotStatus__Sequence * input,
  robot_info_system_msg__msg__RobotStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robot_info_system_msg__msg__RobotStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robot_info_system_msg__msg__RobotStatus * data =
      (robot_info_system_msg__msg__RobotStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robot_info_system_msg__msg__RobotStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robot_info_system_msg__msg__RobotStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robot_info_system_msg__msg__RobotStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
