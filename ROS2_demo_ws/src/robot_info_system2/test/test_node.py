import time
import logging
import pytest
from robot_info_system_msg.msg import RobotStatus

def test_publishing_message(node):
    """Test if the published message has valid data."""
    
    # Subscribe to the topic instead of accessing an attribute
    received_messages = []

    def callback(msg):
        received_messages.append(msg)

    subscription = node.create_subscription(RobotStatus, 'robot_status', callback, 10)
    
    time.sleep(0.5)  # Allow time for message reception
    node.publish_state()
    time.sleep(0.5)  # Allow time for message reception

    assert received_messages, "No message received!"
    msg = received_messages[-1]  # Get the last received message

    assert 0 <= msg.battery_level.data <= 100, "Battery level out of range!"
    assert 20 <= msg.temperature.data <= 100, "Temperature out of range!"


def test_battery_threshold(node, caplog):
    """Test if the battery warning is triggered correctly."""
    caplog.set_level(logging.WARNING)
    msg = RobotStatus()
    msg.battery_level.data = 10  # Below the threshold

    node.status_callback(msg)

    # Ensure the warning is logged
    assert any("⚠️ Low Battery!" in record.message for record in caplog.records), \
        "Low Battery warning not found in logs!"


def test_temperature_threshold(node, caplog):
    """Test if the temperature warning is triggered correctly."""
    caplog.set_level(logging.WARNING)
    msg = RobotStatus()
    msg.temperature.data = 80  # Above the threshold

    node.status_callback(msg)

    # Ensure the warning is logged
    assert any("🔥 High Temperature!" in record.message for record in caplog.records), \
        "High Temperature warning not found in logs!"
