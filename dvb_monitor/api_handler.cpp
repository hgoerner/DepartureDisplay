#include "api_handler.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>  // Ensure this is included

bool fetchHaltestellenData(const char* url1, const char* url2, 
                           JsonDocument& doc1, 
                           JsonDocument& doc2) {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("WiFi not connected!");
        return false;
    }

    HTTPClient http1, http2;
    http1.begin(url1);
    http2.begin(url2);

    int httpCode1 = http1.GET();
    int httpCode2 = http2.GET();

    if (httpCode1 == 200 && httpCode2 == 200) {
        String payload1 = http1.getString();
        String payload2 = http2.getString();

        DeserializationError error1 = deserializeJson(doc1, payload1);
        DeserializationError error2 = deserializeJson(doc2, payload2);

        http1.end();
        http2.end();

        if (error1 || error2) {
            Serial.println("JSON Parsing Error");
            return false;
        }
        return true;
    } else {
        Serial.printf("HTTP Error: %d (URL1), %d (URL2)\n", httpCode1, httpCode2);
        http1.end();
        http2.end();
        return false;
    }
}
