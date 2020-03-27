#include <Arduino.h>
#include "Connector.h"


class Button {

int buttonPin;
        Connector connect;


    public: //constructor   
    Button (int buttonPin) {
        this->buttonPin = buttonPin;
        pinMode(buttonPin, INPUT_PULLUP);
    }

    void notPressed (){
        if(digitalRead(buttonPin)){
                Serial.println("Not pressed");
        }else{
            Serial.println("Pressed");
            connect.broadcast("init 9 9");
        }
    }
};