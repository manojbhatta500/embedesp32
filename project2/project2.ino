#define led 2
#define ioo 0

void setup(){
pinMode(led,OUTPUT);
pinMode(ioo,INPUT_PULLUP);
Serial.begin(115200);
}

void loop(){
  if(digitalRead(ioo) == LOW){
  shortCode(led);
  longCode(led);
  shortCode(led); 
  }else{
    Serial.println("the button state is high. please press the button");
  }
        
}
     
void shortCode(int ledNO){
  for(int i = 0;i<3;++i){
  digitalWrite(ledNO,HIGH);
  delay(1000);
  digitalWrite(ledNO,LOW);
  delay(800);
  }
  delay(2000);
}

void longCode(int ledNO){
  for(int i = 0;i<3;++i){
  digitalWrite(ledNO,HIGH);
  delay(2000);
  digitalWrite(ledNO,LOW);
  delay(1500);
  
  }
  delay(2000);
}

