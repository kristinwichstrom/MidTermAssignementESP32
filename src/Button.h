#include <Arduino.h>

class Button {
int _buttonPin;


    public: //constructor   
    Button (int buttonPin) {
        _buttonPin = buttonPin;
        pinMode(_buttonPin, INPUT_PULLUP);
    }

    bool notPressed (){
        return digitalRead(_buttonPin);
    }
};