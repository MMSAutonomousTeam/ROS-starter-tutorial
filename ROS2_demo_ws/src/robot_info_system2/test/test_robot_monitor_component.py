import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from robot_info_system_msg.msg import RobotStatus  # Import your custom message
import pytest
import time

@pytest.fixture(scope="module")
def rclpy_node():
    """Fixture to initialize and shutdown an rclpy node for testing."""
    rclpy.init()
    node = Node("test_robot_monitor_component")
    yield node
    node.destroy_node()
    rclpy.shutdown()

def test_robot_monitor_component(rclpy_node):
    """Component test for the Robot Monitor node."""
    
    received_logs = []

    def log_callback(msg):
        """Callback to capture logs published by Robot Monitor."""
        received_logs.append(msg.data)

    # ✅ Create a subscription to listen to logs/messages
    rclpy_node.create_subscription(String, "/robot_monitor/logs", log_callback, 10)

    # ✅ Create a publisher to send test messages
    pub = rclpy_node.create_publisher(RobotStatus, "/robot_status", 10)
    time.sleep(1)  # Wait for node discovery

    # ✅ Publish test messages
    msg = RobotStatus()
    msg.battery_level.data = 10  # Low battery test
    msg.temperature.data = 80  # High temperature test

    pub.publish(msg)
    time.sleep(2)  # Give time for processing

    # ✅ Verify expected logs were received
    assert any("Low Battery!" in log for log in received_logs), "❌ 'Low Battery!' warning not received!"
    assert any("High Temperature!" in log for log in received_logs), "❌ 'High Temperature!' warning not received!"

    print("✅ Component test passed!")

