#include <Wire.h>
#include <LiquidCrystal.h>
#define beta 4090  // значение беты термистора
LiquidCrystal lcd(4, 5, 6, 7, 8, 9);
const int SLAVE_ADDR = 5;
float temp = 0;

void setup() {
  Wire.begin();
  lcd.begin(16, 2);  // Print a message to the LCD.
  for (int i = 4; i < 9; i++) {
    pinMode(i, OUTPUT);
    Serial.begin(9600);
  }
}

void loop() {
  Wire.requestFrom(SLAVE_ADDR, 1);
  if (Wire.available()) {
    temp = Wire.read();
  }
  temp = ((temp * 5000.0 / 1023.0) - 500.0) / 10.0; 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("NTC-MF52Master");
  lcd.setCursor(0, 1);
  lcd.print(String(temp) + "C deg");
  delay(1000);
}
