#include <Arduino.h>
#include "Connector.h"

class Joystick {

public:
  int pinX;
  int pinY;
  int currentX;
  int currentY;
  Connector connect;

  Joystick (int pinX, int pinY) {
    this-> pinX = pinX;
    this-> pinY = pinY;
    pinMode (pinX, INPUT);
    pinMode (pinY, INPUT);
  }

  void movement(){
    delay(3000);
    connect.broadcast("speed 8");

    currentX = analogRead(pinX);
    currentY = analogRead(pinY);
    Serial.print("X: ");
    Serial.println(analogRead(pinX));
    Serial.print("Y: ");
    Serial.println(analogRead(pinY));

    if(currentX > 3000){
      connect.broadcast("moveright");
    }else if(currentX < 1000){
      connect.broadcast("moverleft");
    }
    if(currentY > 3000){
      connect.broadcast("moveup");
    } else if(currentY < 1000){
      connect.broadcast("movedown");
    }
  }
    
};
