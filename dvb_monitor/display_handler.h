#ifndef DISPLAY_HANDLER_H
#define DISPLAY_HANDLER_H
#include <Arduino.h>
#include <ArduinoJson.h>  // Ensure this is included

void setupDisplay();
void displayMessage(const char* message);
void clearDisplay();
void displayDepartures(JsonDocument& doc1, JsonDocument& doc2);
void displayStationNames(const char* name1, const char* name2);
#endif