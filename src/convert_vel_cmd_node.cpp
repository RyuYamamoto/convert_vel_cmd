#include <ros/ros.h>
#include <convert_vel_cmd/convert_vel_cmd.hpp>

int main(int argc, char* argv[])
{
	ros::init(argc, argv, "convert_vel_cmd_node");
	ros::NodeHandle nh;
	ConvertVelCmd convert_vel_cmd(nh);
	ros::spin();
	return 0;
}
