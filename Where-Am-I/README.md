# Project3: Where Am I?

### Goal
Use the Adaptive Monte Carlo Localization algorithm in ROS to localize my robot.

### Steps to launch the simulation

#### Update and upgrade the Workspace image
```
sudo apt-get update
sudo apt-get upgrade -y
```
#### Clone the lab folder in /home/workspace/
```
cd /home/workspace/
git clone https://github.com/sahilshembekar/Udacity-Software-Engineering-Nanodegree.git
```
#### Launch the simulation
```
cd /home/workspace/Where-Am-I/catkin_ws
source devel/setup.bash
roslaunch my_robot world.launch
```

#### Launch amcl launch file
```
cd /home/workspace/Where-Am-I/catkin_ws
source devel/setup.bash
roslaunch my_robot amcl.launch
```
#### Testing

##### Option 1: Send 2D Navigation Goal from RViz
Click the 2D Nav Goal button in the toolbar, then click and drag on the map to send the goal to the robot. It will start moving and localize itself in the process.

##### Option 2: Use teleop node
```
cd /home/workspace/Where-Am-I/catkin_ws
source devel/setup.bash
rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```
Now, you can control my robot by keyboard commands.

### Result
![images](./images/Screenshot-of-Localization-in-Rviz.png)