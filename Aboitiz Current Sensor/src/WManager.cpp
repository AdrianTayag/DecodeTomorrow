// Author: Cedric Velandres 

#include "WManager.h"

void setupWiFi(){
  Log("WManager: Starting WiFi");
  WiFi.mode(WIFI_AP_STA);
  WiFiMulti.addAP(Config.STA_SSID, Config.STA_PSK);
  LogVar(Config.STA_SSID);
  LogVar(Config.STA_PSK);

  if(WiFiMulti.run() == WL_CONNECTED) {
    Log("WManager: WiFi Connected");
  }

  if(MDNS.begin("current-sensor")){
    Log("WManager: MDSN Service Started");
  }

}

void sendRequest(){

  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  if (!client.connect(Config.publish_host, 80)) {
    Log("Failed to connect")
    return;
  }

  // We now create a URI for the request
  String url = Config.publish_uri;
  url += "?voltage=";
  url += voltageReading;
  url += "&current=";
  url += currentReading;
  LogVar(url);

  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + Config.publish_host + "\r\n" +
               "Connection: close\r\n\r\n");
  Log(url);
}
