void setup() {
  Serial.begin(9600);
}
void loop() {
  int i = analogRead(A0);
  int black =40;
  int white =50;
  if (i>500){
    Serial.println(black);
  }
  if(i<100){
    Serial.println(white);
  }
  delay(100);
}
