#include "Config.h"

ESP8266WiFiMulti WiFiMulti;
ESP8266WebServer WFserver(80);
struct Config Config;
float currentReading;
float voltageReading;
int currentOffset = C_CURRENT_OFFSET;
