#include <Arduino.h>

class Potentiometer{
    public:
        int pinNumber;
        int lastRead;
        int currentRead;
        int sensitivity;
        String color = "DEFAULT COLOR";
    

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
            Serial.println(abs(lastRead-analogRead(pinNumber)));
            return abs(lastRead-analogRead(pinNumber)) > sensitivity;
        }
         void setColor(String message)
       {
           this -> color = message;
       }
       
        void settingColor()
        {
            if (this->hasChanged())
            {
                currentRead = readPotentiometer();

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
               
              /*  int digiRead = digitalRead(this->pinNumber);
               
                if (this->hasChanged() && digiRead <= 1356)
             {
                    Serial.println(this->infoMessage);
                }
                else if (this->hasChanged() && digiRead > 1356)
                {
                Serial.println(this->infoMessage);
                }
                else {
                    Serial.println(this->infoMessage);
                }*/
            }
        }
};