#!/bin/sh

# Define workspace variable
path_catkin_ws="/home/workspace/catkin_ws"

# TURTLEBOT_WORLD: Open the workspace, source and launch turtlebot_world.launch
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=${path_catkin_ws}/src/map/Office.world" &

sleep 10

# AMCL_DEMO: Open the workspace, source and launch amcl_demo.launch
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch turtlebot_gazebo amcl_demo.launch  map_file:=${path_catkin_ws}/src/map/map.yaml" &

sleep 10

# VIEW_NAVIGATION: Open the workspace, source and launch view_navigation.launch
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch add_markers view_navigation_add_marker.launch" &

sleep 10

# ADD_MARKERS: Open the workspace, source and launch add_markers add_markers
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && rosrun add_markers add_markers" &

sleep 10

# PICK_OBJECTS: Open the workspace, source and launch pick_objects pick_objects
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && rosrun pick_objects pick_objects" 