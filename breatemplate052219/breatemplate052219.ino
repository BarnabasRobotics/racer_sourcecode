#include <Servo.h>
Servo LM;
Servo RM;

void go(){
  LM.write(180);
  RM.write(0);
}

void halt(){
  LM.write(90);
  RM.write(90);
}

void left(){
  LM.write(180);
  RM.write(180);
}

void right(){
  LM.write(0);
  RM.write(0);
}

void back(){
  LM.write(0);
  RM.write(180);
}

int getdistance(){
  long duration;
  digitalWrite(3,LOW);
  delayMicroseconds(2);
  digitalWrite(3,HIGH);
  delayMicroseconds(20);
  digitalWrite(3,LOW);
  duration=pulseIn(4,HIGH);
  duration=duration/59;
  if ((duration<2) || (duration>300)) return false;
  return duration;
}

void setup() {
  LM.attach(9);
  RM.attach(10);
  pinMode(3,OUTPUT);
  pinMode(4,INPUT);
  pinMode(7,OUTPUT);
  pinMode(2,INPUT_PULLUP);
  while (digitalRead(2)==HIGH){
    
  }
}

void loop() {
  x=getdistance();
  if(){
    
  }
  else{
    
  }

}
