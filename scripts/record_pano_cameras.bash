#!/bin/bash

rosbag record -o pano_cameras --duration=1m --split  /posmv/orientation /posmv/position /posmv/time_reference /pano_1/camera_info /pano_1/image_raw /pano_2/camera_info /pano_2/image_raw /pano_3/camera_info /pano_3/image_raw /pano_4/camera_info /pano_4/image_raw /pano_5/camera_info /pano_5/image_raw /pano_6/camera_info /pano_6/image_raw /tf_static /sensor/ais/contact /radar
