int trig = 3;
int echo = 4;

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

  Serial.begin(9600);
  
}

void loop() {
  
  // reset the ultrasonic sensor
  digitalWrite(trig,LOW);
  delayMicroseconds(5);

  // send a 10 microsecond pulse out through the trigger
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // wait for the response and store it in duration.  It will retun in microseconds
  duration_microSeconds = pulseIn(echo, HIGH);

  // convert duration to seconds
  duration_seconds = duration_microSeconds / 1000000;

  // get distance traveled in meters.  distance = (speed * time) / 2.  
  // We need to divide by two because the sound needs to go from the sensor, hit the wall, and then come back.  So it travels twice.
  distance_meters = (duration_seconds * speedOfSoundMetersPerSec)/2;

  //convert meters to 
  distance_cm = distance_meters*100;

  //throw out bad readings.  Max reading is around 300 cm.
  Serial.println(distance_cm);
 
}
