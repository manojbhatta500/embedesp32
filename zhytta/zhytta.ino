#include <WiFi.h>
#include <WebServer.h>
#include "config.h"

#define led 2
#define server_button 13


// constant values 
WebServer server(80);
Config appConfig;
AppState state;




void setup(){  
  Serial.begin(115200);
  pinMode(led,OUTPUT);
  state.ledPin = led ;
  bool wifi_conn_result = connectWifi();
  if(wifi_conn_result == true){
    Serial.println("wifi is connected;");
    Serial.println(WiFi.localIP());
    Serial.println("------------------");

    server.on("/",handleRoot);
    server.on("/led",HTTP_POST,handleLed);
    server.onNotFound(noRoutesFound);
    startServer(); 
  }else{
    Serial.println("wifi is not connected;");
  }
}

void loop(){
  bool result = shouldOpenServer();
  if(result == true ){
    server.handleClient();  
  }else{  
   Serial.println("server is off"); 
  }   
}



