int duration, cm;         
void setup() {
  Serial.begin (9600);             // Serial Port begin
  pinMode(12, OUTPUT);        // 定義輸入及輸出 
  pinMode(11, INPUT);
}
void loop()
{
  digitalWrite(12, LOW);
  delayMicroseconds(5);
  digitalWrite(12, HIGH);     // 給 Trig 高電位，持續 10微秒
  delayMicroseconds(10);
  digitalWrite(12, LOW);
  duration = pulseIn(11, HIGH);   // 收到高電位時的時間
  cm = (duration/2) / 29.1;         // 將時間換算成距離 cm 或 inch  
  Serial.print("Distance : ");  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(500);
}
