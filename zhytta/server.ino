#include <ArduinoJson.h>

void startServer(){
  server.begin();
}

bool shouldOpenServer(){
  state.isRunning = true;
  return state.isRunning;
}



void handleRoot(){
  jsonDocument doc;
  doc["statuscode"] = 200;
  doc["data"] = "esp32  is working";
  String output;
  serializeJson(doc,output);
  server.send(200,"application/json",output);
}

void handleLed(){
  String body = server.arg("plain");
  if(body.isEmpty()){
  server.send(400, "application/json", "{\"error\":\"empty body\"}");
  return;
  }
  jsonDocument doc;
  deserializeJson(doc,body);
  int ledpin = doc["ledpin"];
  bool action = doc["action"];

  

}


void noRoutesFound(){
  char* jsonResponse = "{\"statusCode\" : 404 ,\"data\": \"This route does not exist.\"}";
  server.send(200,"application/json",jsonResponse);

}
