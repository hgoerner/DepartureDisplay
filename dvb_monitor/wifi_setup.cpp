#include "wifi_setup.h"
#include <WiFi.h>

const char* ssid = "";
const char* password = "";

void setupWiFi() {
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi connected!");
}
