
#include <Arduino.h>
#include <GxEPD2_BW.h>
#include <Adafruit_GFX.h>
#include "display_handler.h"


#define EINK_CS 5
#define EINK_DC 17
#define EINK_RST 16
#define EINK_BUSY 4

const char* station1 = "Oschatzer Strasse";
const char* station2 = "Liststrasse";

GxEPD2_BW<GxEPD2_290_T94_V2, GxEPD2_290_T94_V2::HEIGHT> display(GxEPD2_290_T94_V2(EINK_CS, EINK_DC, EINK_RST, EINK_BUSY));

void displayStationNames(const char* name1, const char* name2) {
    display.setFullWindow();
    display.firstPage();
    do {
        display.fillScreen(GxEPD_WHITE);
        display.setTextColor(GxEPD_BLACK);
        display.setTextSize(1);

        // **Stationsnamen einmalig anzeigen**
        display.setCursor(10, 10);
        display.println(name1);
        display.setCursor(158, 10);
        display.println(name2);

        // **Linien für das Layout**
        display.drawLine(0, 30, 295, 30, GxEPD_BLACK);
        display.drawLine(148, 0, 148, 295, GxEPD_BLACK);

    } while (display.nextPage());

    display.hibernate();
}

void setupDisplay() {
    display.init();
    display.setRotation(1);
    displayStationNames(station1, station2);
}

void displayMessage(const char* message) {
    display.setPartialWindow(0, 0, display.width(), display.height());
    display.firstPage();
    do {
        display.fillScreen(GxEPD_WHITE);
        display.setCursor(10, 20);
        display.setTextColor(GxEPD_BLACK);
        display.setTextSize(3);
        display.println(message);
    } while (display.nextPage());
}

void displayDepartures(JsonDocument& doc1, JsonDocument& doc2) {
    display.setPartialWindow(0, 35, display.width(), display.height() - 35);  // Update nur Abfahrtsbereich
    display.firstPage();
    do {
        display.fillScreen(GxEPD_WHITE);
        display.setTextColor(GxEPD_BLACK);
        display.setTextSize(1);
        display.drawLine(0, 30, 295, 30, GxEPD_BLACK);
        display.drawLine(148, 0, 148, 295, GxEPD_BLACK);

        // Display departures for station 1
        int yPosition1 = 40;
        for (JsonArray departure : doc1.as<JsonArray>()) {
            if (yPosition1 > 280) break;
            
            String line = departure[0].as<String>();
            String direction = departure[1].as<String>();
            // Begrenze die Länge der Richtung auf 12 Zeichen
            if (direction.length() > 12) {
              direction = direction.substring(0, 12);
            }
            int minutes = departure[2].as<int>();
            display.setCursor(10, yPosition1);
            display.printf("%s %s %d m", line.c_str(), direction.c_str(), minutes);
            yPosition1 += 15;
        }

        // Display departures for station 2
        int yPosition2 = 40;
        for (JsonArray departure : doc2.as<JsonArray>()) {
            if (yPosition2 > 280) break;
            String line = departure[0].as<String>();
            String direction = departure[1].as<String>();
             // Begrenze die Länge der Richtung auf 12 Zeichen
            if (direction.length() > 12) {
              direction = direction.substring(0, 12);
            }
            int minutes = departure[2].as<int>();
            display.setCursor(158, yPosition2);
            display.printf("%s %s %d m", line.c_str(), direction.c_str(), minutes);
            yPosition2 += 15;
        }
    } while (display.nextPage());
}


void clearDisplay() {
    display.setFullWindow();
    display.firstPage();
    do {
        display.fillScreen(GxEPD_WHITE);
    } while (display.nextPage());
}