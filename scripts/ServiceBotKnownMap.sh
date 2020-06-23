#!/bin/sh

xterm -e " roslaunch my_robot world.launch " &
sleep 10
xterm -e " roslaunch my_robot amcl.launch " &
sleep 10
xterm -e " roslaunch add_markers add_markers.launch" &
sleep 10
xterm -e " roslaunch pick_objects pick_objects.launch " 

