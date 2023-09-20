// пин для подключения динамика
#define buzzer 11
int x = 0;
// пины подключения светодиодов
int led = 2;
// пины для подключения кнопок
int but[] = { A0, A1};

boolean button1WasUp = true;
boolean button2WasUp = true;

boolean switching = false;
void setup() {
  // put your setup code here, to run once:
/*Serial.begin(9600);
Serial.println("Начинаю отчёт каждую секунду через последовательный порт");*/
Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(but[0], INPUT);
  pinMode(but[1], INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*Serial.println("Значение числа на +1 в сек: " + String(x) + ".");
delay(1000);
x++;*/
boolean button1IsUp = digitalRead(but[0]);
boolean button2IsUp = digitalRead(but[1]);

if (button1IsUp == HIGH) {// Если нажата Btn2

      switching = true; // Переводим флаг в выкл. состояние
      button1WasUp = true;
      delay(100);
}

else if(button2IsUp == HIGH) {// Иначе если нажата Btn1
      
      switching = false ; // Переводим флаг в вкл. состояние
      button2WasUp = true;
      delay(100);
}

if (switching == true) // Если флаг включен, то горит светодид и зуммер пищит
  {
    if (button1WasUp)
      {      
      tone(buzzer, 2* led);
      digitalWrite(led, HIGH);
      Serial.println("Лампочка и зуммер вкл.");
      }
    button1WasUp = false;
  }

else // Иначе выключаем оба устройства

  {
    if (button2WasUp)
      {
      noTone(buzzer);
      digitalWrite(led, LOW);
      Serial.println("Лампочка и зуммер выкл.");
      }
    button2WasUp = false;
  }

}
