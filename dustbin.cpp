#include <Servo.h>

#define trig 12
#define echo 14
#define servoPin 27

Servo lid;
long duration;
int distance;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  lid.attach(servoPin);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 15) {
    lid.write(90);  // Open lid
    delay(3000);    // Wait 3 sec
    lid.write(0);   // Close lid
  }

  delay(1000);
}
