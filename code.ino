// Automatic Canon Gun 
// developer : Kunal Kaushik

#include <Servo.h>
char i;
const int trigPin = 3;
const int echoPin = 5;
long duration;
int distance;
Servo myservo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(9);
  myservo.write(180);
  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  
  if (distance < 30)
  {
    delay(500);
    shoot();
    delay(2000);
  }
}

void shoot()
{
  Serial.println("SHOOT");
  delay(1000);
  myservo.write(0);
  delay(1000);
  myservo.write(180);
  delay(1000);
}
