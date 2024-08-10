# Arduino Motor Controller

This code serves as a bridge between ROS and Arduino. The Arduino will (at least for now) read MPU6050 and send it over serial. It uses a request-response type of communication. This code is inspired by https://github.com/joshnewans/ros_arduino_bridge. I also have a separate repo (https://github.com/NoobiesDoobies/ros_arduino_bridge), which is another ros-arduino bridge, but for controlling and reading motor.



## Functionality

The main functionality provided is to receive MPU6050 reading requests over a serial connection, and provide gyro and acceleration feedback.

The main commands to know are

- `i` - MPU6050 response with rotation speed and acceleration readings
-  `j` - To calibrate MPU6050

