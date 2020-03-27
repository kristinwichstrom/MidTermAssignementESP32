#ifndef CONNECTOR_H   //Guards the file against double definition. Makes it idempotent
#define CONNECTOR_H
#include "Arduino.h"
#include "WiFi.h" 
#include "AsyncUDP.h"
 
 
class Connector{
 
   
    public:
        const char * ssid = "Krisw";     //Insert your wifi name
        const char * password = "solbakk11"; //insert your wifi password
        AsyncUDP udp;
        int port = 7000;
       
 
        Connector () {
            WiFi.mode(WIFI_STA);
            WiFi.begin(ssid, password);
        }
 
        void broadcast(String message){
            udp.broadcastTo(message.c_str(), port);
        }
 
     
 
 
};
 
#endif