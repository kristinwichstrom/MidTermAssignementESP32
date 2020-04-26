#include <Arduino.h>
#include "Connector.h"
 
 
 
class Potentiometer{
    public:
        int pinNumber;
        int lastRead;
        int currentRead;
        int sensitivity;
        Connector connect;
        String color = "";
   
 
        Potentiometer(int pinNumber) // Constructor for the Potentiometer class
        {
            this->pinNumber = pinNumber;
            pinMode(pinNumber, INPUT);
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
        bool hasChanged()
        {
            return abs(lastRead-analogRead(pinNumber)) > sensitivity;
        }
         /*
         * changePixelColor method checks the currentRead and sets individual commands representing red, green and blue color.
         */
        void changePixelColor()
        {
            if (this->hasChanged())
            {
                currentRead = readPotentiometer();
                Serial.print(analogRead(pinNumber));
 
                if (currentRead <=1356 )
                {  
                    connect.broadcast("color 255 0 0");
                }
                else if(currentRead > 1356 && currentRead <= 2712)
                {
                   connect.broadcast("color 0 255 0");
               
                }
                 else
                {
                    connect.broadcast("color 0 0 255");
                    
                }
            }
        }
};  