int y;
void setup() {
  Serial.begin(9600);
  Serial.println("Hello!Press T/N TO TURN ON/OFF the LED.");
}

void loop() {
  if (Serial.available() ==1){
    y = Serial.read();
    if (digitalRead(y) == 84){
      delay(200);
      digitalWrite(13,HIGH);
      Serial.println("LED ON.");
    }
    else if (digitalRead(y)==78){
      delay(200);
      digitalWrite(13,LOW);
      Serial.println("LED OFF.");
    }
  }
}
