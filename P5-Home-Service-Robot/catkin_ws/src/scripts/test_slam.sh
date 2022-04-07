#!/bin/sh

# Define workspace variable
path_catkin_ws="/home/workspace/catkin_ws"

# TURTLEBOT_WORLD: Open the workspace, source and launch turtlebot_world.launch
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_gazebo turtlebot_world.launch" &

sleep 5

# GMAPPING_DEMO: Open the workspace, source and launch gmapping_demo.launch
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_gazebo gmapping_demo.launch" &

sleep 5

#  VIEW_NAVIGATION: Open the workspace, source and launch view_navigation.launch
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_rviz_launchers view_navigation.launch" &

sleep 5

# KEYBOARD_TELEOP: Open the workspace, source and launch keyboard_teleop.launch
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_teleop keyboard_teleop.launch"
