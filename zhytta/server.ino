#include <ArduinoJson.h>

void startServer(){
  server.begin();
}

bool shouldOpenServer(){
  state.isRunning = is_server_button_pressed();
  return state.isRunning;
}

void toogleServer(){
  if(state.isRunning == true){
    state.isRunning = false;
  }else{
    state.isRunning = true;
  }
}

bool is_server_button_pressed(){
if(digitalRead(server_button) ==LOW){
  return true;
}else{
  return false;
}
}





void handleRoot(){
  JsonDocument doc;
  doc["statuscode"] = 200;
  doc["response"] = "esp32  is working";
  String output;
  serializeJson(doc,output);
  serverLogs("/ hitted");
  server.send(200,"application/json",output);
}

void sResponse(String message){
  JsonDocument doc;
  doc["statuscode"] = 200;
  doc["response"] = message;
  doc["success"] = true; 
  String output;
  serializeJson(doc,output);
  server.send(404,"application/json",output);
}


void eResponse(String message){
  JsonDocument doc;
  doc["statuscode"] = 404;
  doc["response"] = message;
  doc["success"] = false; 
  String output;
  serializeJson(doc,output);
  server.send(404,"application/json",output);
}

void handleLed(){
  String body = server.arg("plain");
  if(body.isEmpty()){
  server.send(400, "application/json", "{\"error\":\"empty body\"}");
  return;
  }
  JsonDocument doc;
  deserializeJson(doc,body);
  if (!doc["action"].is<bool>()) {
    serverLogs("action is not a boolean.");
    eResponse("wrong input. 'action' must be true or false.");
    return;
  }
  bool action = doc["action"];

  serverLogs("/led route hitted");

  serverLogs("/led action is " + String(action));

  if (action == true){
    serverLogs("action is true. led is on");
    lightOn(state.ledPin);
    sResponse("led is ON.");
  }else{
    serverLogs("action is false. led is off");
    lightOff(state.ledPin);
    sResponse("led is OFF.");
  }

}


void noRoutesFound(){
  char* jsonResponse = "{\"statusCode\" : 404 ,\"data\": \"This route does not exist.\"}";
  server.send(200,"application/json",jsonResponse);

}
