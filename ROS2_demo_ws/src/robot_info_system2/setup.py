from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'robot_info_system2'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob(os.path.join('launch', '*launch.[pxy][yma]*'))),
    ],

    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='zaynap',
    maintainer_email='zozaahmad203@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    test_suite='tests',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'robot_state_publisher = robot_info_system2.robot_state_publisher:main',
            'robot_monitor = robot_info_system2.robot_monitor:main'
        ],
    },
)




##########################################################read this for more expalination #########################################
# from setuptools import find_packages, setup
#     find_packages : to find all the packages in your project 
#     setup : define package metadata , depend


# package_name = 'robot_info_system2'
#     to define a variable with the package name to could use it in another parts 

# setup(
#     the main function to add installation and metadata for the package 

# name=package_name,
#     sets the name of the package we previously declared 

# version='0.0.0',
#     version of the package 

# packages=find_packages(exclude=['test']),
#     Uses the find_packages function to automatically discover all packages and sub-packages in your project directory.
#     The exclude=['test'] parameter tells find_packages to ignore the test directory,
#     meaning that any code or modules inside it will not be packaged for installation.

# data_files=[
#     Begins a list of data files that need to be installed along with your package.
#     Data files are non-Python files such as configuration files, launch files, or in this case, custom message files.

# ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
#     This tuple specifies that a file located at resource/robot_info_system should be
#     installed into the directory share/ament_index/resource_index/packages.

#     in ros2 This line is used by ROS 2 to locate your package. 
#     The file in the resource directory is a marker file that helps ROS 2 tools identify installed packages.

# ('share/' + package_name, ['package.xml']),
#     Specifies that package.xml should be installed into the directory share/robot_info_system.

# ('share/' + package_name + '/config', glob('config/*.yaml')),
# ('share/' + package_name + '/launch', glob('launch/*.py')),

#     The first  line would install all .yaml files from a config directory into share/robot_info_system/config.
#     The second line would install all Python launch files from a launch directory into share/robot_info_system/launch.

# install_requires=['setuptools'],
#     Specifies the runtime dependencies for your package. In this case, it ensures that setuptools is available when your package is installed.

# zip_safe=True,
#     This flag indicates whether the project can be safely installed and run from a zip file.
#     Setting it to True means that your package does not rely on file system access to its source files.

# maintainer='zaynap',
# maintainer_email='name@email.com',
# description='Robot information system package for monitoring and publishing robot status',
# license='Apache License 2.0',
#     some meta data 

# tests_require=['pytest'],
#     Lists the dependencies needed to run the package's tests. Here, pytest is specified as a testing framework.

# entry_points={
#     'console_scripts': [
#         'robot_state_publisher = robot_info_system2.robot_state_publisher:main',
#         'robot_monitor = robot_info_system2.robot_monitor:main',
#         ],
#     },
# )
#         entry_points:This section defines executable scripts that will be installed into the system’s executable path.

#     console_scripts:Under this key, you define command-line scripts.

#     'robot_state_publisher = robot_info_system.robot_state_publisher:main':
#     This means that when a user types robot_state_publisher in the command line, the Python interpreter will execute the main function located in the robot_info_system/robot_state_publisher.py file.

#     'robot_monitor = robot_info_system.robot_monitor:main':
#     Similarly, this creates a command-line script robot_monitor that runs the main function in robot_info_system/robot_monitor.py.



