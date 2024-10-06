int IN1 = 38;
int IN2 = 36;
int IN3 = 34;
int IN4 = 32;

void hbridge_setup()
{
// Set the output pins

pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
}

void move_forward() {

// Move  Motors CCW - Forward
digitalWrite(IN1, LOW); //Left
digitalWrite(IN2, HIGH); // Left 
digitalWrite(IN3, LOW); // Right 
digitalWrite(IN4, HIGH); // Right 

}

void move_backward() {

// Move Motors CW - Backwards
digitalWrite(IN1, HIGH); //Left 
digitalWrite(IN2, LOW);  // Left 
digitalWrite(IN3, HIGH); // Right 
digitalWrite(IN4, LOW); // Right 

}

void turn_right() {

digitalWrite(IN1, HIGH); //Left Motor CW
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW); // Right Motor CCW
digitalWrite(IN4, HIGH); 

}

void turn_left() {

digitalWrite(IN1, LOW); //Left Motor CCW
digitalWrite(IN2, HIGH); 
digitalWrite(IN3, HIGH); // Right Motor CW
digitalWrite(IN4, LOW); 


}

void stop_moving() {

// Stop Both Motors 
digitalWrite(IN1, HIGH);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, HIGH);

}
