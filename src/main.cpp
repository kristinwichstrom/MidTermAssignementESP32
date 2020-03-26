#include <Arduino.h>
#include "WiFi.h"
#include "AsyncUDP.h"
#include "Button.h"
#include <Potentiometer.h>


const char * ssid = "Krisw";     //Insert your wifi name
const char * password = "solbakk11"; //insert your wifi password

int PIN_BUTTON = 23;
Button button (PIN_BUTTON);
Potentiometer potentiometer(13);
AsyncUDP udp;

void setup() {
 
  potentiometer.setSensitivity(100);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.begin(9600);

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
  //delay (300);
  potentiometer.settingColor();
  if (potentiometer.hasChanged()) 
  {
    udp.broadcastTo(potentiometer.color.c_str(), 7000);

  }
}
