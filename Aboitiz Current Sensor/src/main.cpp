// Author: Cedric Velandres 

#include <Arduino.h>
#include "Config.h"
#include "WManager.h"
#include <ESP8266TrueRandom.h>

Ticker toggleMeasure;
volatile bool measureFlag= false;


void toggleMeasureFlag(){
  if(!measureFlag){
    measureFlag=true;
  }
}

void dataRead(){
  currentReading = (((analogRead(ADC_CURRENT_PIN)-currentOffset)*5/1024) - currentReading) * EMA_FACTOR;
  voltageReading = (((analogRead(ADC_VOLTAGE_PIN))*5/1024) - voltageReading) * EMA_FACTOR;

  LogVar(currentReading);LogVar(voltageReading);
}

void setup() {
    Serial.begin(115200);
    Serial.println("");
    setupWiFi();

    // pinMode(4,INPUT);
    Log("Attach Timers");
    toggleMeasure.attach(Config.measureInterval,toggleMeasureFlag);
}

void loop() {
  if((WiFi.status() != WL_CONNECTED)){
    Log("Connecting");
    WiFiMulti.run();
  }

    if(measureFlag){
      if((WiFi.status() == WL_CONNECTED)){
        Log("Measure Flag triggered");
        dataRead();
        sendRequest();
      }
      measureFlag=false;
    }

    // Housekeeping tasks here
}
