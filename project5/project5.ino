#define button 13 
#define led 2
void setup(){
  pinMode(button,INPUT_PULLUP);
  pinMode(led,OUTPUT);
  Serial.begin(115200);
}
bool ledState = false;

void loop(){
  if(digitalRead(button) == LOW ){
    Serial.println("the button is pressed");
    ledState = !ledState;
    digitalWrite(led,ledState);
    delay(50);  
    while(digitalRead(button)== LOW);
  }else{
    digitalWrite(led,ledState);
  }
}
