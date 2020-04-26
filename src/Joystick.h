/*
The Joystick class 
*/

#include <Arduino.h>
#include "Connector.h"

class Joystick {

/*
Initializes the variables for the X and Y pin
*/
public:
  int pinX;
  int pinY;
  int currentX;
  int currentY;
  Connector connect; //Calls the Connector class 

/*
* Initializes and creates a constructor for the Joystick class
*/
  Joystick (int pinX, int pinY) { 
      this-> pinX = pinX;
      this-> pinY = pinY;
      pinMode (pinX, INPUT);
      pinMode (pinY, INPUT);
  }
/*
movement method checks X and Y value and and sends commands to the pxlserver using the broadcast method from the Connector class
*/
  void movement(){

    //connect.broadcast("speed 8");
    currentX = analogRead(pinX);
    currentY = analogRead(pinY);

    //-------Prints to terminal-------
    Serial.print("X: ");
    Serial.println(analogRead(pinX));
    Serial.print("Y: ");
    Serial.println(analogRead(pinY));

/*
When using 3,5 volt, center is between 1700-1850
*/

   /* if(currentX == 0){ //When the joystick is pushed completely to the left, the pixel will move left
      connect.broadcast("moveleft");
    } else if(currentX == 4095){ //When the joystick is pushed completely to the right, the pixel will move right
        connect.broadcast("moveright");
    } else if(currentY == 0){ //When the joystick is pushed completely up, the pixel will move up
       connect.broadcast("moveup");
    } else if(currentY == 4095){ //When the joystick is pushed completely down, the pixel will move down
        connect.broadcast("movedown");
    } else {
        connect.broadcast("stop");
    }*/
if (currentX>1500 && currentX <1900 && currentY > 1500 && currentY <1900){
connect.broadcast ("stop");
} 
    else if(currentX > 1900){
      connect.broadcast("moveright");
    }else if(currentX < 1500){
      connect.broadcast("moveleft");
    }
    if(currentY > 1900){
      connect.broadcast("moveup");
    } else if(currentY < 1500){
      connect.broadcast("movedown");
    }  
  } 
};
