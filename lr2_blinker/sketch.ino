int red = 2;
int yellow = 3;
int green = 4;

int delayblink = 500;
int delayPeriod = 3000;
int delayyellow = 1000;

int blinkingtimer;

void setup() {
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);
}

void loop() {
    changeLights();  
}

void changeLights(){
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH); //green lights shine for 3 seconds
    delay(delayPeriod);
    blinkingtimer = 0;
    //green blinked on for 3 seconds
    while(blinkingtimer < 3000) {
      digitalWrite(green, LOW);
      delay(delayblink);
      digitalWrite(green, HIGH);
      delay(delayblink);
      blinkingtimer += delayblink * 2;

    }
    // green off, yellow on for 1 seconds
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    delay(delayyellow);
    // turn off yellow, then turn red on for 3 seconds
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    delay(delayPeriod);
}