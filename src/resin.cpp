#include "resin.h"

Resin::Resin(){}
Resin::~Resin(){}

void Resin::Setup(String applicationUUID, String ssid, String password, bool led) {
    _applicationUUID = applicationUUID;
    _ssid = ssid;
    _password = password;
    _led = led;

    if (_led) {
        pinMode(LED_BUILTIN, OUTPUT);
        digitalWrite(LED_BUILTIN, HIGH);
    }

    WiFi.setAutoConnect(true);
    WiFi.setAutoReconnect(true);
    WiFi.begin(_ssid.c_str(), _password.c_str());
    while (WiFi.status() != WL_CONNECTED) {
        delay(100);
    }

    _httpServer = WiFiServer(80);
    _httpServer.begin();

    ArduinoOTA.begin();
}

void Resin::Loop() {
    Serve();

    ArduinoOTA.handle();

    if (_led) {
        if (WiFi.isConnected()) {
            digitalWrite(LED_BUILTIN, LOW);
        } else {
            digitalWrite(LED_BUILTIN, HIGH);
        }
    }
}

void Resin::Serve() {
    WiFiClient client = _httpServer.available();
    if (!client) {
        return;
    }

    while(client.connected() && !client.available()){
        delay(1);
    }

    String req = client.readStringUntil('\r');
    int addr_start = req.indexOf(' ');
    int addr_end = req.indexOf(' ', addr_start + 1);
    if (addr_start == -1 || addr_end == -1) {
        return;
    }

    req = req.substring(addr_start + 1, addr_end);
    client.flush();

    if (req == "/id") {
        client.print(_applicationUUID.c_str());
    }
}
