#include <Arduino.h>

class Potentiometer {
    public:
    int pinNumber;
    int lastRead;
    int sensitivity;
    int color;

    int redVal = 0;   // Variables to store the values to send to the pins
    int grnVal = 0;
    int bluVal = 0;

Potentiometer (int pinNumber)
{
 this -> pinNumber = pinNumber;   
 pinMode (pinNumber, INPUT);
 this->lastRead = this->readPotentiometer();
}
int readPotentiometer()
        {
            return analogRead(pinNumber);
        }
 void setSensitivity(int sensitivity)
        {
            this->sensitivity = sensitivity;
        }
void setColor(int color)
{
    
this->color = color;
}
    bool hasChanged()
        {
            return abs(lastRead-analogRead(pinNumber)) > sensitivity;
        }



};