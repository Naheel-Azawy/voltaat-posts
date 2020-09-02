/*
  Arduino Track location

  Tutorial link: https://www.learn.voltaat.com/post/gps

  This is an Arduino sketch that reads NMEA data from the NEO-6M GPS module and outputs it to the serial monitor

  Components Needed:
  NEO-6M GPS Module ...x1

  Connections:
  NEO-6M GND → Arduino pin GND
  NEO-6M Vcc → Arduino pin 5V
  NEO-6M Rx  → Arduino pin 3
  NEO-6M Tx  → Arduino pin 4

*/

#include <SoftwareSerial.h> // Software serial connection library

#define GPS_RX 3 // GPS Rx pin
#define GPS_TX 4 // GPS Tx pin

// The serial connection to the GPS module
SoftwareSerial ss(GPS_TX, GPS_RX);

// Commands inside void setup run once
void setup() {

  Serial.begin(9600); // Start the serial monitor
  ss.begin(9600);     // Start the GPS software serial

}

// Commands inside void loop run forever
void loop() {

  // While there is data from the serial connection
  while (ss.available() > 0) {

    // Read a byte from the GPS serial
    byte gpsData = ss.read();
    // Output the byte to the serial monitor
    Serial.write(gpsData);

  }

}
