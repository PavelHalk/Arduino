#include <LiquidCrystal.h>

#define beta 4090 // значение беты термистора
float reostat_value = 0.0, temp = 0.0;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  // Print a message to the LCD.
  Serial.begin(9600);
  pinMode(A0, INPUT);
  //Serial.println("Замеряю значение в сек., читаемое с термистора: ");
}
void loop() {
  reostat_value = analogRead(A0);
  lcd.setCursor(0, 0);
  lcd.print("MF52 NTC-MF52AT");
  lcd.setCursor(0, 1);

  temp = beta /(beta / 298.0 - log((1025.0 * 10 / reostat_value - 10) / 10)) - 273.0; // Цельсия
  //temp = 1.8 * temp + 32.0; // по Фаренгейту

  lcd.print(String(temp));
  //Serial.println(String(reostat_value) + ".");
  Serial.println(temp);
  //delay(1000);
}
