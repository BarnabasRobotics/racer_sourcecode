int trig = 3;
int echo = 4;
int led = 7;

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

  Serial.begin(9600);

}

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
 Serial.println(ultrasonic());

 if (ultrasonic() < 5) {
  //do something
  digitalWrite(led,HIGH);
 }
 else {
  //do something else
  digitalWrite(led,LOW);
 }

}
