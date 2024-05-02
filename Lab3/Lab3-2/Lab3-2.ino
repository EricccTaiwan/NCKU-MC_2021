float x;
float y;
void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
}
void loop() {
  y = analogRead(A0);
  x=y*0.00489;
  delay(2000);
  Serial.print("類比值: ");
  Serial.println(x);
  delay(2000);
  Serial.print("信號值: ");
  Serial.println(y);
}
