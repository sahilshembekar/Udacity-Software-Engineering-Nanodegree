#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    // Request a service and pass the velocities to it to drive the robot
    ROS_INFO_STREAM("Requesting the velocities to drive the robot...");

    ball_chaser::DriveToTarget srv1;
    srv1.request.linear_x = lin_x;
    srv1.request.angular_z = ang_z;

    // In case of failure print error
    if (!client.call(srv1))
        ROS_ERROR("Failed to call the service command_robot");

}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{
	
    // Loop through each pixel in the image and check if there's a bright white one
    // Then, identify if this pixel falls in the left, mid, or right side of the image
    // Depending on the white ball position, call the drive_bot function and pass velocities to it
    // Request a stop when there's no white ball seen by the camera

	int white_pixel = 255;
	bool ball_found = false; //Initially ball is not found
	float lin_x = 0;
	float ang_z = 0; //Initial values taken as 0
	
	for(int i = 0; i < img.height * img.step; i += 3) {
		if (img.data[i] == white_pixel && img.data[i + 1] == white_pixel && img.data[i + 2] == white_pixel) {
		//Means that the nall is found	    	
		ball_found = true;
	    	int location_found = i % img.step;
	    	if (location_found < img.step / 3) {
            		
			// Turn the robot Left
            		lin_x = 0.0;
            		ang_z = 0.5;
	    	}
	    	else if (location_found > img.step * 2 / 3) {
            		
			// Turn the robot Right
            		lin_x = 0.0;
            		ang_z = -0.5;
	    	}
	    	else {
			//otherwise just go ahead
            		// Move the robot Forward
            		lin_x = 0.5;
    			ang_z = 0.0;
	    	}
	        break;
        }
    }
     if (ball_found == false) {
	lin_x = 0.0;
	ang_z = 0.0;
     }
	
    drive_robot(lin_x, ang_z); // In all other cases move 
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}

