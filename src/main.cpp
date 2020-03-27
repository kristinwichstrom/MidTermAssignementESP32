// -------- Includes the necessary classes and libraries ------------
#include <Arduino.h> 
#include <Button.h>  
#include <Potentiometer.h>
#include <Joystick.h>
 
const char * ssid = "Krisw";     
const char * password = "solbakk11"; 
 
int PIN_BUTTON = 23;
Button button (PIN_BUTTON); 
Potentiometer potentiometer(34);
Joystick joystick(36, 35);
 
void setup() {
      Serial.begin(9600);
      potentiometer.setSensitivity(50);
      WiFi.mode(WIFI_STA);
      WiFi.begin(ssid, password);
}
 
void loop() {
 
  button.notPressed();
  delay (300);
  joystick.movement();
  potentiometer.changePixelColor();
  
 
}