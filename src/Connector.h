#ifndef CONNECTOR_H   //Guards the file against double definition. Makes it idempotent
#define CONNECTOR_H
#include "Arduino.h"
#include "WiFi.h" 
#include "AsyncUDP.h"
 
 
class Connector{
 
    public:
        const char * ssid = "Your wifi name"; //Insert your wifi name
        const char * password = "Your password"; //Insert your wifi password
        AsyncUDP udp;
        int port = 8000;
       
 
        Connector () {
            WiFi.mode(WIFI_STA);
            WiFi.begin(ssid, password);
        }
 /*
 * broadcast method takes message as an argument. c_str parses the message to a char array, which is needed for broadcastTo to work
 */
        void broadcast(String message){
            
        udp.broadcastTo(message.c_str(), port);
        }
};
 
#endif