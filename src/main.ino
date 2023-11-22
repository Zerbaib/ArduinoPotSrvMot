#include <Wire.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20,16,2);
int brochepot = A0;
int valpot;
int conversion;
Servo servo;

void setup() {
  servo.attach(3);
  lcd.init();
  lcd.clear();         
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Hugo Hennetin");
}

void loop() {
  valpot = analogRead(brochepot);
  conversion = map(valpot, 0, 1024, 0, 180);
  lcd.setCursor(1,1);
  lcd.print("Potent.: " + String(conversion));
  servo.write(conversion);
}
