#include <Servo.h>

int trig = 3;
int echo = 4;
int led = 7;

int button = 2;
int mA = 10;
int mB = 11;

Servo motorA;
Servo motorB;

// float so that we can handle decimals
float speedOfSoundMetersPerSec = 343;
float duration_microSeconds;
float duration_seconds;
float distance_meters;
float distance_cm;

void setup() {
  // put your setup code here, to run once:

  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(led,OUTPUT);
  
  pinMode(button,INPUT);

  motorA.attach(mA);
  motorB.attach(mB);

  stop();

  Serial.begin(9600);

}

/*************************/
/***** car movements *****/
/*************************/

void stop() {
  motorA.write(90);
  motorB.write(90);
}

void backward() {
  motorA.write(180);
  motorB.write(0);
}

void forward() {
  motorA.write(0);
  motorB.write(180);
}

void turnRight() {
  motorA.write(90);
  motorB.write(180);
  delay(500);
  stop();
}

void turnLeft() {
  motorA.write(0);
  motorB.write(90);
  delay(500);
  stop();
}

/***********************/
/**** ultrasonic *******/
/***********************/

float ultrasonic() {
  // reset the ultrasonic sensor
 digitalWrite(trig,LOW);
 delayMicroseconds(5);

 // send a 10 microsecond pulse out through the trigger
 digitalWrite(trig, HIGH);
 delayMicroseconds(10);
 digitalWrite(trig, LOW);

 // wait for the response and store it in duration.  It will return in microseconds.
 duration_microSeconds = pulseIn(echo,HIGH);

 // convert duration to seconds
 duration_seconds = duration_microSeconds / 1000000;

 // get distance traveled in meters.  distance = (speed * time)/2

 distance_meters = (speedOfSoundMetersPerSec * duration_seconds)/2;

 // convert to cm

 distance_cm = distance_meters*100;
 //Serial.println(distance_cm);

 return distance_cm;
 
}

void loop() {

  //wait here until you press the button
  while(digitalRead(button)==HIGH) {
    //do nothing
  }

  //move forward
  forward();

  //keep moving forward WHILE I am more than 5 cm away from the wall
  while (ultrasonic() > 4) {
    forward();
  }

  stop();
  delay(1000);
  backward();
  delay(500);
  turnRight();

  

}
