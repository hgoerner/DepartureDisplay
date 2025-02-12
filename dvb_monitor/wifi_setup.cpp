#include "wifi_setup.h"
#include <WiFi.h>

const char* ssid = "FRITZ!Box 7590 WO";
const char* password = "1337Moritzburger26!";

void setupWiFi() {
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi connected!");
}