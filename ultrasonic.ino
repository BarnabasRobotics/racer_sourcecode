int ultrasonic(int trigPin, int echoPin)
{
  long duration;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  duration = duration / 59;
  if ((duration < 2) || (duration > 300)) return false;
  return duration;
}


void setup()
{
  pinMode( 7 , OUTPUT);
  digitalWrite( 3 , LOW );

}

void loop()
{
  digitalWrite( 7 , HIGH );
  delay( 	ultrasonic( 3 , 4 ) );
  digitalWrite( 7 , LOW );
  delay( 	ultrasonic( 3 , 4 ) );
}


