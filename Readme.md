## Udacity-Robotics-Software-Engineering-Nanodegree

This repository contains Project done for Nanodegree in Robotics Software Engineer by Udacity

Course Link: [Robotics Software Engineer](www.udacity.com/course/robotics-software-engineer--nd209)

There are a total of 5 projects. This repository is currently under development.
<!--- 
All media files can be found in the [media]() folder.
<a name="project1"/>
--->
## 1. Project1: Gazebo-World

### Goal

Design a Gazebo World environment including multiple models and use it as a base for the rest of my projects.

### What I learned
- Launching a Gazebo Environment
- Designing in Gazebo


## 2. Project2: Go Chase It

### Goal

Design and build a mobile robot, and house it in a world. Next, program the robot with nodes and services using C++ in ROS to chase a white colored ball.

### What I learned
- Building Catkin Workspaces
- ROS node creation
- ROS node communication
- Using additional ROS packages
- Gazebo world integration
- RViz integration
- rqt_graph for debugging

## Demo
![](Media/Project2/ball_chaser_new.gif)

<!---
<a name="project3"/> -->

## 3. Project3: Where Am I?

### Goal

Interface the mobile robot with the Adaptive Monte Carlo Localization (AMCL) algorithm in ROS to estimatethe robot's position as it travels through a predefined set of waypoints, and tune different parameters to increase the localization efficiency of the robot.

### What I learned
- Implementation of Adaptive Monte Carlo Localization in ROS
- How to generate a map using pgm_map_creator
- Using move_base node package
- Understanding of tuning of parameters 

## Demo with Control-Using-2D-Nav-Goal
![](Media/Project3/Control-using-2D-Nav-Goal.gif)

## Demo with Control-using-teleop-keyboard 
![](Media/Project3/Control-using-teleop-keyboard.gif)

## 4. Project4: Map My World

### Goal

An application of [rtabmap-ros](http://wiki.ros.org/rtabmap_ros) package for simultaneous localization and mapping (SLAM) of a mobile robot. 
This project assumes known robot pose to map an environment. The robot uses camera data to recognize previously visited regions in the map using a graph-based SLAM approach known as Real-Time Appearance Based (RTAB) mapping (under the hood, bag-of-words is used for detecting loop closures). More information on this can be found [here](http://introlab.github.io/rtabmap/).

### What I learned
- Implementation of SLAM in ROS
- How to use rtabmap_ros package to generate database
- To view a database file using ` rtabmap-databaseViewer `

##

<table style="width:100%">
  <tr>
    <th><p>
           <img src="Media/Project4/World.jpg"
            alt="3D map" width="400" height="200"></a>
           <br>World 
        </p>
    </th>
    <th><p>
           <img src="Media/Project4/2dmap.png"
            alt="2D map" width="200" height="200"></a>
           <br>2D Map
      </p>
    </th>
  </tr>
  <tr>
    <th><p>
           <img src="Media/Project4/Occupancy-grid-map.png"
            alt="occupancy grid" width="400" height="200"></a>
           <br>Occupancy Grid
      </p>
    </th>
    <th><p>
           <img src="Media/Project4/Detected-Features.png"
            alt="features" width="200" height="200"></a>
           <br>Detected Features
      </p>
    </th>
  </tr>
</table>