import launch
import launch_ros.actions

def generate_launch_description():
    return launch.LaunchDescription([
        launch_ros.actions.Node(
            package='robot_info_system2',
            executable='robot_monitor',
            name='robot_monitor'),

        launch_ros.actions.Node(
            package='robot_info_system2',
            executable='robot_state_publisher',
            name='robot_state_publisher'),
  ])