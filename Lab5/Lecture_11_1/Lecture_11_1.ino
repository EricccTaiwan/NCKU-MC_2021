int x = 10;
void setup() {
  Serial.begin(9600);
  Serial.print("global ");
  Serial.println(x);
  int x=20;
  Serial.print("local ");
  Serial.println(x);
}
void loop() {
}
