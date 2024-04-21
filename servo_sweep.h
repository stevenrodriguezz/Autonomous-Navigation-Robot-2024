#include <Servo.h>
#include "ultrasonic.h"

Servo myservo;  

int home_pos = 73;
int start_sweep = 0;    // variable to store the servo position
int saved_angle = 0;    // variable to store the angle at which the sweep is stopped

void servo_setup() {
  myservo.attach(5);  // attaches the servo on pin 5 to the servo object
  myservo.write(home_pos);
}

void servo_loop() {
  int rotation_angle = 0; // Variable to store the rotation angle when the distance exceeds 30 cm

  // Sweep from 0 degrees to 140 degrees
  for (start_sweep = 0; start_sweep <= 140; start_sweep += 1) {
    // Check if the distance from the object is greater than 30 cm
    if (distance_from_object() > 30) {
      // Save the current angle and stop the sweep
      saved_angle = start_sweep;
      myservo.write(home_pos); // Return to the original servo position
      break; // Exit the loop
    } else {
      // Continue the sweep
      myservo.write(start_sweep);  // Tell servo to go to position in variable 'start_sweep'
      delay(15);                   // Wait for the servo to reach the position
    }
  }

  // Calculate the rotation angle based on the saved angle and home position
  if (saved_angle > home_pos) {
    rotation_angle = saved_angle - home_pos;
  } else if (saved_angle < home_pos) {
    rotation_angle = home_pos - saved_angle;
  }

  // If the sweep was stopped prematurely, print the rotation angle and exit the function
  if (rotation_angle != 0) {
    Serial.print("Rotation angle: ");
    Serial.println(rotation_angle);
    return;
  }

  // Sweep from 140 degrees to 0 degrees
  for (start_sweep = 140; start_sweep >= 0; start_sweep -= 1) {
    myservo.write(start_sweep);  // Tell servo to go to position in variable 'start_sweep'
    delay(15);                   // Wait for the servo to reach the position
  }
}

