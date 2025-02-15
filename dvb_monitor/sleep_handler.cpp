#include "sleep_handler.h"
#include <Arduino.h>  
#include "display_handler.h"
#include <esp_sleep.h>

void handleSleep() {
    static unsigned long previousMillisSleep = 0;
    const unsigned long sleepInterval = 300000;  // 5 minutes (300,000 ms)

    if (millis() - previousMillisSleep >= sleepInterval) {
        Serial.println("Going to deep sleep after 5 min");
        displayMessage("Going to deep sleep after 5 min");
        delay(1000);
        previousMillisSleep = millis();  // ✅ Update the last sleep time
        goToDeepSleep();
    }
}

void goToDeepSleep() {
    //esp_light_sleep_start();
    esp_deep_sleep_start();
}
