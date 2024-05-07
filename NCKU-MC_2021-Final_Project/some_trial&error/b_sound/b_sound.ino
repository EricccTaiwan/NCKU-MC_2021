int duraton_b, cm_b;         
void setup() {
  Serial.begin (9600);             // Serial Port begin
  pinMode(8, OUTPUT);        // green
  pinMode(7, INPUT);
}
void loop()
{
  digitalWrite(8, LOW);
  delayMicroseconds(5);
  digitalWrite(8, HIGH);     // 給 Trig 高電位，持續 10微秒
  delayMicroseconds(10);
  digitalWrite(8, LOW);
  duraton_b = pulseIn(7, HIGH);   // 收到高電位時的時間
  cm_b = (duraton_b/2) / 29.1;         // 將時間換算成距離 cm_b 或 inch  
  Serial.print("Distance : ");  
  Serial.print(cm_b);
  Serial.print("cm");
  Serial.println();
  delay(500);
}
