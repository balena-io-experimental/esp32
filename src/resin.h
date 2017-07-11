#include <Arduino.h>
#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

#ifndef Resin_H
#define Resin_H

#define LED_BUILTIN 13

class Resin {
    public:
        Resin();
        ~Resin();

        void Setup(String applicationUUID, String ssid, String password, bool led=true);
        void Loop();

    private:
        void Serve();

        WiFiServer _httpServer;

        String _applicationUUID;
        String _ssid;
        String _password;
        bool _led;
};

#endif
