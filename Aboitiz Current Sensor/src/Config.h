// Author: Cedric Velandres 

#ifndef CONFIG_H
#define CONFIG_H

#define FS_NO_GLOBALS

#include <stdarg.h>
#include <Arduino.h>
#include <ArduinoJson.h>
#include <Ticker.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266httpUpdate.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

//-------------------------------------
#define C_BUILD_NO "01"
#define C_PUBLISH_HOST "192.168.168.26"
#define C_PUBLISH_PORT "80"
#define C_PUBLISH_URI "/php/publish.php"
#define C_STA_SSID "Aboitiz Hackathon"
#define C_STA_PSK "AHACK@2018"
#define C_MEASUREMENT_INTERVAL 2

#define ADC_CURRENT_PIN A0
#define ADC_VOLTAGE_PIN A1
#define C_CURRENT_OFFSET 512
#define EMA_FACTOR .5

//-------------------------------------
#define DEBUG
#ifdef DEBUG
#define Log(x)  Serial.println(x);
#define LogVar(var) Serial.print(#var ": "); Serial.println(var)
#else
#define LogVar(var) ;
#define Log(x) ;
// #define Serial.begin(x) ;
#endif

extern ESP8266WiFiMulti WiFiMulti;
extern ESP8266WebServer WFserver;
extern struct Config Config;
extern float currentReading;
extern float voltageReading;
extern int currentOffset;

struct Config {
  uint8_t status = 0;
  char BUILD_NO[8] = C_BUILD_NO;

  char publish_host[16] = C_PUBLISH_HOST;
  char publish_port[4] = C_PUBLISH_PORT;
  char publish_uri[32] = C_PUBLISH_URI;

  char STA_SSID[32] = C_STA_SSID;
  char STA_PSK[16] = C_STA_PSK;

  uint32_t measureInterval = C_MEASUREMENT_INTERVAL;
};




#endif
