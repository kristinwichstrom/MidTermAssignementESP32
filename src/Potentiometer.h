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
   
 
        Potentiometer(int pinNumber)
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
         
        void changePixelColor()
        {
            Serial.println("before has changed");
            if (this->hasChanged())
            {
                currentRead = readPotentiometer();
                Serial.print(analogRead(pinNumber));
 
                if (currentRead <=1356 )
                {  
                    Serial.println("Red");
                    connect.broadcast("color 255 0 0");
                    //connector.broadcast("color 255 0 0");
                }
                else if(currentRead > 1356 && currentRead <= 2712)
                {
                    connect.broadcast("color 0 255 0");
                    //connector.broadcast("color 0 255 0");
               
                }
                 else
                {
                    connect.broadcast("color 0 0 255");
                    //connector.broadcast("color 0 0 255");
                }
            }
        }
};