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

### Steps to launch the simulation

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
#### Step 4. Clone the following repositories to catkin_ws/src
```sh
$ cd ~/catkin_ws/src
$ git clone https://github.com/ros-perception/slam_gmapping.git
$ git clone https://github.com/turtlebot/turtlebot.git
$ git clone https://github.com/turtlebot/turtlebot_interactions.git
$ git clone https://github.com/turtlebot/turtlebot_simulator.git
```
Install package dependencies with `rosdep install [package-name]`

#### Step 5. Source and build the project
```sh
$ cd ~/catkin_ws
$ source devel/setup.bash
$ catkin_make
```
Run `./home_service.sh` in `scripts` directory to deploy the home service robot.

### Output
Gazebo should launch the environment that has turtlebot inside the world. Then RViz should map the environment around the turtlebot. The marker should be appear near the pick up location. The robot should start moving towards the marker and once the robot reaches the pick-up location where the marker is, the marker should be "picked up" by the robot. The robot should then move to the drop-off location and "drop off" the marker.