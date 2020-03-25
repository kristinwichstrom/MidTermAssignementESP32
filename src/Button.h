#include <Arduino.h>

class Button {
int buttonPin;


    public: //constructor   
    Button (int buttonPin) {
        this->buttonPin = buttonPin;
        pinMode(buttonPin, INPUT_PULLUP);
    }

    bool notPressed (){
        return digitalRead(buttonPin);
    }
};