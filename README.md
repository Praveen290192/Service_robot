# Service_robot
This project contains the packages for robot to localize itself in the environment and travel to the target location for object pickup and drop

## Video Link
Unfamiliar environment
https://youtu.be/5DhNemCUV1k

Familiar environment
https://youtu.be/MEmC2viKCUY

## Cloning Repository
clone the repository in catkin_ws
then perform catkin_make

## To generate Own map
save you world file in the my_robot/worlds directory

run

cd catkin_ws/src/Service_robot/scripts

./test_slam.sh 

drive your robot through the enviornment. The gmapping slam methond is used for generating map.

## Saving Map
Open new terminal 

cd catkin_ws/src/Service_robot/map

After that use below command to save your map

rosrun map_server map_saver --occ 100 --free 10 -f my_map map:=/move_base/global_costmap/costmap

## Robot navigation through known map
Use below commands for picking and droping objects (AMCL localization algorithm is used for localizing itself in the environment.

cd catkin_ws/src/Service_robot/scripts

./ServiceBotKnownMap.sh

## Robot navigation through Unkown Map or Dynamic environment
This script will help robot to perform its task in dynamic environment or in the environment whose map is not provided. It uses Gmapping algorithm to perform it's localization in the environment

./ServiceBotUnkownMap.sh

## Issues
Sometime robot needs to be moved slightly from its location if it doesn't perform any actions.

