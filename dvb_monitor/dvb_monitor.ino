#include "wifi_setup.h"
#include "display_handler.h"
#include "api_handler.h"
#include "ota_update.h"
#include "sleep_handler.h"
#include "button_handler.h"

void setup() {
    Serial.begin(115200);

    setupWiFi();
    setupDisplay();
    setupOTA();
    setupButton();
    Serial.println("Setup complete!");

    
}

void loop() {
    static unsigned long lastFetch = 0;
    const unsigned long fetchInterval = 60000;  // Fetch data every 30 sec

    if (millis() - lastFetch >= fetchInterval) {
        lastFetch = millis();
        JsonDocument doc1, doc2;


        if (fetchHaltestellenData(
                "http://widgets.vvo-online.de/abfahrtsmonitor/Abfahrten.do?hst=Oschatzer%20Straße&vz=5&ort=Dresden&lim=10",
                "http://widgets.vvo-online.de/abfahrtsmonitor/Abfahrten.do?hst=Liststraße&vz=5&ort=Dresden&lim=10",
                doc1, doc2)) {
            displayDepartures("Oschatzer Strasse", "Liststrasse", doc1, doc2);
        }
    }

    handleButton();
    handleOTA();
    handleWakingup();
}
