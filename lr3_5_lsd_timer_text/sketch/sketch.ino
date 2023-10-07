// include the library code:
#include <LiquidCrystal.h>

int but0 = A0; //вкл & stop (GREEN BUTTON)
int but1 = A1; //RESET      (BLUE  BUTTON)
int delaypushbut = 400; //чтобы было время на нажатие. 
//Цикл работает быстрее, чем происходит событие нажатия

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
/*const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7; //for wokwi
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);*/
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte val = 0;
boolean switching = false;
int button2WasUp = 0;
int countclick = 0;
bool upbut = true;

int digit_global;
int minut_global;
bool CHETNOST;
boolean whatsbutton = false;

byte val1 = 0;
boolean switching1 = false;
int button2WasUp1 = 0;
int countclick1 = 0;
bool upbut1 = true;

void setup() {
  pinMode(but0, INPUT); 
  pinMode(but1, INPUT); 
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello, world!");

  Serial.begin(9600);
  digit_global = 0;
  minut_global = 0;
  CHETNOST     = true;
}

void loop() {
  // (note: line 1 is the second row, since counting begins with 0):
  buttonOn0(); //отслеживание события на нажатие кнопки0
  buttonOn1(); //отслеживание события на нажатие кнопки1
  // set the cursor to column 0, line 1

  if (switching) { 
    // Если флаг включен, то идёт отчёт timer for 0-59
    for(int i = digit_global; i < 60; i++){
      //  Пусть им будет номер текущей секунды, зацикленный на десятке
      if (digit_global == 60) 
      {
        i = 0;
        minut_global++;
      } 
      // перевод 60 сек в 1 мин
      digit_global = i;
      timer(digit_global, minut_global); //считаем время на дислпей

      delay(1000);
      buttonOn0(); //отслеживание события на нажатие кнопки0
      buttonOn1(); //отслеживание события на нажатие кнопки1
      if (!switching) break;
    }
    buttonOn0(); //отслеживание события на нажатие кнопки0
    buttonOn1(); //отслеживание события на нажатие кнопки1
 }
  // передвигающийся текст к последнему заданию
  delay(500); 
  lcd.scrollDisplayLeft();

}

void butok(){

  if(upbut && whatsbutton) {
    if (countclick == 1) {

      switching = true; // Переводим флаг в вкл. состояние
      Serial.println("Секундомер вкл.");

    } else if (countclick == 0) {

      switching = false;
      Serial.println("Секундомер stop.");

    }
  }
  else if(upbut1 && !whatsbutton) {
     if (countclick1 == 0) {

       timer(000, 00);
       Serial.println("Секундомер выкл.");
       switching1 = false;
     }
  }

  upbut = false;
  upbut1= false;
}

void buttonOn0(){
val=digitalRead(but0);
if(val == HIGH) {// Иначе если нажата Btn1
    if(button2WasUp == 0) {
      button2WasUp++;
      delay(delaypushbut);
      
    } else {
      if (countclick == 1) countclick = 0;
      else countclick++;
      button2WasUp = 0;
      upbut = true;
      whatsbutton = true;
      switching = false;
      delay(delaypushbut);

    }
  }
  butok();
}

void buttonOn1(){
val1=digitalRead(but1);
if(val1 == HIGH) {// Иначе если нажата Btn1
    if(button2WasUp1 == 0) {
      button2WasUp1++;
      delay(delaypushbut);
      
    } else {
      if (countclick1 == 1) countclick1 = 0;
      else countclick1++;
      button2WasUp1 = 0;
      upbut1 = true;
      whatsbutton = false;
      switching1 = false;
      delay(delaypushbut);

    }
  }
  butok();
}

void timer(int digit, int minut){
  //digit = millis() / 1000; //really timer
  lcd.setCursor(10, 1);
  // print the number of seconds since reset:
  if(CHETNOST) 
  {
    lcd.print(String(minut) + ":" + String(digit) + " ");
    CHETNOST = false;
  } else {
    lcd.print(String(minut) + " " + String(digit) + " ");
    CHETNOST = true;
  }
  
  digit_global = digit;
  minut_global = minut;
}