/* 
 *  Chris Reichert, 2019
 *  
 *  This creates a wifi access point with a random SSID and password
 *  
 *  Board type = ESP32
 */

#include <WiFi.h>
#include <WiFiAP.h>

// for initial functionality, hard code the SSID and no password
const char *ssid = "myAP";

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);

  Serial.println("Starting Soft-AP");

  if (WiFi.softAP(ssid)) {
    Serial.println("Soft-AP started");

    Serial.print("SSID: ");
    Serial.println(ssid);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
