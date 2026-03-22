#define led 2
#define ioo 0



void setup(){

  pinMode(led,OUTPUT);
  pinMode(ioo,INPUT_PULLUP);
}

void loop(){
  if(digitalRead(ioo)== LOW){
    digitalWrite(led,HIGH);
  }else{
    digitalWrite(led,LOW);
  }

  // sleep(10);
}