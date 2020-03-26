/*#include <Arduino.h>

class Joystick {

public:
int pinX;
int pinY;
unsigned long currentMillis;
unsigned long previousMillis = 0;
int interval = 1000;

Joystick (int inX, int inY) {
  this-> pinX = pinX;
  this-> pinY = pinY;
pinMode (inX, INPUT);
  pinMode (inY, INPUT);
}

void movementMessage (String ){

}
void movingJoystick (int horizontal, int vertical){
    if(horizontal == 0){ 
       movementMessage("moveleft");
    } else if(horizontal == 4095){ 
        movementMessage("moveright"); 
    } else if(vertical == 0){ 
       movementMessage("moveup");
    } else if(vertical == 4095){
      movementMessage("movedown");
}
    
};
*/