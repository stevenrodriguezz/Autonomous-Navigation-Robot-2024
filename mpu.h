#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

Adafruit_BNO055 bno = Adafruit_BNO055(55);
double originalX = 0; // Global variable to store the original X position

void mpu_setup() {
  Serial.begin(9600);
  delay(1000); // Delay for stability
  
  if (!bno.begin())
  {
    Serial.println("Failed to initialize BNO055 sensor!");
    while (1); // Halts program execution indefinitely
  }

  Serial.println("BNO055 sensor initialized successfully!");
}

void mpu_loop() {
  /* Get a new sensor event */
  sensors_event_t event;
  bno.getEvent(&event);

  if (originalX == 0) {
    originalX = event.orientation.x; // Store the original X position
    Serial.print("Original X: ");
    Serial.println(originalX);
  }

  /* Display the floating point data */
  Serial.print("X-axis Orientation: ");
  Serial.println(event.orientation.x);

  delay(1000); // Delay for readability
}
