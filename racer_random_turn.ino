#include <Servo.h>

int trig = 3;
int echo = 4;
/* 20200604 - changed from 2 to 7 to match Ed's hardware */
int led = 7; 

/* 20200604 - changed from 8 to 2 to match Ed's hardware */
int button = 2;

/* 20200604 - changed from 12 to 10 to match Ed's hardware */
int mA = 10;

/* 20200604 - changed from 13 to 11 to match Ed's hardware */
int mB = 11;
int button2 = 8;


Servo motorA;
Servo motorB;

long randNumber;
// float so that we can handle decimalse
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

  randomSeed(analogRead(0));
  
}

/*************************/
/***** car movements *****/
/*************************/

void stop() {
  motorA.write(90);
  motorB.write(90);
}

void backward() {
  motorA.write(160);
  motorB.write(0);
}

void forward() {
  motorA.write(0);
  motorB.write(180);
}

void turnRight() {
  motorA.write(90);
  motorB.write(180);
  delay(550);
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
   randomSeed(analogRead(0));
}

void loop() {
  // print a random number from 10 to 19
  /**20200604 - 
   * changed from random(3) to random(1,3).  You need to add the 1 to 
   * set the lowest random number to 1.
   * 
   * Also turn off the LED when you begin the loop
   */
  digitalWrite(led,LOW);
  randNumber = random(1,3);
  Serial.println(randNumber);

  /**20200604 - 
   * Add logic so that the LED turns on if randNumber = 1and LED turns off if randNumber = 2
   */
  if (randNumber == 1) {
    digitalWrite(led,HIGH);
  }
  if (randNumber == 2) {
    digitalWrite(led,LOW);
  }

  delay(50);
  
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

  if(randNumber== 1) {
    turnRight();
  }
  if(randNumber == 2) {
    turnLeft();
  }
  

}
