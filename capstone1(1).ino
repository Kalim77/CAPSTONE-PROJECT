int redPin=11;
int greenPin=10;
int bluePin=9;
const int analog_pin = A0;
const float alpha =0.1;
double lastAvg = 0.0;

void setup() 
{                     
Serial.begin(9600);
delay (10);
pinMode(redPin,OUTPUT); // set the LED pins as output
pinMode(greenPin,OUTPUT);
pinMode(bluePin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int i=0;
  int cur_sample=0;
  double cur_avg=0.0;
  int psensor = analogRead(A0);
  cur_sample = analogRead(analog_pin);
  delayMicroseconds(300);
  cur_avg = (cur_sample*alpha) + ((lastAvg)*(1-alpha));
   float millivol = cur_avg * (5000.0 / 1023.0);
  Serial.println(millivol);
  lastAvg=cur_avg;
  delayMicroseconds(300);
{
  if(psensor < 200)     // reading equal to zero, RGB LED turns blue
 {                         
 digitalWrite(bluePin, HIGH);
 digitalWrite(greenPin,HIGH);
 digitalWrite(redPin,0);
  delay(10);
 }
 if(psensor > 350)                      // reading at desired pressure, RGB LED turns green
 {
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin,0);
  digitalWrite(redPin,0);
  delay(10);
 }
 
   if(220< psensor < 350)     //reading lower than desired pressure, RGB LED turns red
 {                          
 digitalWrite(redPin,HIGH);
 digitalWrite(greenPin,0);
 digitalWrite(bluePin,0);
  delay(10);
}
}
}
