#include <Arduino.h>
#include "config.h"
#include "WiFi.h"
#include "PubSubClient.h"
#include <WiFiClientSecure.h>

WifiConfig wifiCred ;
HiveConfig hivecred ;

void setupWifi(WifiConfig* w){
    w->ssid = "EE-5KHZ6C";
    w->password = "JyQi43fRiRt3KTgJ";
}


void setupHive(HiveConfig* h){
    h->broker_url = "1eb3f284c50d43248444cbd5f38ef729.s1.eu.hivemq.cloud";
    h->port = 8883;
    h-> username = "manoj12";
    h->password = "3uJC6SP95!tPkzK";
    h->topic = "/example";
}

WiFiClientSecure espClient;     
PubSubClient client(espClient);

void connectHive(HiveConfig* hc){
  espClient.setInsecure();      
  client.setServer(hc->broker_url,hc->port);
  
  if(client.connect("ESP32",hc->username,hc->password)){
    Serial.println("mqtt connected successfully");
  }else{
    Serial.println("failed connecting to hive");
  }
}

void publishMessage(const char* topic,const char* message){
  if(client.connected()){
    client.publish(topic,message);
    Serial.println("published data");
  }else{
    Serial.println("failed to publish data ");
  }
}


void connectWifi(WifiConfig* w){
  WiFi.mode(WIFI_STA);
  WiFi.begin(w->ssid,w->password);
  while(WiFi.status() != WL_CONNECTED){
    Serial.println("wifi is not connected");
    delay(100);
  }
  Serial.println("wifi is connected");
}




void setup() {
  Serial.begin(115200);
  delay(1000);
  setupWifi(&wifiCred);
  setupHive(&hivecred);
  connectWifi(&wifiCred);

  connectHive(&hivecred);
}

void loop() {
  client.loop();

  // publishMessage("/example","20.32432 , 3.1231");
  delay(500);
  // if(client.connected()){
  //   Serial.println("mqtt is conneted inside loop");
  // }else{
  //   Serial.println("mqtt not connected");
  // }

  // if(WiFi.status() == WL_CONNECTED){
  //   Serial.println(WiFi.status());
  // }else{
  //   Serial.println("wifi is not conneted ");
  // }
}

