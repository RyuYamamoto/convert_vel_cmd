#include <convert_vel_cmd/convert_vel_cmd.hpp>

ConvertVelCmd::ConvertVelCmd(ros::NodeHandle nh)
	: _nh(nh)
{
	ros::NodeHandle pnh("~");
	pnh.param<std::string>("cmd_vel_topic", _cmd_vel_topic, "cmd_vel");

	_vehicle_cmd_sub = _nh.subscribe("/vehicle_cmd", 10, &ConvertVelCmd::vehicle_cmd_callback, this);
	_cmd_vel_pub = _nh.advertise<geometry_msgs::Twist>(_cmd_vel_topic, 10);
}

void ConvertVelCmd::vehicle_cmd_callback(const autoware_msgs::VehicleCmdConstPtr &msg)
{
	geometry_msgs::Twist cmd_vel;
	cmd_vel = msg->twist_cmd.twist;
	_cmd_vel_pub.publish(cmd_vel);
}
