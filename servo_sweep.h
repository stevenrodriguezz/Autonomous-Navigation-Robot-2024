
 #include <Servo.h>

Servo myservo;  

int home_pos = 73;
int start_sweep = 0;    // variable to store the servo position

void servo_setup() {
  myservo.attach(5);  // attaches the servo on pin 5 to the servo object
  myservo.write(home_pos);
}

void servo_loop() {
  // for (start_sweep = 0; start_sweep <= 180; start_sweep += 1) { // goes from 0 degrees to 180 degrees
  //   // in steps of 1 degree
  //   myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //   delay(15);                       // waits 15 ms for the servo to reach the position
  // }
  // for (start_sweep = 180; start_sweep >= 0; start_sweep -= 1) { // goes from 180 degrees to 0 degrees
  //   myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //   delay(15);                       // waits 15 ms for the servo to reach the position
  // }
}