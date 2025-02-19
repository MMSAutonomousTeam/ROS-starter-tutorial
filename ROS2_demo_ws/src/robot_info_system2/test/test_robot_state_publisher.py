import pytest  # Import pytest for unit testing
import time  # Import time module to add delays where necessary
import rclpy  # Import rclpy for interacting with ROS2
from std_msgs.msg import Int32, UInt8  # Import standard ROS2 message types
from robot_info_system_msg.msg import RobotStatus  # Import the custom message type for robot status
from robot_info_system2.robot_state_publisher import RobotStatePublisher  # Import the node under test

# -----------------------------------------------
#  Import Statements
# We import necessary libraries:
# - `pytest` for unit testing.
# - `rclpy` for ROS2 communication.
# - `std_msgs.msg` for standard message types (Int32, UInt8).
# - `robot_info_system_msg.msg.RobotStatus` (custom message).
# - `RobotStatePublisher` (our ROS2 node being tested).
# -----------------------------------------------

@pytest.fixture
def node():
    """
    Fixture to initialize the ROS2 node for testing.
    - Sets up a ROS2 node before the test starts.
    - Destroys the node after the test is done.
    """
    rclpy.init()  # Initializes ROS2 before the tests
    test_node = RobotStatePublisher()  # Creates an instance of the node we are testing
    yield test_node  # Provides the node for the test function
    test_node.destroy_node()  # Destroys the node after the test
    rclpy.shutdown()  # Properly shuts down ROS2

# -----------------------------------------------
#  `node()` Fixture (Setup & Teardown)
# - `rclpy.init()` → Initializes ROS2 before the tests.
# - `RobotStatePublisher()` → Creates an instance of the node we are testing.
# - `yield test_node` → Provides the node for the test function.
# - Cleanup:
#     - `test_node.destroy_node()` → Destroys the node after the test.
#     - `rclpy.shutdown()` → Properly shuts down ROS2.
# -----------------------------------------------

def test_publishing_message(node):
    """
    Test if the RobotStatePublisher publishes valid messages.
    - Subscribes to the 'robot_status' topic.
    - Waits for the message.
    - Validates message contents.
    """

    received_messages = []  # List to store received messages

    def callback(msg):
        """Callback function to handle received messages."""
        received_messages.append(msg)

    # Subscribe to the 'robot_status' topic
    subscription = node.create_subscription(RobotStatus, 'robot_status', callback, 10)

    time.sleep(1)  # Allow ROS2 time to establish the subscription
    
    node.publish_state()  # Call the function that should publish a message
    
    for _ in range(5):  # Try receiving a message with retries
        rclpy.spin_once(node, timeout_sec=0.5)  # Process ROS2 events
        if received_messages:  # If a message is received, exit loop
            break

    # Assert that at least one message was received
    assert received_messages, "No message received!"
    
    # Extract the first received message
    msg = received_messages[0]
    
    # Validate the battery level range (0-100%)
    assert 0 <= msg.battery_level.data <= 100, "Battery level is out of range!"
    
    # Validate the temperature range (20-100°C)
    assert 20 <= msg.temperature.data <= 100, "Temperature is out of range!"

# -----------------------------------------------
#  `test_publishing_message(node)`
#  Purpose: Checks if `RobotStatePublisher` correctly publishes messages.
#
#  Steps:
# 1️ Create a callback function → Stores messages received on the `robot_status` topic.
# 2️ Subscribe to the topic → Uses `create_subscription()`.
# 3️ Wait for ROS2 to establish the topic → `time.sleep(1)`.
# 4️ Trigger the node to publish → Calls `node.publish_state()`.
# 5️ Wait for messages:
#     - Uses `rclpy.spin_once()` to process ROS2 callbacks.
#     - If a message is received, the loop breaks early.
# 6️ Check if a message was received → `assert received_messages`.
# 7️ Validate message contents:
#     - Battery level is between `0` and `100`.
#     - Temperature is between `20` and `100`.
# -----------------------------------------------
