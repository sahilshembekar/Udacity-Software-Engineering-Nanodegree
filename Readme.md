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

<a name="project2"/>

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
![](Media/Project2/ball_chaser.gif)

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


![](Media/Project3/Control-Using-2D-Nav-Goal.gif)

## Demo with Control-using-teleop-keyboard 

![](Media/Project3/Control-using-teleop-keyboard.gif)


<!--
<a name="project4"/>

## 4. Project4: Map My World

### Goal

Interface my mobile robot with an RTAB Map ROS package to localize the robot and build 2D and 3D maps of the environment. Properly launch the robot and then teleop it to map its environment.

### What I learned
- SLAM implementation with ROS/Gazebo
- ROS debugging tools: rqt, roswtf

<a name="project5"/>

## 5. Project5: Home Service Robot

### Goal

Use a SLAM package to autonomously map an environment and interface robot with a path planning and navigation ROS package to move objects within an environment.

### What I learned
- Advanced ROS and Gazebo Integration
- ROS Navigation stack 7
- Path Planning

--->