#include <DistanceSensor.h>

// Define pins
const int echoPin = 24;
const int trigPin = 22;

// Start the sensor
DistanceSensor sensor(trigPin, echoPin);


int distance_from_object () {
    // Get distance in cm
    int distance = sensor.getCM();
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println("cm");

    return distance; 
    delay(2000);
} 

    // // Write values to serial port
    // Serial.print("Distance: ");
    // Serial.print(distance);
    // Serial.println("cm");

    // // Wait a bit
    // delay(500);
