void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
}

void loop() {
  int d2 = digitalRead(2);
  int a0 = analogRead(A0);
  
  Serial.print(d2);
  Serial.print(","); 
  Serial.println(a0);
  delay(300);

}
