bool a;
void setup() {
  pinMode(13,OUTPUT);
  pinMode(2,INPUT);
}
void loop() {
  a=digitalRead(2);
  if (a){
  delay(200);
  digitalWrite(13,HIGH);
  }
  else{
  delay(200);
  digitalWrite(13,LOW);
  }
}
