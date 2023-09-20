// пин для подключения динамика
#define buzzer 11


const int left_btn = A0;
const int rght_btn = A1;
int left_led = 4;
int rght_led = 3;
byte left_val = 0;
byte rght_val = 0;
int x, y;
void setup() {
  pinMode(left_btn, INPUT);
  pinMode(rght_btn, INPUT);
  pinMode(left_led, OUTPUT);
  pinMode(rght_led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  x=0; 
  y=0;
}

void loop() {
 noTone(buzzer);
 delay(random(500, 6000));
 digitalWrite(buzzer, HIGH);
 for(int i = 0; i<1; i++){
  if(digitalRead(left_btn)==HIGH){
    delay(100);
    left_val=1;
    digitalWrite(left_led, HIGH);
    x++;
    Serial.println("Сигнал левый " + String(x) + ":" + String(y));
    break;
} else if (digitalRead(rght_btn)==HIGH){
    delay(100);
    digitalWrite(rght_led, HIGH);
    y++;
    Serial.println("Сигнал правый " + String(x) + ":" + String(y));
    rght_val=1;
    break;
  }
 }
 if(left_val == 1){
  delay(80);
  tone(buzzer, 8 * left_led);
  delay(300); 
  digitalWrite(left_led, LOW);       
  left_val=0;
 }
  if(rght_val == 1){
  delay(80);
  tone(buzzer, 1 * rght_led);
  delay(300);
  digitalWrite(rght_led, LOW);  
  rght_val=0;
 }
}
