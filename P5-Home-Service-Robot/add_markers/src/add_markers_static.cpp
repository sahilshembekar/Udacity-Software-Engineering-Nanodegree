#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

int main( int argc, char** argv )
{
  ros::init(argc, argv, "basic_shapes");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1, true);

  uint32_t shape = visualization_msgs::Marker::CUBE;
  bool marker_show = true;
  bool show_status = true;

  while (ros::ok())
  {
    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker
    marker.ns = "basic_shapes";
    marker.id = 0;

    // Set the marker type
    marker.type = shape;

    // Set the marker action
    marker.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker
    marker.pose.position.x = -0.3;
    marker.pose.position.y = 1.35;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

	// Set the scale of the marker -- 0.3x0.3x0.3 here means 0.3m on a side
	marker.scale.x = 0.3;
	marker.scale.y = 0.3;
	marker.scale.z = 0.3;

	// Set the color -- be sure to set alpha to something non-zero!
	marker.color.r = 1.0f;
	marker.color.g = 0.0f;
	marker.color.b = 0.0f;
	marker.color.a = 1.0;

    marker.lifetime = ros::Duration();

    if(marker_show){
      ROS_INFO("Publish marker then go to sleep for 5 sec");
      marker_pub.publish(marker);
      ros::Duration(5.0).sleep();

      ROS_INFO("Remove marker then go to sleep for 5 sec");
      marker.action = visualization_msgs::Marker::DELETE;
      marker_pub.publish(marker);
      marker_show = false;
      ros::Duration(5.0).sleep();  
    }
    else{
      if(show_status)
      {
        ROS_INFO("Publish marker then do nothing");  
        show_status = false;
      }
      marker.pose.position.x = 1;
      marker.pose.position.y = 1;
      marker.action = visualization_msgs::Marker::ADD;
      marker_pub.publish(marker);
    }
  }
}