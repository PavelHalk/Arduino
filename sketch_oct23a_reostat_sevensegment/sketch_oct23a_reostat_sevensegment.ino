const int value_reostat = A0;

void setup() {
  for (int i = 1; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(value_reostat, INPUT);
}

void loop() {
  int r = analogRead(value_reostat);
  if (r < 10) {
    clear();
    for (int i = 1; i < 8; i++)  // 0
    {
      if (i != 6) digitalWrite(i, HIGH);
    }
  } else 
  if (r >= 10 && r < 250) {
    clear();
    for (int i = 2; i < 4; i++)  // 1
    {
      digitalWrite(i, HIGH);
    }
  } else 
  if (r >= 250 && r < 550) {
    clear();
    for (int i = 1; i < 8; i++)  // 2
    {
      if (i != 3 && i != 7) digitalWrite(i, HIGH);
    }
  } else 
  if (r >= 550 && r < 800) {
    clear();
    for (int i = 1; i < 8; i++)  // 3
    {
      if (i != 5 && i != 7) digitalWrite(i, HIGH);
    }
  } else 
  if (r >= 800 && r < 1010) {
    clear();
    for (int i = 1; i < 8; i++)  // 4
    {
      if (i != 1 && i != 4 && i != 5) digitalWrite(i, HIGH);
    }
  } else 
  if (r >= 1010) {
    clear();
    for (int i = 1; i < 8; i++)  // 5
    {
      if (i != 2 && i != 5) digitalWrite(i, HIGH);
    }
  }
}

void clear() {
  delay(100);
  for (int i = 1; i < 8; i++) {
    digitalWrite(i, LOW);
  }
}
