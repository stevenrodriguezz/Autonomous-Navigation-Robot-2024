#include "servo_sweep.h"
#include "robot_movement.h"
#include "mpu.h"
//#include "ultrasonic.h"

// Define constants to represent movement states
const int MOVING_FORWARD_STATE = 0;
const int MOVING_BACKWARD_STATE = 1;
const int STOPPED_STATE = 2;
const int ROTATE_LEFT_STATE = 3;
const int ROTATE_RIGHT_STATE = 4;

// Initialize the state variable
int currentState = MOVING_FORWARD_STATE;

void setup() {
  Serial.begin(9600);
  servo_setup();
  //mpu_setup();
  delay(5000);
  hbridge_setup();
}

void loop() {
  // Get distance from object
  int object_distance = distance_from_object();

  // Determine action based on object distance and current state
  switch (currentState) {
    case MOVING_FORWARD_STATE:
      if (object_distance < 25) {
        // If object is too close, stop moving forward and start moving backward
        stop_moving();
        delay(3000);
        currentState = MOVING_BACKWARD_STATE;
      } else {
        // Otherwise, continue moving forward
        move_forward();
      }
      break;
      
    case MOVING_BACKWARD_STATE:
      // Move backward for a certain duration or until a certain condition is met
      move_backward();
      delay(1000); // Adjust the delay as needed
      currentState = STOPPED_STATE; // Move to STOPPED state after backing up
      break;

    case STOPPED_STATE:
      // Wait for a brief period in the stopped state
      stop_moving();
      delay(2000); // Adjust the delay as needed
      servo_loop();

      currentState = ROTATE_RIGHT_STATE; // Move back to MOVING_FORWARD state
      break;

    case ROTATE_RIGHT_STATE:

    turn_right();
    delay(1000);
    stop_moving();
    delay(2000);

    currentState = MOVING_FORWARD_STATE; 

    break;


    case ROTATE_LEFT_STATE:

    turn_left();
    delay(1000);
    stop_moving();
    delay(2000);

    currentState = MOVING_FORWARD_STATE; 

    break; 
  }

  // Add a delay to control the loop execution frequency
  delay(100); // Adjust delay as needed
}
