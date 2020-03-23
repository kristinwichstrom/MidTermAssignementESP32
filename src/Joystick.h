#include <Arduino.h>

class Joystick {

int inX ; // The joysticks x-axis
int inY; // The joysticks y-axis

int xValue;
int yValue;

public:

Joystick (int inX, int inY, int xValue, int yValue) {
    this->inX = inX;
    this->inY = inY;
    this->xValue = xValue;
    this->yValue = yValue;

pinMode (inX, INPUT);
  pinMode (inY, INPUT);
}
void readJoystick (){
xValue = analogRead (inX);
  yValue = analogRead(inY);

  Serial.print ("\n\t X: ");
  Serial.print (xValue);

  Serial.print ("\n\t Y: ");
  Serial.print (yValue);
}

    
};