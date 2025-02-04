from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'robot_info_system'

setup(
    name=package_name,
    version='0.0.1',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/config', glob('config/*.yaml')),  # Include config files
        ('share/' + package_name + '/launch', glob('launch/*.py')),  # Include launch files
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='zaynap',
    maintainer_email='zozaahmad203@gmail.com',
    description='Robot information system package for monitoring and publishing robot status',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'robot_state_publisher = robot_info_system.robot_state_publisher:main',
            'robot_monitor = robot_info_system.robot_monitor:main',
        ],
    },
)
