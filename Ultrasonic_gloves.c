#include<Arduino.h>
const int pingTrigPin = 12;  
const int pingEchoPin = 10;   
const int buz = 5;            

void setup() {
  Serial.begin(9600);         
  pinMode(buz, OUTPUT);       
}

void loop() {
  long duration, cm;

  pinMode(pingTrigPin, OUTPUT);      
  digitalWrite(pingTrigPin, LOW);    
  delayMicroseconds(2);               

  digitalWrite(pingTrigPin, HIGH);   
  delayMicroseconds(5);
  digitalWrite(pingTrigPin, LOW);     

  pinMode(pingEchoPin, INPUT);        
  duration = pulseIn(pingEchoPin, HIGH); 

  cm = microsecondsToCentimeters(duration); 

  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.println(" cm");

  if (cm <= 50 && cm > 0) {
    digitalWrite(buz, HIGH);    
  } else {
    digitalWrite(buz, LOW);    
  }

  delay(100); 
}

long microsecondsToCentimeters(long microseconds) {
 
  return microseconds / 29 / 2;
}
