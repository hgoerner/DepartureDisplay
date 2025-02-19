#include "ota_update.h"
#include <ArduinoOTA.h>
#include <WiFi.h>

void setupOTA() {
    ArduinoOTA.begin();
    Serial.println("OTA ready!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}

void handleOTA() {
    ArduinoOTA.handle();
}