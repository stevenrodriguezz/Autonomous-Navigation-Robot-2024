# Obstacle Avoidance Robot #


#Project Overview#

This project involves the development of an autonomous robot designed for obstacle avoidance and navigation using real-time sensor data. The robot utilizes a state machine to manage various actions, including moving forward, backward, and turning, allowing for adaptive navigation through dynamic environments.

Features
Real-Time Obstacle Detection: The robot employs an ultrasonic distance sensor to detect obstacles within a specified range, ensuring safe navigation.
State Machine Architecture: A robust state machine manages the robot's movement states, enabling smooth transitions between actions based on sensor feedback.
Sensor Integration: Incorporates a BNO055 orientation sensor and a servo for enhanced spatial awareness and environmental scanning.
Modular Code Design: Code is organized into functional modules for motor control, sensor management, and servo operation, promoting reusability and clarity.
Components
1. Main Logic (main.ino)
Implements the core logic for obstacle avoidance and navigation using the defined movement states.
Manages transitions between moving forward, backward, stopping, and turning based on distance readings.
2. MPU Setup (mpu.h)
Initializes and retrieves orientation data from the BNO055 sensor.
Provides functions for handling sensor events and displaying orientation data.
3. Motor Control (robot_movement.h)
Controls the H-bridge motor driver for movement actions (forward, backward, turns, stop).
Defines pin assignments and motor control functions for seamless operation.
4. Servo Control (servo_sweep.h)
Sets up the servo motor for scanning the environment.
Contains a loop for sweeping, currently commented out for future implementation.
5. Ultrasonic Distance Sensor (ultrasonic.h)
Measures the distance to nearby objects and provides real-time distance readings.
Prints distance data to the serial monitor for debugging and analysis.
