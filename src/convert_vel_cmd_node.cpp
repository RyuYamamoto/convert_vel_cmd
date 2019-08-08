#include <ros/ros.h>
#include <autoware_msgs/VehicleCmd.h>
#include <geometry_msgs/Twist.h>

ros::Subscriber vehicle_cmd_sub;
ros::Publisher cmd_vel_pub;

void callback(const autoware_msgs::VehicleCmdConstPtr &msg)
{
	geometry_msgs::Twist cmd_vel;
	cmd_vel = msg->twist_cmd.twist;
	cmd_vel.linear.x *= 0.8;
	cmd_vel_pub.publish(cmd_vel);
}

int main(int argc, char* argv[])
{
	ros::init(argc, argv, "convert_vel_cmd_node");
	ros::NodeHandle nh;

	vehicle_cmd_sub = nh.subscribe("/vehicle_cmd", 10, callback);
	cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("sample_robot/diff_drive_controller/cmd_vel", 10);
	ros::spin();
	return 0;
}
