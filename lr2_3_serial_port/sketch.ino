int x = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("Начинаю отчёт каждую секунду через последовательный порт");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Значение числа на +1 в сек: " + String(x) + ".");
delay(1000);
x++;
}
