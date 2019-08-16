#ifndef _CONVERT_VEL_CMD_H_
#define _CONVERT_VEL_CMD_H_

#include <ros/ros.h>
#include <autoware_msgs/VehicleCmd.h>
#include <geometry_msgs/Twist.h>

class ConvertVelCmd
{
	public:
		ConvertVelCmd(ros::NodeHandle nh);
		~ConvertVelCmd(){}
		void vehicle_cmd_callback(const autoware_msgs::VehicleCmdConstPtr &msg);
	private:
		ros::NodeHandle _nh;

		ros::Subscriber _vehicle_cmd_sub;
		ros::Publisher _cmd_vel_pub;

		std::string _cmd_vel_topic;
};

#endif
