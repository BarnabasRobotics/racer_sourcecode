#include <Servo.h>
int TRIG=3;
int ECHO=4;
Servo LM;
Servo RM;

void stop(){
  LM.write(90);
  RM.write(90);
}

void go(float x, float y, float z){
  LM.write(90+z);
  RM.write(90-z);
  delay(x*1000);
  stop();
  delay(y*1000);
}

void turn(float x, float y, float z){
  LM.write(90+z);
  RM.write(90+z);
  delay(x*1000);
  stop();
  delay(y*1000);
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
  pinMode(2,INPUT_PULLUP);
  pinMode(3,OUTPUT);
  pinMode(4,INPUT);
  pinMode(7,OUTPUT);
  LM.attach(11);
  RM.attach(10);
  while (digitalRead(2)==HIGH){
    stop();
  }
}

void loop() {
  int x=getdistance();
  if (x<20 and x!=0){
    turn(0.5,1,25);
  }
  else{
    go(1,0,90);
  }
}
