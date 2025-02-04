import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/zaynap/ROS-starter-tutorial/ROS2_demo_ws/install/robot_info_system'
