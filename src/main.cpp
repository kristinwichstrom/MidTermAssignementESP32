
// -------- Includes the necessary classes and libraries ------------
#include <Arduino.h> 
#include <Button.h>  
#include <Potentiometer.h>
#include <Joystick.h>
 
const char * ssid = "Your wifi name"; //Insert your wifi name
const char * password = "Your password"; //Insert your wifi password
 
 /*
 * Sets the pinNumbers for the different sensors.
 */
int PIN_BUTTON = 23;
Button button (PIN_BUTTON); 
Potentiometer potentiometer(34); 
Joystick joystick(36, 35);

 void setup() {
      Serial.begin(9600);
      WiFi.mode(WIFI_STA);
      WiFi.begin(ssid, password);
      potentiometer.setSensitivity(50);   // Sets the sensitivity
}
/*
* The loop function constineuosly looks for updates and calls the button, joystick and potentiometer functions if there are any.
*/
void loop() {
  delay(300);
  button.buttonPressed();
  delay(300);
  joystick.movement();
  potentiometer.changePixelColor();
  
 
}