int but = A0;
int led = 2;

#define FIRST_SEGMENT_PIN   2
#define SEGMENT_COUNT       8

int red = 11;
int yellow = 12;
int green = 13;

int delaypushbut = 500; //чтобы было время на нажатие. Цикл работает быстрее, чем происходит событие нажатия

/* Всего цифр 10, поэтому в массиве 10 чисел.
   Цифры 0-9*/
byte numberSegments[10] = {
0b00111111,
0b00000110,
0b01011011,
0b01001111,
0b01100110,
0b01101101,
0b01111101,
0b00000111,
0b01111111,
0b01101111
};

byte val = 0;
boolean switching = false;
int button2WasUp = 0;
int countclick = 0;
bool upbut = true;

#define dot 300 //длительность короткого сос
#define dash 1200 //длительность длинного сос
void setup() {
    pinMode(but, INPUT); 
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);
    for (int i = 0; i < SEGMENT_COUNT; ++i)
      pinMode(i + FIRST_SEGMENT_PIN, OUTPUT); 
    changeinteger(0); // секундомер in 0
    Serial.begin(9600); 
}

void loop() {
  buttonOn(); //отслеживание события на нажатие кнопки

if (switching ) { // Если флаг включен, то идёт отчёт
  // timer for 0-9
  for(int i=0; i<10; i++){
    //  Пусть им будет номер текущей секунды, зацикленный на десятке
    // int number = (millis() / 1000) % 10; // время секундомера начинается 
    // относительно запуска симуляции
    if (i == 10) i = 0;
    changeinteger(i);
    delay(1000);
    buttonOn(); //отслеживание события на нажатие кнопки
    if (!switching) break;
  }
}
}

void butok(){

  if(upbut) {
    if(countclick == 0) {
      digitalWrite(red, HIGH);
      digitalWrite(yellow, LOW);
      digitalWrite(green, LOW); 
      changeinteger(0);
      switching = false;
      Serial.println("Секундомер выкл.");

    } else if (countclick == 1) {
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(green, HIGH);
      switching = true; // Переводим флаг в вкл. состояние
      Serial.println("Секундомер вкл.");

    } else if (countclick == 2) {
      digitalWrite(red, LOW);
      digitalWrite(yellow, HIGH);
      digitalWrite(green, LOW);
      switching = false;
      Serial.println("Секундомер stop.");

    }
  }

  upbut = false;
}


void buttonOn(){
val=digitalRead(but);
if(val == HIGH) {// Иначе если нажата Btn1
    if(button2WasUp == 0) {
      button2WasUp++;
      delay(delaypushbut);
      
    } else {
      if (countclick == 2) countclick = 0;
      else countclick++;
      button2WasUp = 0;
      upbut = true;
      switching = false;
      delay(delaypushbut);

    }
  }
  butok();
}

void changeinteger(int looping){
  // определяем число, которое следует отобразить.
  // получаем код из массива, в котором содержится полученная цифра
  int mask = numberSegments[looping];
  // для каждого из 7 сегментов индикатора
  for (int i = 0; i < SEGMENT_COUNT; ++i) {
    // определяем: должен ли он быть включён.
    boolean enableSegment = bitRead(mask, i);
    // включаем/выключаем сегмент на основе полученного значения
    digitalWrite(i + FIRST_SEGMENT_PIN, enableSegment);
  }
}
