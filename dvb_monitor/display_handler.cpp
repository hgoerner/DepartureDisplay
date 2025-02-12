#include "display_handler.h"
#include <GxEPD2_BW.h>
#include <Adafruit_GFX.h>

// Define the display
#define EINK_CS 5
#define EINK_DC 17
#define EINK_RST 16
#define EINK_BUSY 4

GxEPD2_BW<GxEPD2_290_T94_V2, GxEPD2_290_T94_V2::HEIGHT> display(GxEPD2_290_T94_V2(EINK_CS, EINK_DC, EINK_RST, EINK_BUSY));

void setupDisplay() {
    display.init();
    display.setRotation(1);
}

void displayMessage(const char* message) {
    display.setFullWindow();
    display.firstPage();
    do {
        display.fillScreen(GxEPD_WHITE);
        display.setCursor(10, 20);
        display.setTextColor(GxEPD_BLACK);
        display.setTextSize(1);
        display.println(message);
    } while (display.nextPage());
}

void clearDisplay() {
    display.setFullWindow();
    display.firstPage();
    do {
        display.fillScreen(GxEPD_WHITE);
    } while (display.nextPage());
}
