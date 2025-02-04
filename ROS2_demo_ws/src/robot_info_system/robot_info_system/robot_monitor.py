#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from robot_info_system.msg import RobotStatus

class RobotMonitor(Node):
    def __init__(self):
        super().__init__('robot_monitor')

        self.declare_parameter('battery_threshold', 20)
        self.declare_parameter('temperature_threshold', 75)

        self.battery_threshold = self.get_parameter('battery_threshold').value
        self.temperature_threshold = self.get_parameter('temperature_threshold').value

        self.sub = self.create_subscription(RobotStatus, 'robot_status', self.status_callback, 10)

    def status_callback(self, msg):
        battery = msg.battery_level.data
        temperature = msg.temperature.data

        self.get_logger().info(f'Received: Battery={battery}% Temp={temperature}°C')

        if battery < self.battery_threshold:
            self.get_logger().warn('⚠️ Low Battery!')

        if temperature > self.temperature_threshold:
            self.get_logger().warn('🔥 High Temperature!')

def main():
    rclpy.init()
    node = RobotMonitor()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
