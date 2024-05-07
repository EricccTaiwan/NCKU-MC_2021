#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcdfunction(0x3F,2,1,0,4,5,6,7,3,POSITIVE);
int duration, cm;  
#include <dht11.h>
dht11 dhtf;
void setup() {
  Serial.begin (9600);             
  pinMode(12, OUTPUT);        
  pinMode(11, INPUT);
  lcdfunction.begin(16,2);
  lcdfunction.setCursor(0,0);
  lcdfunction.print("START WORKING!");
  delay(500);
  lcdfunction.clear();
}
void loop() {
  int y=dhtf.read(6);
  float t=dhtf.temperature;
  float h=dhtf.humidity;
  if (y==0){
  lcdfunction.setCursor(0,0);
  lcdfunction.print("temperature");
  lcdfunction.setCursor(0,1);
  lcdfunction.print(t);
  delay(500);
  lcdfunction.clear();
  lcdfunction.setCursor(0,0);
  lcdfunction.print("humidity");
  lcdfunction.setCursor(0,1);
  lcdfunction.print(h);
  delay(500);
  lcdfunction.clear();
  }
  if (y!=0) {
  lcdfunction.setCursor(0,0);
  lcdfunction.print("error");
  delay(500);
  }
  digitalWrite(12, LOW);
  delayMicroseconds(5);
  digitalWrite(12, HIGH);     // 給 Trig 高電位，持續 10微秒
  delayMicroseconds(10);
  digitalWrite(12, LOW);          
  duration = pulseIn(11, HIGH);   // 收到高電位時的時間
  cm = duration/58;         // 將時間換算成距離 cm 或 inch   
  lcdfunction.setCursor(0,0);
  lcdfunction.print("distance");
  lcdfunction.setCursor(0,1);
  lcdfunction.print(cm);
  delay(500);
  lcdfunction.clear();
}
