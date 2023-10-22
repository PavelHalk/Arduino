#include <LiquidCrystal.h>
byte val = 0;
double reostat_value = 0.0;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  // Print a message to the LCD.
  Serial.begin(4800);
  pinMode(A0, INPUT);
  //Serial.println("Замеряю значение в сек., читаемое с потенциометра: ");
}

void loop() {
  reostat_value = analogRead(A0);
  lcd.setCursor(0, 0);
  lcd.print("reostat-B5K");
  lcd.setCursor(0, 1);
  lcd.print(String(reostat_value));
  //Serial.println(String(reostat_value) + ".");
  Serial.println(reostat_value);
  //delay(1000);
}
