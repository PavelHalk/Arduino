// пин для подключения динамика
#define buzzer 11
// пины подключения светодиодов
int led[] = { 2, 3, 4, 5};
// пины для подключения кнопок
int but[] = { A0, A1, A2, A3 };
// варианты комбинаций (можно добавить свои)
char* kod[] = { "1203", "1230", "0213", "3201", "1302",
             "1321", "0312", "2301", "1203", "2103"
             };
int del = 1000;
int w = -1, aa = 0;
byte level = 1;
byte b1, b2, b3, b4;
String KOD, OTV, A;

byte num_led = sizeof(led) / sizeof(int*);
byte num_but = sizeof(but) / sizeof(int*);
byte num_cod = sizeof(kod) / sizeof(char*);
byte len = strlen(kod[0]);

boolean button1WasUp = true;
boolean button2WasUp = true;
boolean button3WasUp = true;
boolean button4WasUp = true;

void setup() {
  pinMode(buzzer, OUTPUT);
  // настраиваем пины для светодиодов
  for (byte i = 0; i <= num_led; i++) {
    pinMode(led[i], OUTPUT);
  }

  // настраиваем пины для кнопок
  for (byte i = 0; i <= num_but; i++) {
    pinMode(but[i], INPUT_PULLUP);
  }
  Serial.begin(9600);
  Serial.println("LEVEL - " + String(level));
  Serial.println("");
}

void loop() {
 
  // рандомно выбираем одну из комбинаций
  while (w == -1) {
    int  x = random(0, num_cod - 1);
    KOD = {kod[x]};
    b1 = 0; b2 = 0; b3 = 0; b4 = 0;
    w = 0;
  }
  delay(10);
  digitalWrite(led[0], LOW);
  delay(10);
  // поочередно включаем светодиоды согласно комбинации
  while (w <= len - 1) {
    aa = 1;
    A = KOD[w];
    int a = A.toInt();
    digitalWrite(led[a], HIGH);
    tone(buzzer, aa * led[a]);
    delay(10);
    noTone(buzzer);
    delay(del);
    digitalWrite(led[a], LOW);
    w++;
    aa++;
  }

  // ждем нажатия всех кнопок
  while (w >= len - 1 and w <= len + len) {
    boolean button1IsUp = digitalRead(but[0]);
    boolean button2IsUp = digitalRead(but[1]);
    boolean button3IsUp = digitalRead(but[2]);
    boolean button4IsUp = digitalRead(but[3]);

    if (b1 == 0 and button1WasUp and !button1IsUp) {
      delay(10);
      button1IsUp = digitalRead(but[0]);
      if (!button1IsUp) {
        tone(buzzer, 1 * led[0]);
        delay(10);
        noTone(buzzer);
        OTV = OTV + "0";
        digitalWrite(led[0], HIGH);
        b1 = 1;
        w++;
      }
    }
    button1WasUp = button1IsUp;

    if (b2 == 0 and button2WasUp and !button2IsUp) {
      delay(10);
      button2IsUp = digitalRead(but[1]);
      if (!button2IsUp) {
        tone(buzzer, 2 * led[1]);
        delay(10);
        noTone(buzzer);
        OTV = OTV + "1";
        digitalWrite(led[1], HIGH);
        b2 = 1;
        w++;
      }
    }
    button2WasUp = button2IsUp;

    if (b3 == 0 and button3WasUp and !button3IsUp) {
      delay(10);
      button3IsUp = digitalRead(but[2]);
      if (!button3IsUp) {
        tone(buzzer, 3 * led[2]);
        delay(10);
        noTone(buzzer);
        OTV = OTV + "2";
        digitalWrite(led[2], HIGH);
        b3 = 1;
        w++;
      }
    }
    button3WasUp = button3IsUp;

    if (b4 == 0 and button4WasUp and !button4IsUp) {
      delay(10);
      button4IsUp = digitalRead(but[3]);
      tone(buzzer, 4 * led[3]);
      delay(10);
      noTone(buzzer);
      if (!button4IsUp) {
        OTV = OTV + "3";
        digitalWrite(led[3], HIGH);
        b4 = 1;
        w++;
      }
    }
    button4WasUp = button4IsUp;

    // если комбинация совпадает начинаем новый уровень
    if (w == len + len and OTV == KOD) {
      Serial.println("");
      Serial.println("DA!");
      Serial.println("");
      level++;
      Serial.println("LEVEL - " + String(level));
      del = del - 100;
      if (del < 10) { del = 100; }
      delay(1000);
      for (byte i = 0; i <= num_led; i++) {
        digitalWrite(led[i], LOW);
      }
      delay(2000);
      KOD = "";
      OTV = "";
      w = -1;
    }
 
    // если комбинация неправильная задаем новую
    if (w == len + len and OTV != KOD) {
      Serial.println("");
      Serial.println("HET!");
      Serial.println("");
      tone(buzzer, 100);
      delay(1000);
      noTone(buzzer);
      Serial.println("LEVEL - " + String(level));
      for (byte i = 0; i <= num_led; i++) {
        digitalWrite(led[i], LOW);
      }
      delay(2000);
      KOD = "";
      OTV = "";
      w = -1;
    }

  }
}
