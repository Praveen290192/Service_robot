/* Using navigation stack for sending a goal to drive the robot_base from one location to another location */

#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Define a client to send a goal requests to the move_base server through a SimpleActionClient
float pickUpGoal[3] = { -2.0, 2.0, 1.0};
float dropOffGoal[3] = { 5.0, -1.2, 1.0};
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv)
{
	//Initialize the simple_navigation_goals node
	ros::init(argc,argv, "pick_objects");
	 //tell the action client that we want to spin a thread by default
  	MoveBaseClient ac("move_base", true);

	// Wait 5 sec for move_base action server to come up
	while(!ac.waitForServer(ros::Duration(5.0)))
	{
		ROS_INFO("Waiting for the move_base action server to come up");
	}

	move_base_msgs::MoveBaseGoal goal;
	
	
	bool pick = false;
	bool drop = false;
	
	// set up the frame parameters
	goal.target_pose.header.frame_id = "odom";
	goal.target_pose.header.stamp = ros::Time::now();
	if(!pick)
	{
		// Define a position and orientation for the robot to reach
		goal.target_pose.pose.position.x = pickUpGoal[0]; //10
		goal.target_pose.pose.position.y = pickUpGoal[1]; //5
		goal.target_pose.pose.orientation.w = pickUpGoal[2];

		// Send the goal position and orientation for the robot to reach
		ROS_INFO("Sending goal");
		ac.sendGoal(goal);

		// Wait an infinite time for the results
		ac.waitForResult();

		// Check if the robot reached its goal
		if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
		{
			ROS_INFO("Reached Pick Position");
			pick = true;
		}	
		else
		{
			ROS_INFO("Failed to reach pick position");
		}
	}
	if(!drop)
	{
		// Define a position and orientation for the robot to reach
		goal.target_pose.pose.position.x = dropOffGoal[0]; //-11
		goal.target_pose.pose.position.y = dropOffGoal[1]; //1
		goal.target_pose.pose.orientation.w = dropOffGoal[2];

		// Send the goal position and orientation for the robot to reach
		ROS_INFO("Sending goal");
		ac.sendGoal(goal);

		// Wait an infinite time for the results
		ac.waitForResult();

		// Check if the robot reached its goal
		if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
		{
			ROS_INFO("Reached drop Position");
			drop = true;
		}	
		else
		{
			ROS_INFO("Failed to reach drop position");
		}
	}

	return 0;

}


