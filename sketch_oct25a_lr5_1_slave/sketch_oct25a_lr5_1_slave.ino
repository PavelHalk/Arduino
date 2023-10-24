#include <Wire.h>

char x;

void setup() {
  Wire.begin(5);
  Wire.onReceive(receiveEvent);
  for (int i = 2; i <= 4; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  if (x == 'y') {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(2, LOW);
  } else if (x == 'g') {
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
  } else if (x == 'r') {
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
  }
}

void receiveEvent(int howMany) {
  x = Wire.read();
}
