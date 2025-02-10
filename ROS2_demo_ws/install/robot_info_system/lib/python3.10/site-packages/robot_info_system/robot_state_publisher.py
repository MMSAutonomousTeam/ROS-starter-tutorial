#!/usr/bin/env python3

import rclpy
import random
from rclpy.node import Node
from std_msgs.msg import Int32, UInt8
from robot_info_system.msg import RobotStatus  # Import your custom message

class RobotStatePublisher(Node):
    """
    A ROS 2 node that publishes robot status messages periodically.
    
    It creates a publisher for the 'robot_status' topic and publishes
    a RobotStatus message at a fixed interval (1 second) with randomized
    battery level and temperature values.
    """
    
    def __init__(self):
        # Initialize the Node with the name 'robot_state_publisher'
        super().__init__('robot_state_publisher')
        # Create a publisher for the custom RobotStatus message on the 'robot_status' topic
        self.publisher_ = self.create_publisher(RobotStatus, 'robot_status', 10)
        # Set a timer to call publish_state() every 1.0 second
        self.timer = self.create_timer(1.0, self.publish_state)
        self.get_logger().info("RobotStatePublisher node has been started.")

    def publish_state(self):
        """
        Generates a RobotStatus message with randomized data and publishes it.
        """
        # Create an instance of the custom RobotStatus message
        msg = RobotStatus()
        # Set the battery_level field using a random integer (0 to 100) wrapped in an Int32
        msg.battery_level = Int32(data=random.randint(0, 100))
        # Set the temperature field using a random integer (20 to 100) wrapped in a UInt8
        msg.temperature = UInt8(data=random.randint(20, 100))
        
        # Publish the message on the 'robot_status' topic
        self.publisher_.publish(msg)
        # Log the published values for debugging
        self.get_logger().info(
            f"Published: Battery={msg.battery_level.data}% Temp={msg.temperature.data}°C"
        )

def main(args=None):
    """
    Initializes the ROS 2 Python client library, starts the node, and
    keeps it running until interrupted. Cleans up the node on shutdown.
    """
    # Initialize rclpy with command-line arguments if provided
    rclpy.init(args=args)
    node = RobotStatePublisher()
    
    try:
        # Keep the node running until a shutdown signal is received
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("Keyboard Interrupt (SIGINT) detected. Shutting down...")
    finally:
        # Clean up and shutdown the node properly
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()


