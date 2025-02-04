import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    config_file = os.path.join(
        get_package_share_directory('robot_info_system'),
        'config',
        'robot_config.yaml'
    )

    return LaunchDescription([
        Node(
            package='robot_info_system',
            executable='robot_state_publisher',
            output='screen'
        ),
        Node(
            package='robot_info_system',
            executable='robot_monitor',
            output='screen',
            parameters=[config_file]
        ),
    ])
