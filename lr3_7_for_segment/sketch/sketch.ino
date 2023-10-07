#define FIRST_SEGMENT_PIN 0
#define SEGMENT_COUNT 10

// Всего цифр 10, поэтому в массиве 10 чисел.
/*
// Цифры 0-9
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
*/

//int repeat = 0;
void setup()
{
for (int i = 0; i < SEGMENT_COUNT; ++i)
pinMode(i + FIRST_SEGMENT_PIN, OUTPUT);

for (int i = 0; i < SEGMENT_COUNT; i++) { // Перебор сегмента
  //if(i != 1 && i != 2)
    digitalWrite(i + FIRST_SEGMENT_PIN, HIGH);// включаем/выключаем сегмент
}

/*
if (repeat == 0)
for (int i = 0; i < SEGMENT_COUNT; ++i) {
int mask1 = numberSegments[i];
// определяем: должен ли он быть включён.
boolean enableSegment1 = bitRead(mask1, i);
// включаем/выключаем сегмент на основе полученного значения
digitalWrite(i + FIRST_SEGMENT_PIN, enableSegment1);
repeat = repeat + 1;
}
delay(1000);
*/
}

void loop()
{
delay(1000); // Пауза 1 сек.
for (int i = 0; i < SEGMENT_COUNT; i++) { // Перебор сегмента
  if(i != 1 && i != 2){
    digitalWrite(i + FIRST_SEGMENT_PIN, LOW );// включаем/выключаем сегмент
    delay(1000); // Пауза 1 сек.
    digitalWrite(i + FIRST_SEGMENT_PIN, HIGH);// включаем/выключаем сегмент
  }
}

/*
// определяем число, которое следует отобразить.
// Пусть им будет номер текущей секунды, зацикленный на десятке
int number = (millis() / 1000 - 1000) % 10;
// получаем код из массива, в котором содержится полученная цифра
int mask = numberSegments[number];
// для каждого из 7 сегментов индикатора
for (int i = 0; i < SEGMENT_COUNT; ++i) {
// определяем: должен ли он быть включён.
boolean enableSegment = bitRead(mask, i);
// включаем/выключаем сегмент на основе полученного значения
digitalWrite(i + FIRST_SEGMENT_PIN, enableSegment);
}
*/

}