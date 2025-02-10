from setuptools import find_packages
from setuptools import setup

setup(
    name='robot_info_system_msg',
    version='0.0.0',
    packages=find_packages(
        include=('robot_info_system_msg', 'robot_info_system_msg.*')),
)
