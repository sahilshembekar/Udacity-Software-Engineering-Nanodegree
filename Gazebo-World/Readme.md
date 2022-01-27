## Udacity Nanodegree Project 1: Build my world

### Objective
To simulate a world in Gazebo.

### Topics covered in this Project
1. Gazebo GUI, model editor, building editor
2. Gazebo Plugins
3. Basics of Kinematics and C++

### Directory Structure

```
   .First-Project                      # Build My World Project 
    ├── model                          # Model files 
    │   ├── DemoOffice
    │   │   ├── model.config
    │   │   ├── model.sdf
    │   ├── Robot1
    │   │   ├── model.config
    │   │   ├── model.sdf
    ├── script                         # Gazebo World plugin C++ script      
    │   ├── welcome_message.cpp
    ├── world                          # Gazebo main World containing models 
    │   ├── DemoOffice.world
    ├── CMakeLists.txt                 # Link libraries 
    └

```

### System Requirements
You need to have Gazebo installed on your Linux system 
[Click here to download and follow the instructions](http://gazebosim.org/)

### Implementation
First build the plugin and update it.
Write the below commands on Terminal.

```
$ cd /home/robond/Desktop/First-Project
$ cd build/
$ cmake ../
$ make # You might get errors if your system is not up to date!
$ export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:/home/robond/Desktop/First-Project/build
```

Now, navigate to the world directory and run the following commands.

```
$ cd /home/robond/Desktop/First-Project/world/
$ gazebo DemoOffice

```
On the Terminal you should see the following command

```
Welcome to Sahil's world!
```

### Reference for further Development

- https://programmer.ink/think/build-your-own-environment-with-gazebo-simulator-of-ros.html
- http://playerstage.sourceforge.net/doc/Gazebo-manual-svn-html/tutorial_model.html
