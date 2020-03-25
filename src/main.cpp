#include <Arduino.h>
#include <Potentiometer.h>

Potentiometer potentiometer(13);

void setup() {
  potentiometer.setSensitivity(50);
  potentiometer.setInfo("INFORMATION!!!");
  potentiometer.setWarning("WARNING!!!!!");

  Serial.begin(9600);

  delay(2000);
  Serial.println(potentiometer.readPotentiometer());


}

void loop() {
  potentiometer.loop();
  
  if (potentiometer.hasChanged()) {
    Serial.println(potentiometer.readPotentiometer());
  }
  
}
