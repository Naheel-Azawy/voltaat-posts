/*
Sound controlled LED

Tutorial link: https://www.learn.voltaat.com/post/sound

This is an Arduino sketch turns on an LED once with clapping

Components Needed:
1. Sound sensor ....x1
2. LED .............x1

Connections:
Sound sensor G  → Arduino pin GND
Sound sensor +  → Arduino pin 5V
Sound sensor D0 → Arduino pin 2
LED             → Arduino pin 3

*/

#define SOUND_PIN 2 // Pin of the sound sensor
#define LED_PIN   3 // Pin of the LED

// Keep the status of the led to be changed later
bool led_status = false;

// Commands inside void setup run once
void setup() {

  Serial.begin(9600);        // Start the serial monitor
  pinMode(SOUND_PIN, INPUT); // Set Pin connected to the sound sensor as an INPUT
  pinMode(LED_PIN, OUTPUT);  // Set Pin connected to the LED as an OUTPUT

}

// Commands inside void loop run forever
void loop() {

  // If sound detected
  if (digitalRead(SOUND_PIN) == HIGH){

    // If the LED was off
    if (led_status == false) {

      digitalWrite(LED_PIN, HIGH); // Turn LED on
      led_status = true;           // Set the LED status
      Serial.println("Turn LED on");

    } else { // Otherwise, if LED was on

      digitalWrite(LED_PIN, LOW); // Turn LED off
      led_status = false;         // Set the LED status
      Serial.println("Turn LED off");

    }

  }

}
