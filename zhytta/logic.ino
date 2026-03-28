void lightOn(int pin){
  digitalWrite(pin,HIGH);
}

void lightOff(int pin){
  digitalWrite(pin,LOW);
}

void serverLogs(String message){
  Serial.println(message);
}