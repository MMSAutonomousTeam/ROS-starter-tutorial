#!/usr/bin/env python3

import rclpy
import random
from rclpy.node import Node
from robot_info_system.msg import RobotStatus
from std_msgs.msg import Int32, UInt8

class RobotStatePublisher(Node):
    def __init__(self):
        super().__init__('robot_state_publisher')
        self.pub = self.create_publisher(RobotStatus, 'robot_status', 10)
        self.timer = self.create_timer(1.0, self.publish_state)

    def publish_state(self):
        msg = RobotStatus()
        msg.battery_level = Int32(data=random.randint(0, 100))
        msg.temperature = UInt8(data=random.randint(20, 100))

        self.pub.publish(msg)
        self.get_logger().info(f'Published: Battery={msg.battery_level.data}% Temp={msg.temperature.data}°C')

def main():
    rclpy.init()
    node = RobotStatePublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
