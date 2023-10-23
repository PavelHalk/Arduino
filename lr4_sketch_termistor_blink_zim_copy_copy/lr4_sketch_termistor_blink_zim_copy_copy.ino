const int ledpin = 2;
const int zumpin = 3;
const int datpin = A0;

#define beta 4090 // значение беты термистора
float reostat_value = 0.0, temp = 0.0;

void setup()
{
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  pinMode(zumpin, OUTPUT);
  pinMode(datpin, INPUT);
}
void loop() {

  reostat_value = analogRead(datpin);
  temp = beta /(beta / 298.0 - log((1025.0 * 10 / reostat_value - 10) / 10)) - 273.0; // Цельсия;
  Serial.print(temp);
  Serial.println(" degrees C");

  if (temp >= 15.0) {
    digitalWrite(ledpin, HIGH);
    tone(zumpin, 600);
    delay(500);
    noTone(zumpin);
    delay(300);
  } else {
    digitalWrite(ledpin, LOW);
    noTone(zumpin);
  }
}

