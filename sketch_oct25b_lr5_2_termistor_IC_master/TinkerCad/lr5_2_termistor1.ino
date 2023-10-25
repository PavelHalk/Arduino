#include <Wire.h>

void setup() 
{
  Wire.begin(5);
  Wire.onRequest(requestEvent);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  Serial.println(analogRead(A0));
  delay(1000);
}
 
void requestEvent()
{
  Wire.write(analogRead(A0));
}
