#include <WiFi.h>  


// WLAN-Konfiguration
const char* ssid = "";
const char* password = "";
  
  
void setupWiFi(){

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    Serial.println("\nWLAN verbunden!");
}