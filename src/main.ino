#include <Wire.h>
#include <Servo.h>

int brochepot = A0;
int valpot;
int conversion;
Servo servo;

void setup() {
  servo.attach(7);
}

void loop() {
  valpot = analogRead(brochepot);
  conversion = map(valpot, 0, 1024, 0, 180);
  servo.write(conversion);
}
