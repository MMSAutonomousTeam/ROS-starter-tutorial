#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from robot_info_system_msg.msg import RobotStatus

class RobotMonitor(Node):
    def __init__(self):
        # Initialize the node with the name 'robot_monitor'
        super().__init__('robot_monitor')
        
        # Declare parameters with default values
        self.declare_parameter('battery_threshold', 20)
        self.declare_parameter('temperature_threshold', 75)
        
        # Retrieve the parameter values and store them in instance variables
        self.battery_threshold = self.get_parameter('battery_threshold').value
        self.temperature_threshold = self.get_parameter('temperature_threshold').value
        
        # Create a subscription to the 'robot_status' topic that expects RobotStatus messages.
        # When a message is received, the callback function `status_callback` is called.
        # The queue size for incoming messages is set to 10.
        self.sub = self.create_subscription(
            RobotStatus,          # Message type expected on the topic
            'robot_status',       # Name of the topic to subscribe to
            self.status_callback, # Callback function to process incoming messages
            10                    # Queue size (depth)
        )

    def status_callback(self, msg):
        """
        Callback function that is executed every time a RobotStatus message is received.
        It logs the received battery and temperature values, and issues warnings if thresholds are exceeded.
        """
        # Extract the battery level and temperature from the received message.
        # Note: Each field is a wrapped message (e.g., std_msgs/Int32), so the actual value is in the 'data' attribute.
        battery = msg.battery_level.data
        temperature = msg.temperature.data

        # Log an informational message showing the received values.
        self.get_logger().info(f'Received: Battery={battery}% Temp={temperature}°C')

        # Check if the battery level is below the declared threshold.
        if battery < self.battery_threshold:
            self.get_logger().warn('⚠️ Low Battery!')

        # Check if the temperature exceeds the declared threshold.
        if temperature > self.temperature_threshold:
            self.get_logger().warn('🔥 High Temperature!')

def main():
    # Initialize the ROS 2 Python client library.
    rclpy.init()
    
    # Create an instance of the RobotMonitor node.
    node = RobotMonitor()
    
    # Keep the node running and process callbacks until the node is shut down.
    rclpy.spin(node)
    
    # Cleanly destroy the node once spinning has stopped.
    node.destroy_node()
    
    # Shutdown the ROS 2 Python client library.
    rclpy.shutdown()

if __name__ == '__main__':
    main()
