#include <Servo.h>

Servo ESC;     // create servo object to control the ESC
int speed = 5;    // min 50 to max 180
const int trigPin = 9;  
const int echoPin = 10; 

void setup() {
  // Attach the ESC on pin 5
  ESC.attach(5,700,2000); // (pin, min 800 pulse width, max 1000 pulse width in microseconds) 
  pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  delay(5000);
}

void loop() {
  digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trigPin, LOW); 
  float duration = pulseIn(echoPin, HIGH); 
  int distance = (duration*.0343)/2;  

  if(distance<25){
    ESC.write(speed);
  }
  else ESC.write(0);    // Send the signal to the ESC
 
  Serial.println(distance);
}
