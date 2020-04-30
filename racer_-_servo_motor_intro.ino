#include <Servo.h>

Servo motorA;
Servo motorB;

void setup() {
  // put your setup code here, to run once:

  pinMode(2,INPUT);
  pinMode(7,OUTPUT);
  motorA.attach(10);
  motorB.attach(11);

  motorA.write(90);
  motorB.write(90);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(2)==LOW) {
    //this is what happens when you press the button
    digitalWrite(7,HIGH);
    motorA.write(0);
    motorB.write(0);
    delay(2000);   
    motorA.write(72);
    motorB.write(80);
    delay(2000);
    motorA.write(90);
    motorB.write(90);
    delay(2000);
  }
  else {
    //this is what happens when you don't press the button
    digitalWrite(7,LOW);
    motorA.write(90);
    motorB.write(90);
  }
  
  
}
