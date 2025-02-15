#include "wifi_setup.h"
#include "display_handler.h"
#include "api_handler.h"
#include "ota_update.h"
#include "sleep_handler.h"
#include "button_handler.h"
#include "led.h"

void setup() {
    Serial.begin(115200);
    setUpLed();
    ledColorPlay(); //Rainbow
    setupWiFi();
    setupDisplay();
    setupOTA();
    setupButton();
    Serial.println("Setup complete!");
    etColor(0,0,0); //Grün
}

void loop() {
    static unsigned long lastFetch = -10000;
    const unsigned long fetchInterval = 10000;  // Fetch data every 10 sec
     
    if (millis() - lastFetch >= fetchInterval) {
        lastFetch = millis();
        JsonDocument doc1, doc2;
        setColor(0,0,0); //Grün

        if (fetchHaltestellenData(
                "http://widgets.vvo-online.de/abfahrtsmonitor/Abfahrten.do?hst=Oschatzer%20Straße&vz=5&ort=Dresden&lim=6",
                "http://widgets.vvo-online.de/abfahrtsmonitor/Abfahrten.do?hst=Liststraße&vz=5&ort=Dresden&lim=6",
                doc1, doc2)) {
            displayDepartures(doc1, doc2);
        }
    }

    handleButton();
    handleOTA();
    handleWakingup();
    breathingEffect();  //50 delay 20


}
