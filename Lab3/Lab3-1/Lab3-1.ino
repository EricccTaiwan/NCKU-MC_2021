int y;
void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  Serial.println("Hello!Press T/N TO TURN ON/OFF the LED.");
}
void loop() {
  if (Serial.available()){
    y = Serial.read();
    if (y == 84){
      digitalWrite(13,HIGH);
      Serial.println("LED ON.");
    }
    if (y == 78){
      digitalWrite(13,LOW);
      Serial.println("LED OFF.");
    }
  }
}
