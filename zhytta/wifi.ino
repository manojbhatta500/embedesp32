#include "config.h"

void w_config_fill(Config &c){
    c.w_ssid = "EE-5KHZ6C";
    c.w_password = "JyQi43fRiRt3KTgJ";
}
bool connectWifi(){
  int attempts = 0;
  WiFi.mode(WIFI_STA);
  w_config_fill(appConfig);
  WiFi.begin(appConfig.w_ssid,appConfig.w_password);
  while(WiFi.status() != 3){
    delay(100);
    attempts ++;
    if(attempts > 30){
      return false;
    }
  }
  return true;
}