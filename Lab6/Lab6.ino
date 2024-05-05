#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcdfunction(0x3F,2,1,0,4,5,6,7,3,POSITIVE);
void setup() {
  // put your setup code here, to run once:
  lcdfunction.begin(16,2);
  lcdfunction.setCursor(0,0);
  lcdfunction.print("HELLO WORLD!");
}
void loop() {
  // put your main code here, to run repeatedly:
  lcdfunction.setCursor(0,1);
  lcdfunction.print(millis()/1000);
}
