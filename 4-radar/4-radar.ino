/*
Ultrasonic Radar

Tutorial link: https://www.learn.voltaat.com/post/arduino-radar

This is an Arduino sketch controls an ultrasonic sensor with a servo motor to act like a radar. This sketch comes with a corresponding processing code.

Components Needed:
1. Ultrasonic sensor ....x1
2. Servo motor ..........x1

Connections:
Arduino GND pin         → Breadboard ground line
Arduino 5V pin          → Breadboard 5V line
Ultrasonic GND pin      → Breadboard ground line
Ultrasonic Vcc pin      → Breadboard 5V line
Ultrasonic Echo pin     → Arduino pin 2
Ultrasonic Trig pin     → Arduino pin 3
Servo motor brown wire  → Breadboard ground line
Servo motor red wire    → Breadboard 5V line
Servo motor orange wire → Arduino pin 4

*/

// Includes the Servo library
#include <Servo.h>

#define ECHO_PIN 2 // Ultrasonic echo pin
#define TRIG_PIN 3 // Ultrasonic trig pin
#define SERV_PIN 4 // Servo motor pin

Servo serv; // Create a servo object for controlling the servo motor

// Commands inside void setup run once
void setup() {
  Serial.begin(9600);        // Start the serial monitor
  pinMode(TRIG_PIN, OUTPUT); // Set the TRIG_PIN as an output
  pinMode(ECHO_PIN, INPUT);  // Set the ECHO_PIN as an input
  serv.attach(SERV_PIN);     // Set the Servo motor pin
}

// Commands inside void loop run forever
void loop() {
  int del = 30; // Set the delay between steps

  // Move from angle 0 to 180
  for (int i = 0; i < 180; ++i) {
    serv.write(i);
    Serial.print(i); Serial.print(',');
    Serial.println(calculateDistance());
    delay(del);
  }

  // Move from angle 179 to 1
  for (int i = 179; i > 0; --i) {
    serv.write(i);
    Serial.print(i); Serial.print(',');
    Serial.println(calculateDistance());
    delay(del);
  }
}

// Calculate the distance measured by the Ultrasonic sensor
int calculateDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  // Sets the TRIG_PIN on HIGH state for 10 micro seconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  // Reads the ECHO_PIN, returns the sound wave travel time in microseconds
  int duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}
