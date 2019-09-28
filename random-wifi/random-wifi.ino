/* 
 *  Chris Reichert, 2019
 *  
 *  This creates a wifi access point with a random SSID and password
 *  
 *  Board type = ESP32
 */

#include <WiFi.h>
//#include <WiFiAP.h>
#include <Wire.h>
#include "SSD1306Wire.h"

// for initial functionality, hard code the SSID and no password
const char *ssid = "myAP";
const char *password = "mypassword12345";

SSD1306Wire display(0x3c, 4, 15);

void setup() {
  // put your setup code here, to run once:

  pinMode(16, OUTPUT);
  digitalWrite(16, 1);

  display.init();

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);

  Serial.begin(115200);

  Serial.println("Starting Soft-AP");

  if (WiFi.softAP(ssid, password, 1, 0, 2)) {
    Serial.println("Soft-AP started");

    Serial.print("SSID: ");
    Serial.println(ssid);
  }

  IPAddress apIP = WiFi.softAPIP();
  
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(0,10,"AP Started...");
  display.drawString(0,20,"SSID: ");
  display.drawString(30,20,ssid);
  display.drawString(0,30,"Password: ");
  display.drawString(0,40,password);
  display.drawString(0,50,"AP IP: " + String(apIP[0]) + "." + String(apIP[1]) + "." + String(apIP[2]) + "." + String(apIP[3]));

  display.display();

}

void loop() {
  // put your main code here, to run repeatedly:

}
