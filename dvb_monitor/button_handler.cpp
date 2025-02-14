#include "button_handler.h"
#include <Arduino.h>  // This fixes 'INPUT_PULLUP' error
#include "display_handler.h"
#include "sleep_handler.h"
#include "driver/rtc_io.h"

#define BUTTON_PIN 32
#define WAKEUP_PIN GPIO_NUM_33

void setupButton() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);  // No more error here
   
    esp_sleep_enable_ext0_wakeup(WAKEUP_PIN, 0);
    pinMode(WAKEUP_PIN, INPUT_PULLUP);
}

void handleButton() {
    if (digitalRead(BUTTON_PIN) == LOW) {
        Serial.println("Button pressed! Going to deep sleep...");
        displayMessage("Going to sleep...");
        delay(1000);
        clearDisplay();
        goToDeepSleep();
    }
}

void handleWakingup(){
    if (digitalRead(WAKEUP_PIN) == LOW) {
        Serial.println("Button pressed! Waking up...");
}
}
