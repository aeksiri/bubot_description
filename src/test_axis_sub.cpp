

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/JointState.h"
#include "std_msgs/Float64.h"


class SubscribeAndPublish
{
	private:
  		ros::NodeHandle nh; 
  		ros::Publisher pub_pose[24];
  		ros::Subscriber sub_moveit;

	public:
		SubscribeAndPublish()
		{

			sub_moveit = nh.subscribe("/joint_states", 1000, &SubscribeAndPublish::move_joint_data, this);
			
			
			pub_pose[5]	 	= nh.advertise<std_msgs::Float64>("torso_yaw_joint_controller/command", 1000);
			pub_pose[6]		= nh.advertise<std_msgs::Float64>("tray_pitch_joint_controller/command", 1000);
			pub_pose[7]		= nh.advertise<std_msgs::Float64>("head_yaw_joint_controller/command", 1000);
			pub_pose[8]		= nh.advertise<std_msgs::Float64>("head_pitch_joint_controller/command", 1000);

			pub_pose[9]		= nh.advertise<std_msgs::Float64>("left_arm_shoulder_pitch_joint_controller/command", 1000); 	
			pub_pose[10]	= nh.advertise<std_msgs::Float64>("left_arm_shoulder_roll_joint_controller/command", 1000);
			pub_pose[11]	= nh.advertise<std_msgs::Float64>("left_arm_shoulder_yaw_joint_controller/command", 1000);
			pub_pose[12]	= nh.advertise<std_msgs::Float64>("left_arm_elbow_roll_joint_controller/command", 1000);
			pub_pose[13]	= nh.advertise<std_msgs::Float64>("left_arm_forearm_yaw_joint_controller/command", 1000);
			pub_pose[14]	= nh.advertise<std_msgs::Float64>("left_arm_wrist_roll_joint_controller/command", 1000);
			pub_pose[15] 	= nh.advertise<std_msgs::Float64>("left_gripper_joint_controller/command", 1000);

			pub_pose[16] 	= nh.advertise<std_msgs::Float64>("right_arm_shoulder_pitch_joint_controller/command", 1000);
			pub_pose[17]  	= nh.advertise<std_msgs::Float64>("right_arm_shoulder_roll_joint_controller/command", 1000);
			pub_pose[18]   	= nh.advertise<std_msgs::Float64>("right_arm_shoulder_yaw_joint_controller/command", 1000);
			pub_pose[19]    = nh.advertise<std_msgs::Float64>("right_arm_elbow_roll_joint_controller/command", 1000);
			pub_pose[20]    = nh.advertise<std_msgs::Float64>("right_arm_forearm_yaw_joint_controller/command", 1000);
			pub_pose[21]    = nh.advertise<std_msgs::Float64>("right_arm_wrist_roll_joint_controller/command", 1000);
			pub_pose[22]    = nh.advertise<std_msgs::Float64>("right_gripper_joint_controller/command", 1000);

			
		}

		void move_joint_data(const  sensor_msgs::JointState::ConstPtr& moveit_data)
		{
			std_msgs::Float64 move_dynamixel;

			for(int i=5; i<=22; i++)
			{
				printf("%s   ", moveit_data->name[i].c_str());
				printf("%f\n", moveit_data->position[i]);
				move_dynamixel.data = moveit_data->position[i];
				pub_pose[i].publish(move_dynamixel);
			}

			printf("\n");

		}

};//End of class SubscribeAndPublish

int main(int argc, char **argv)
{
  
	ros::init(argc, argv, "subscribe_and_publish");

	SubscribeAndPublish SAPObject;

  

  	ros::spin();

  	return 0;
}