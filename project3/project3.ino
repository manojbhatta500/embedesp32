#define led 2
#define ioo 0



void setup(){
 pinMode(led,OUTPUT);
 pinMode(ioo,INPUT_PULLUP);
 Serial.begin(115200);
}

 int ioo_Counter = 0;

void loop(){
      full_cycle_up(led);
      delay(1000);
      full_cycle_down(led);
}


void full_cycle_up(int ledNo){
  for(int i = 0;i<255;++i){
    analogWrite(ledNo,i);
    delay(10);
  }
}

void full_cycle_down(int ledNo){
  for(int i = 255; i>0;i--){
    analogWrite(ledNo,i);
    delay(10);
  }
}

void plus_counter(int input){
  ioo_Counter = ioo_Counter + 1;
}

void display_counter(){
  Serial.print("current counter : ");
  Serial.print(ioo_Counter);
  Serial.println(" ");
}

void analyze_Counter(int i){
  if(i?)

}


