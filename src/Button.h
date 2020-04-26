#include <Arduino.h>
#include "Connector.h"


class Button {

int buttonPin;
        Connector connect; //Calls the Connector class 
        
    public: 

    Button (int buttonPin) { //Creates a constructor for the Button class
        this->buttonPin = buttonPin;
        pinMode(buttonPin, INPUT_PULLUP);
    }

/*
* Method checks whether button is pressed or not.
*/
    void buttonPressed (){
        if(digitalRead(buttonPin)){
                Serial.println("Not pressed");
        }else{
            Serial.println("Pressed");
            connect.broadcast("init 200 200");
        }
    }
};