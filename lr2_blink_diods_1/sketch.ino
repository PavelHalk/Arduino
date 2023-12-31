int led[] = {2, 3, 4};
char* kod[] = { "012", "120", "201", "010", "102"
, "002", "121", "202", "210"};

byte num_led = sizeof(led) / sizeof(int*);
byte num_cod = sizeof(kod) / sizeof(char*);
byte len = strlen(kod[0]);   
int del = 300; //задержка для интервала 0.3 сек
int w = -1;
String KOD, A;
void setup() {
  // put your setup code here, to run once:
  for (byte i = 0; i <= num_led; i++) {
    pinMode(led[i], OUTPUT);
  }  
  Serial.begin(9600);
}

void loop() {
  // рандомно выбираем одну из комбинаций
  int x;
  while (w == -1) {
    x = random(0, num_cod - 1);
    KOD = {kod[x]}; 
    w = 0;
  }
  // поочередно включаем светодиоды согласно комбинации
  while (w <= len - 1) {
    A = KOD[w];
    int a = A.toInt();
    digitalWrite(led[a], HIGH);
    delay(del);  //использование задержки в цикле
    digitalWrite(led[a], LOW);
    w++;
  }
delay(4000); //каждые 4 секунды загорается различная рандомная последовательность из kod[]
KOD = "";
w = -1;
}
                                                