# Project 5: Home Service Robot

### Goal
Program a robot that can autonomously map an environment and navigate to pick up and drop virtual objects.
This is where all the previous projects come together. `gmapping` is used to create a map in which the turtlebot traverses from the starting point to the drop-off point via the pick-up waypoint. The object is represented by a Red marker.


### Directory Structure

```
.Home-Sevice-Robot                                        # Home Service Robot Project
├── catkin_ws                                             # Catkin workspace
│   ├── src
│   │   ├── add_markers                                   # add_markers package        
│   │   │   ├── launch
│   │   │   │   ├── view_navigation_add_marker.launch     # launch file for home service robot demo
│   │   │   ├── rviz
│   │   │   │   ├── home_service_robot.rviz               # rvizConfig file for home service robot 
│   │   │   ├── src
│   │   │   │   ├── add_markers.cpp                       # source code for add_markers node
│   │   │   │   ├── add_markers_static.cpp                # source code for addding the markers in static state
│   │   ├── pick_objects                                  # pick_objects package     
│   │   │   ├── src
│   │   │   │   ├── pick_objects.cpp                      # source code for pick_objects node 
│   │   ├── scripts                                       # shell scripts files
│   │   │   ├── add_marker.sh                             # shell script to model virtual objects  
│   │   │   ├── home_service.sh                           # shell script to launch home service robot demo  
│   │   │   ├── pick_objects.sh                           # shell script to send multiple goals  
│   │   │   ├── test_navigation.sh                        # shell script to test localization and navigation
│   │   │   ├── test_slam.sh                              # shell script to test SLAM
│   │   ├── map                                           # map files
│   │   │   ├── map.pgm                                   # map image file  
│   │   │   ├── map.yaml                                  # map yaml file  
│   │   │   ├── Office.world                              # World file used to make the map  
│   │   ├── slam_gmapping                                 # gmapping_demo.launch file
│   │   ├── turtlebot                                     # keyboard_teleop.launch file
│   │   ├── turtlebot_interactions                        # view_navigation.launch file
│   │   ├── turtlebot_simulator                           # turtlebot_world.launch file package        
│   │   ├── CMakeLists.txt                                # compiler instructions

```

## Packages Used
- [gmapping](http://wiki.ros.org/gmapping)  
Using `gmapping_demo.launch` to perform SLAM and build a map of the environment with a robot equipped with laser range finder sensors or RGB-D type cameras.

- [turtlebot_teleop](http://wiki.ros.org/turtlebot_teleop)  
To manually control a robot using keyboard commands with **keyboard_teleop.launch** in case it is needed.

- [turtlebot_rviz_launchers](http://wiki.ros.org/turtlebot_rviz_launchers)  
Using the `view_nagivation.launch` to load a pre-configured rviz workspace for visualization (e.g. robot model, trajectories, map, etc).

- [turtlebot_gazebo](http://wiki.ros.org/turtlebot_gazebo)  
With `turtlebot_world.launch` to deploy a turtlebot in a gazebo environment by linking the world file to it. `amcl_demo.launch` also used for localization.

## Scripts
- Shell scripts  
To automate launching of ros commands via command lines instead of using roslaunch or roscore. Located in **scripts** folder.

## Configuration Files
- `map.pgm`, `map.yaml`  
Both files are required to provide a map for amcl, located in the **map** folder.
- `Office.world`  
World file to setup the environment in Gazebo, located in the **map** folder.

#### Total of 5 scripts for the demo of 5 different tests.
1. **`launch.sh`**  
To launch Gazebo and Rviz without any configuration.  
2. **`test_slam.sh`**  
To manually test the SLAM. Controlling the turtlebot by keyboard commands.  
3. **`test_navigation.sh`**  
To make sure that the turtlebot is able to reach different positions by manually setting up the 2D navigation goal using Rviz.  
4. **`pick_objects.sh`**  
To make sure robot is able to reach its two predefined locations. The robot will travel to the desired pickup location, wait for 5 seconds, then travel to desired drop off location.  
5. **`add_marker.sh`**  
To visualize and test the marker's behaviors. A cube marker will first appear at one position for 5 seconds, then disappear for 5 seconds, and lastly it will show up at another location.  
6. **`home_service.sh`**  
The final script for robot's movements utilizing all the packages used in the previous tests. An object (shown with a marker) will first show up at the pickup location where the robot will move towards. Upon reaching the position, the marker will disappear. Then the robot will move towards the drop off location and drop off the object, the marker will reappear at the drop off location.


### Steps to launch the home robot service simulation

#### Step 1. Update the system
`sudo apt-get update`

#### Step 2. Install the ROS navigation stack
`sudo apt-get install ros-kinetic-navigation`

#### Step 3. Create catkin workspace
```sh
$ mkdir -p ~/catkin_ws/src
$ cd ~/catkin_ws/src
$ catkin_init_workspace
$ cd ~/catkin_ws
$ catkin_make
```
#### Step 4. Run the Project
```sh
$ cd ~/catkin_ws/src/scripts
$ chmod +x home_service.sh
$ ./home_service.sh
```

### Output
Gazebo should launch the environment that has turtlebot inside the world. Then RViz should map the environment around the turtlebot. The marker should be appear near the pick up location. The robot should start moving towards the marker and once the robot reaches the pick-up location where the marker is, the marker should be "picked up" by the robot. The robot should then move to the drop-off location and "drop off" the marker.