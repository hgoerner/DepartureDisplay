#include "sleep_handler.h"
#include <Arduino.h>  // This fixes 'millis()' not declared
#include "display_handler.h"
#include <esp_sleep.h>

#define SLEEP_DURATION 300000000ULL  // Microseconds

void setupSleep() {
    esp_sleep_enable_timer_wakeup(SLEEP_DURATION);
}

void handleSleep() {
    static unsigned long previousMillisSleep = 0;
    const unsigned long sleepInterval = 300000;  // 5 minutes

    if (millis() - previousMillisSleep >= sleepInterval) {
        Serial.println("Going to deep sleep...");
        displayMessage("Going to sleep...");
        delay(1000);
        clearDisplay();
        goToDeepSleep();
    }
}

void goToDeepSleep() {
    esp_deep_sleep_start();
}
