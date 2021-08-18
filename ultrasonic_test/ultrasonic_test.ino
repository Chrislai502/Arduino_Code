/*
  Ultrasonic 4 Sensors Test
  ultrasonic-4sense-test.ino
  Uses 4 x HC-SR04 Ultrasonic Range Finders
  Uses NewPing Library

  DroneBot Workshop 2019
  http://dronebotworkshop.com
*/

// Include NewPing Library for HC-SR04 sensor
#include <NewPing.h>

// Hook up 4 HC-SR04 sensors in 1-pin mode
// Sensor 0
#define TRIGGER_PIN_0  8
#define ECHO_PIN_0     8


// Maximum Distance is 400 cm
#define MAX_DISTANCE 400

// Create objects for ultrasonic sensors
NewPing sensor0(TRIGGER_PIN_0, ECHO_PIN_0, MAX_DISTANCE);

// Variables to represent distances
float distance0;

void setup() {  
  
   // Serial monitor for testing
   Serial.begin (9600);
   
}

void loop() {
   
  // Read sensors in CM 
  // Sensor 0
  distance0 = sensor0.ping_cm();
  delay(20);
  
   
  // Send results to Serial Monitor
  // Sensor 0
  Serial.print("Distance 0 = ");
  if (distance0 >= 400 || distance0 <= 2) {
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance0);
    Serial.println(" cm");
    delay(500);
  }
  
  delay(500);
}
