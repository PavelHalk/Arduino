bool flag = true;

void setup() {
  pinMode (12, OUTPUT);
  pinMode (11, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode (9 , OUTPUT);
  pinMode (A0, INPUT);

  Serial.begin(9600);
}

void loop() {

  int val = analogRead(A0);
  Serial.println(val);
  
  if (val >= 100 && flag) {
    
    digitalWrite (12, LOW);
    digitalWrite (11, LOW);
    digitalWrite (10, LOW);
    digitalWrite (9, LOW);
    flag = false;
  } 
  else 
  if (val < 100 && !flag) {
    
    digitalWrite (12, HIGH);
    digitalWrite (11, HIGH);
    digitalWrite (10, HIGH);
    digitalWrite (9, HIGH);
    flag = true;
  }
}
