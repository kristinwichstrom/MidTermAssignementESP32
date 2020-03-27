#include <Arduino.h>
#include "WiFi.h"
#include "AsyncUDP.h"
#include "Button.h"
#include <Potentiometer.h>
#include <Joystick.h>

const char * ssid = "Krisw";     //Insert your wifi name
const char * password = "solbakk11"; //insert your wifi password

int PIN_BUTTON = 23;
Button button (PIN_BUTTON);
Potentiometer potentiometer(13);
AsyncUDP udp;

WiFiServer server(7000);

void setup() {
 Serial.begin(9600);
  potentiometer.setSensitivity(50);
  //WiFi.mode(WIFI_STA);
  //WiFi.begin(ssid, password);
}

void loop() {

  if (button.notPressed())
  {
    Serial.print ("");
  } 
  else
  {
    udp.broadcastTo("init 9 9", 7000);
  }
  delay (1000);

  potentiometer.loop();

  if (potentiometer.hasChanged()) 
  {
    Serial.println(potentiometer.color);
   //  udp.broadcastTo(potentiometer.color.c_str(), 7000);
  }
}
