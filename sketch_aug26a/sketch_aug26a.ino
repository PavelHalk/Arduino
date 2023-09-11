int red = 10;
int yellow = 9;
int green = 8;
int repeat = 1;
int delayPeriod = 650;
void setup() {
  // put your setup code here, to run once:
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 if(repeat == 1)
 {
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  delay(3000);
  repeat = 2;
  digitalWrite(red, HIGH);
  digitalWrite(yellow, HIGH);
  digitalWrite(green, LOW);
  delay(10000);
 }
 else{
    changeLights();
    delay(10000);
 }

}
void changeLights(){
    //green blinked on for 3 points
    for (int i = 0; i < 3; i++) {
      digitalWrite(green, HIGH);
      delay(delayPeriod);
      digitalWrite(green, LOW);
      delay(delayPeriod);
    }
    // green off, yellow on for 3 seconds
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    delay(3000);
    // turn off yellow, then turn red on for 5 seconds
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
    delay(5000);
    // red and yellow on for 2 seconds (red is already on though)
    digitalWrite(yellow, LOW);
    delay(2000);
    // turn off red and yellow, then turn on green
    digitalWrite(yellow, HIGH);
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    delay(3000);
}