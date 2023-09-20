// пин для подключения динамика
#define buzzer 11

const int red_led = 3;
const int green_led = 4;

int val1 = A0;
int val2 = A1;
int val3 = A2;

bool pin1 = false;
bool pin2 = false;
bool pin3 = false;

int delaylong = 800; // 5 count

void setup() {
  pinMode(val1, INPUT);
  pinMode(val2, INPUT);
  pinMode(val3, INPUT);
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
    Serial.begin(9600);
}

void loop() {
  pin1 = false;
  pin2 = false;
  pin3 = false;
  Serial.println("Введите кодовую последовательность: ");
  digitalWrite(red_led, HIGH);
  digitalWrite(green_led, LOW);
  noTone(buzzer);
  for (;;) {
    if (digitalRead(val2) == HIGH) {
      pin1 = true;
      break;
    }
    if (digitalRead(val1) == HIGH) {
      break;
    }
    if (digitalRead(val3) == HIGH) {
      break;
    }
  }
  for (;;) {
    if (digitalRead(val3) == HIGH) {
      pin2 = true;
      break;
    }
    if (digitalRead(val1) == HIGH) {
      break;
    }
  }
  for (;;) {
    if (digitalRead(val1) == HIGH) {
      pin3 = true;
      break;
    }
  }


  if (pin1 == true && pin2 == true && pin3 == true) {
    Serial.println("Доступ разрешён " );
    digitalWrite(red_led, LOW);
    digitalWrite(green_led, HIGH);
  } else {
    Serial.println("Доступ запрещён ");
    for (int i = 0; i < 5; i++) {
      digitalWrite(red_led, HIGH);
      tone(buzzer, 1 * red_led);
      delay(delaylong);
      digitalWrite(red_led, LOW);
      noTone(buzzer);
      delay(200);
    }
  }
  delay(5000); //обновление для ввода последов.

}