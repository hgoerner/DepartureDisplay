#ifndef API_HANDLER_H
#define API_HANDLER_H

#include <ArduinoJson.h>  // Ensure this is included

bool fetchHaltestellenData(const char* url1, const char* url2, JsonDocument& doc1, JsonDocument& doc2);

#endif