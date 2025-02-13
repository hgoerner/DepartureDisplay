#ifndef DISPLAY_HANDLER_H
#define DISPLAY_HANDLER_H
#include <Arduino.h>
#include <ArduinoJson.h>  // Ensure this is included

void setupDisplay();
void displayMessage(const char* message);
void clearDisplay();
void fetchAndDisplayHaltestellen(const char* url1, const char* name1, const char* url2, const char* name2);
void displayDepartures(const char* name1, const char* name2, JsonDocument& doc1, JsonDocument& doc2);
#endif