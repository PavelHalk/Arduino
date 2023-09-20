// пин для подключения динамика
#define buzzer 11

int but = A1;
int led = 2;
byte val = 0;
bool flag = false;

boolean switching = false;
int button2WasUp = 0;

#define dot 300 //длительность короткого сос
#define dash 1200 //длительность длинного сос

void setup() {
  pinMode(but, INPUT); 
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
val=digitalRead(but); 
if(val == HIGH) {// Иначе если нажата Btn1
      
    if(button2WasUp == 0) {
      button2WasUp++;
      switching = true ; // Переводим флаг в вкл. состояние
      Serial.println("Лампочка и зуммер вкл.");
      delay(3000);// 3 сек ждать, чтобы выкл
    }
    else {
      button2WasUp = 0;
      switching = false;
      Serial.println("Лампочка и зуммер выкл.");
      delay(3000); // потом 3 сек, но при вкл не надо ждать
    }

}


if (switching == true) // Если флаг включен, то горит светодид и зуммер пищит
  {
   flag=true;
   delay(200);

} else flag = false;
   
int i = 0;

if(flag==true){

// 3 точки
  for(i=0; i<3; i++){
    digitalWrite(led,HIGH);
    tone(buzzer, 4 * led);
  delay(dot);
   digitalWrite(led,LOW);
    noTone(buzzer);
  delay(dot);
  }
val = digitalRead(but);
  //пауза между коротким сос и длинным равная 1й точке
  delay(dot);
  //3 тире
for(i=0; i<3; i++){
    digitalWrite(led,HIGH);
    tone(buzzer, 4 * led);
  delay(dash);
   digitalWrite(led,LOW);
    noTone(buzzer);
  delay(dot);
  }
val = digitalRead(but);
  //снова пауза
  delay(dot);
  //3 точки
for(i=0; i<3; i++){
    digitalWrite(led,HIGH);
    tone(buzzer, 4 * led);
  delay(dot);
   digitalWrite(led,LOW);
    noTone(buzzer);
  delay(dot);
  }
val = digitalRead(but);
  //7 сигналов - пауза между ними
  delay(7*dot);
  flag=true;
  val = digitalRead(but);
} 

else 

if (flag==false){
  flag=false;
  digitalWrite(led,LOW);
    noTone(buzzer);
}

}
  
