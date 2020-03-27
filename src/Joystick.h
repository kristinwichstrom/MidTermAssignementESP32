#include <Arduino.h>

class Joystick {

public:
int pinX;
int pinY;
int currentX;
int currentY;

Joystick (int inX, int inY) {
  this-> pinX = pinX;
  this-> pinY = pinY;
pinMode (inX, INPUT);
  pinMode (inY, INPUT);
}

String movementMessage (String move){

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
}

void loop(){
  currentX = analogRead(pinX);
  currentY = analogRead(pinY);

  if(currentX > 3000){
    return "moveRight"
  }

}
    
};
