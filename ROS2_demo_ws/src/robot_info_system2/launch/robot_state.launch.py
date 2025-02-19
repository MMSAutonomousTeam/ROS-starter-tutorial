#!/usr/bin/env python3
# This is a Python-based launch file for ROS 2.
# It uses the launch and launch_ros libraries to start multiple nodes in a coordinated way.

import launch  # Import the core launch library that provides the basic tools for creating and managing launch descriptions.
import launch_ros.actions  # Import ROS-specific actions, such as launching nodes, from the launch_ros package.

def generate_launch_description():
    """
    This function is the entry point for the ROS 2 launch system.
    When you run "ros2 launch", the launch system automatically calls this function to retrieve
    a LaunchDescription object that defines what actions to perform (like starting nodes, setting parameters, etc.).
    """
    # Create a LaunchDescription object that aggregates all the actions we want to perform.
    return launch.LaunchDescription([
        # ---------------------------------------------------------------------------------------
        # Action 1: Launch the 'robot_monitor' node.
        #
        # This action instructs ROS 2 to start a node using the specified parameters:
        # - package: The name of the package where the node's executable is located.
        # - executable: The name of the executable file that should be run.
        # - name: The desired name for this node instance in the ROS graph.
        # ---------------------------------------------------------------------------------------
        launch_ros.actions.Node(
            package='robot_info_system2',      # Package containing the node.
            executable='robot_monitor',        # Executable file to run (this starts the robot_monitor node).
            name='robot_monitor'               # The name assigned to the node instance.
        ),

        # ---------------------------------------------------------------------------------------
        # Action 2: Launch the 'robot_state_publisher' node.
        #
        # Similar to the first node, this action launches another node:
        # - It specifies the package, executable, and node name.
        # This node is responsible for publishing the robot's state.
        # ---------------------------------------------------------------------------------------
        launch_ros.actions.Node(
            package='robot_info_system2',          # Package containing the node.
            executable='robot_state_publisher',    # Executable file to run (this starts the robot_state_publisher node).
            name='robot_state_publisher'           # The name assigned to this node instance.
        ),
    ])
