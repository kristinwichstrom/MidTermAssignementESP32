#include <Arduino.h>

class Potentiometer{
    public:
        int pinNumber;
        int lastRead;
        int currentRead;
        int sensitivity;
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
            //Serial.println(analogRead(pinNumber));
            //Serial.println(abs(lastRead-analogRead(pinNumber)));
            return abs(lastRead-analogRead(pinNumber)) > sensitivity;
        }
         void setColor(String message)
       {
           this -> color = message;
       }
       
        void loop()
        {
            Serial.println("BEFORECHANGED");
            if (this->hasChanged())
            {
                currentRead = readPotentiometer();
                Serial.println("READ: ");
                Serial.print(analogRead(pinNumber));


                if (currentRead <=1356 )
                {
                    setColor("color 255 0 0");
                }
                else if(currentRead > 1356 && currentRead <= 2712)
                {
                    setColor("color 0 255 0");
                }
                 else
                {
                    setColor("color 0 0 255");
                }
            }
        }
};