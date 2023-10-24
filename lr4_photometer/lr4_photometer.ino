bool flag = true;

const int matrixPin12 = 10;
const int matrixPin11 = 11;
const int matrixPin10 = 12;
const int matrixPin9 = 13;

const int matrixPin1 = 2;
const int matrixPin2 = 3;
const int matrixPin3 = 4;
const int matrixPin4 = 5;

void setup() {
  pinMode(9, OUTPUT);
  pinMode(A0, INPUT);

  pinMode(matrixPin1, OUTPUT);
  pinMode(matrixPin2, OUTPUT);
  pinMode(matrixPin3, OUTPUT);
  pinMode(matrixPin4, OUTPUT);

  pinMode(matrixPin9, OUTPUT);
  pinMode(matrixPin10, OUTPUT);
  pinMode(matrixPin11, OUTPUT);
  pinMode(matrixPin12, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int val = analogRead(A0);
  Serial.println(val);

  if (val < 430 && flag) {

    digitalWrite(9, LOW);
    digitalWrite(matrixPin1, LOW);
    digitalWrite(matrixPin2, LOW);
    digitalWrite(matrixPin3, LOW);
    digitalWrite(matrixPin4, LOW);

    digitalWrite(matrixPin9, LOW);
    digitalWrite(matrixPin10, LOW);
    digitalWrite(matrixPin11, LOW);
    digitalWrite(matrixPin12, LOW);

    flag = false;
  } else if (val >= 430 && !flag) {

    digitalWrite(matrixPin1, HIGH);
    digitalWrite(matrixPin2, HIGH);
    digitalWrite(matrixPin3, HIGH);
    digitalWrite(matrixPin4, HIGH);

    digitalWrite(matrixPin9, HIGH);
    digitalWrite(matrixPin10, HIGH);
    digitalWrite(matrixPin11, HIGH);
    digitalWrite(matrixPin12, HIGH);

    digitalWrite(9, HIGH);
    flag = true;
  }
}
