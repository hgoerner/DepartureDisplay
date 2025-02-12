#ifndef DISPLAY_HANDLER_H
#define DISPLAY_HANDLER_H

void setupDisplay();
void displayMessage(const char* message);
void clearDisplay();
void fetchAndDisplayHaltestellen(const char* url1, const char* name1, const char* url2, const char* name2);

#endif