#include <Arduino.h>
#include "WiFi.h"
#include "AsyncUDP.h"
#include "Button.h"

const char * ssid = "Krisw";     //Insert your wifi name
const char * password = "solbakk11"; //insert your wifi password

int PIN_BUTTON = 23;
Button button (PIN_BUTTON);

AsyncUDP udp;

void setup() {

   Serial.begin(9600);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

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
  delay (300);
}
