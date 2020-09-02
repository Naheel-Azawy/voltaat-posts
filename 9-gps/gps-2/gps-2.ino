/*
  Arduino Track location

  Tutorial link: https://www.learn.voltaat.com/post/gps

  This is an Arduino sketch that uses the TinyGPS library with the NEO-6M GPS module to output the longitude and latitude to the serial monitor

  Components Needed:
  NEO-6M GPS Module ...x1

  Connections:
  NEO-6M GND → Arduino pin GND
  NEO-6M Vcc → Arduino pin 5V
  NEO-6M Rx  → Arduino pin 3
  NEO-6M Tx  → Arduino pin 4

*/

#include <SoftwareSerial.h> // Software serial connection library
#include <TinyGPS++.h>      // NMEA parser library

#define GPS_RX 3 // GPS Rx pin
#define GPS_TX 4 // GPS Tx pin

// The serial connection to the GPS module
SoftwareSerial ss(GPS_TX, GPS_RX);

// The TinyGPS++ instance
TinyGPSPlus gps;

// Commands inside void setup run once
void setup() {

  Serial.begin(9600); // Start the serial monitor
  ss.begin(9600);     // Start the GPS software serial

  // Inform the serial monitor
  Serial.println("Searching for GPS location...");

}

// Commands inside void loop run forever
void loop() {

  // While there is data from the serial connection
  while (ss.available() > 0) {

    // Read a byte from the GPS serial and encode it
    gps.encode(ss.read());

    // Print the location once we get it
    if (gps.location.isUpdated()) {
      Serial.print("Latitude: ");
      Serial.print(gps.location.lat());
      Serial.print(" Longitude: ");
      Serial.println(gps.location.lng());
    }

  }

}
