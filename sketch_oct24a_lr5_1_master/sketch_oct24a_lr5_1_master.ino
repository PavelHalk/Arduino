#include <Wire.h>

int led_r = 4;
int led_y = 3;
int led_g = 2;

char green = 'g';
char yellow = 'y';
char red = 'r';

void setup() {
  Wire.begin();
  for (int i = 2; i <= 4; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  Wire.beginTransmission(5);
  Wire.write(green);
  Wire.endTransmission();
  digitalWrite(led_g, HIGH);
  delay(2000);
  digitalWrite(led_g, LOW);

  Wire.beginTransmission(5);
  Wire.write(yellow);
  Wire.endTransmission();
  digitalWrite(led_y, HIGH);
  delay(2000);
  digitalWrite(led_y, LOW);

  Wire.beginTransmission(5);
  Wire.write(red);
  Wire.endTransmission();
  digitalWrite(led_r, HIGH);
  delay(2000);
  digitalWrite(led_r, LOW);

  Wire.beginTransmission(5);
  Wire.write(yellow);
  Wire.endTransmission();
  digitalWrite(led_y, HIGH);
  delay(2000);
  digitalWrite(led_y, LOW);
}
