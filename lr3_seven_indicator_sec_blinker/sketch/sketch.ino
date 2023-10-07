#define FIRST_SEGMENT_PIN   2
#define SEGMENT_COUNT       8

int red = 11;
int yellow = 12;
int green = 13;

int delayblink = 500;
int delaycounter = 1000; //секундометр задержка в секунду
int delayPeriod = 9000;
int delayyellow = 3000;

int count;
int blinkingtimer;

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

int repeat = 0;

void setup() {
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);
    for (int i = 0; i < SEGMENT_COUNT; ++i)
      pinMode(i + FIRST_SEGMENT_PIN, OUTPUT);
}

void loop() {
    changeLights();
}

void changeLights(){
    changeinteger(9); // вкл секундомер на 9
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH); //green lights shine for 9 seconds
    for (int i = 8; i >= 0; --i) {
      delay(delaycounter);
      changeinteger(i); // секундомер с счётчиком от 8 до 0
    }
    delay(delayblink); //short delay for null in indicator
    //delay(delayPeriod); 9 раз по 1 секунде в секундомере
    blinkingtimer = 0;
    count = 3;
    //green blinked on for 3 seconds
        changeinteger(count); // вкл секундомер на 3
    while(blinkingtimer < 3000) {
      digitalWrite(green, LOW);
      delay(delayblink);
      digitalWrite(green, HIGH);
      delay(delayblink);
      count--;
      changeinteger(count); // вкл секундомер на 2
      blinkingtimer += delayblink * 2;

    }
    delay(delayblink); //short delay for null in indicator
    changeinteger(3); // вкл секундомер на 3
    // green off, yellow on for 3 seconds
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    //delay(delayyellow);
  for(count = 2; count >= 0; count--)
     {
      delay(delaycounter);
      changeinteger(count); // вкл секундомер на 3
     }

    delay(delayblink); //short delay for null in indicator
    changeinteger(9); // вкл секундомер на 9
    // turn off yellow, then turn red on for 9 seconds
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    for (int i = 8; i >= 0; --i) {
      delay(delaycounter);
      changeinteger(i); // секундомер с счётчиком от 8 до 0
    }
    delay(delayblink); //short delay for null in indicator
    //delay(delayPeriod);
}

void changeinteger(int looping){
  // определяем число, которое следует отобразить.
  //  Пусть им будет номер текущей секунды, зацикленный на десятке
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
