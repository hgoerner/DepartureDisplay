#include "wifi_setup.h"
#include "display_handler.h"
#include "ota_update.h"
#include "sleep_handler.h"
#include "button_handler.h"

void setup() {
    Serial.begin(115200);

    setupWiFi();         // Connect to WiFi
    setupDisplay();      // Initialize the e-ink display
    setupOTA();          // Initialize OTA updates
    setupSleep();        // Configure deep sleep
    setupButton();       // Configure button press handling

    Serial.println("Setup complete!");
}

void loop() {
    handleSleep();       // Check if it's time to sleep
    handleButton();      // Check button press for wake-up
    handleOTA();         // Handle OTA updates
}