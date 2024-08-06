from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess

def generate_launch_description():
    ld = LaunchDescription()

    control_node = Node(
        package="control_pkg",
        executable="control"
    )

    sensors_node = Node(
        package="control_pkg",
        executable="sensors"
    )       


    ld.add_action(control_node)
    ld.add_action(sensors_node)   
   

    return ld
