import rclpy
import pytest
import logging
from robot_info_system_msg.msg import RobotStatus
from robot_info_system2.robot_monitor import RobotMonitor


@pytest.fixture
def node():
    """Fixture to initialize and clean up the ROS2 node."""
    rclpy.init()
    test_node = RobotMonitor()  # Initialize node
    yield test_node  # Provide node to test functions
    test_node.destroy_node()  # Cleanup
    rclpy.shutdown()


# --------------------------------------
# ✅ Test: Node Initialization
# --------------------------------------
def test_node_initialization(node):
    """Ensure the node initializes with the correct name and a valid subscriber."""
    assert node.get_name() == "robot_monitor", "❌ Node name should be 'robot_monitor'."
    assert hasattr(node, "sub"), "❌ Subscriber should be initialized."


# --------------------------------------
# ✅ Test: Correct Subscription Topic
# --------------------------------------
def test_subscriber_topic(node):
    """Verify that the subscriber listens to the correct topic."""
    topics = node.get_topic_names_and_types()
    assert any(topic[0] == "/robot_status" for topic in topics), "❌ Subscriber should be on 'robot_status'."


# --------------------------------------
# ✅ Test: Node Parameters
# --------------------------------------
def test_node_parameters(node):
    """Ensure that battery and temperature threshold parameters are set correctly."""
    assert node.get_parameter("battery_threshold").value == 20, "❌ Battery threshold should be 20."
    assert node.get_parameter("temperature_threshold").value == 75, "❌ Temperature threshold should be 75."


# --------------------------------------
# ✅ Test: Battery Warning Trigger
# --------------------------------------
def print_logs_if_failed(caplog):
    """Helper function to print captured logs if a test fails."""
    if not caplog.records:
        print("⚠️ No logs were captured. Ensure the logger is set correctly!")
    else:
        print("\n".join(f"[{record.levelname}] {record.message}" for record in caplog.records))

        
def test_battery_threshold(node, caplog):
    """Simulate a low battery scenario and check if a warning is logged."""
    logger = logging.getLogger(node.get_logger().name)
    caplog.set_level(logging.WARNING, logger=logger.name)

    msg = RobotStatus()
    msg.battery_level.data = 10  # Below threshold
    msg.temperature.data = 50  # Normal temperature

    node.status_callback(msg)

    # Debugging: Print captured logs
    for record in caplog.records:
        print(f"Captured Log: {record.levelname} - {record.message}")

    assert any("Low Battery!" in record.message for record in caplog.records), \
        "❌ Expected 'Low Battery!' warning not found in logs!"

def test_temperature_threshold(node, caplog):
    """Simulate a high temperature scenario and check if a warning is logged."""
    caplog.set_level(logging.WARNING, logger="robot_monitor")

    msg = RobotStatus()
    msg.battery_level.data = 50  # Normal battery
    msg.temperature.data = 80  # Above threshold

    node.status_callback(msg)

    if not any("High Temperature!" in record.message for record in caplog.records):
        print_logs_if_failed(caplog)

    assert any("High Temperature!" in record.message for record in caplog.records), \
        "❌ Expected 'High Temperature!' warning not found in logs!"