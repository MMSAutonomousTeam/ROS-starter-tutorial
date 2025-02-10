# Specify the minimum required version of CMake.
cmake_minimum_required(VERSION 3.8)

# Set the name of the project. In this case, the project is called "robot_info_system_msg".
project(robot_info_system_msg)

#-------------------------------------------------------------------
# Optional: Set additional compiler flags for better warnings.
# If the compiler is GNU or Clang, add extra warning flags to help catch
# potential issues in your code.
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

#-------------------------------------------------------------------
# Find and load the required packages for this project.
#
# - ament_cmake: Provides macros and functions to support the ament build system used by ROS 2.
# - rosidl_default_generators: Provides tools for generating code from ROS interface files (e.g., .msg files).
# - std_msgs: The package that provides standard message types (like Int32, UInt8), which our custom message depends on.
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)

#-------------------------------------------------------------------
# List the custom message files that you want to generate interfaces for.
# Here, we set a variable 'msg_files' containing the relative path to our custom message.
set(msg_files
  "msg/RobotStatus.msg"  # This is the custom message file that defines the RobotStatus message.
)

#-------------------------------------------------------------------
# Generate the interface code for your custom messages.
#
# The rosidl_generate_interfaces() macro takes:
#   - The project name (here, ${PROJECT_NAME} expands to "robot_info_system_msg"),
#   - A list of message files to process (in this case, ${msg_files}),
#   - And a list of dependencies (here, std_msgs) that the message depends on.
#
# This macro will generate language-specific code (e.g., for Python and/or C++) so that the
# custom message (RobotStatus) can be used in nodes.
rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
  DEPENDENCIES std_msgs
)

#-------------------------------------------------------------------
# Export the dependency on rosidl_default_runtime.
#
# This ensures that any package depending on this message package will also have access
# to the runtime support necessary for the generated message code.
ament_export_dependencies(rosidl_default_runtime)

#-------------------------------------------------------------------
# Finalize the package configuration.
#
# ament_package() must be called at the end of the CMakeLists.txt file to properly set up the package
# for use with the ament build system.
ament_package()
