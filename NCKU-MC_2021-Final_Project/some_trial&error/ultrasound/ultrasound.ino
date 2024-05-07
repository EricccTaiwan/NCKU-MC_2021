int duration_f, cm_f;         
void setup() {
  Serial.begin (9600);             // Serial Port begin
  pinMode(2, OUTPUT);        // trig 
  pinMode(3, INPUT);
}
void loop()
{
  digitalWrite(2, LOW);
  delayMicroseconds(5);
  digitalWrite(2, HIGH);     // 給 Trig 高電位，持續 10微秒
  delayMicroseconds(10);
  digitalWrite(2, LOW);
  duration_f = pulseIn(3, HIGH);   // 收到高電位時的時間
  cm_f = (duration_f/2) / 29.1;         // 將時間換算成距離 cm 或 inch  
  Serial.print("Distance : ");  
  Serial.print(cm_f);
  Serial.print("cm");
  Serial.println();
  delay(500);
}
