 void setup() {
   pinMode(3,OUTPUT);
}
void loop() {
  for (int x=0;x<255;x=x+5){
  analogWrite(3,x);
   delay(100);
   }
   for (int y=255;y>0;y=y-5){
    analogWrite(3,y);
   delay(100);
    }
 }
