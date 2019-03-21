int TRIG=3;//These are the trigger and echo pins on the sensor
int ECHO=2;//I have put them on pins 2 and 3 
int LEDA=9;
int LEDB=7;
int maxRange=30;//This determines the distance that the LED will
                //turn off. Smaller numbers will work better.
int getdistance(int trig, int echo){//This is the function that will
  long duration;                    //use the sensor to output a distance
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(20);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  duration = duration / 59;//This line appropriately scales the output to be in cm
  if ((duration < 2) || (duration > maxRange)) return false;
  return duration;                                    
}


void setup()
{
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  pinMode(LEDA,OUTPUT);
  pinMode(LEDB,OUTPUT);
  digitalWrite(TRIG,LOW);

}

void loop()
{
  int x=getdistance(TRIG,ECHO);
  int y=maxRange-x;
  int fade=map(y,0,maxRange,0,255);//Maps the brightness to be lowest just before reaching maxRange
  int flash=map(x,0,maxRange,0,1000);//Maps LEDB to blink in intervals up to one second. Blinks slower the further away objects are.
  if (x!=0){
    analogWrite(LEDA,fade); //Dimming part
    digitalWrite(LEDB,HIGH);//These 4 lines are the blinking part
    delay(flash);
    digitalWrite(LEDB,LOW);
    delay(flash);
  }
  else {//If the distance is outside of maxRange, the LED will turn off.
    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
  }
  delay(10);
}
