void setup() {
Serial.begin(9600);
pinMode(11,OUTPUT); 
pinMode(10,OUTPUT); 
pinMode(9,OUTPUT); 
pinMode(6,OUTPUT); 
pinMode(5,OUTPUT); 
pinMode(4,OUTPUT); 
}
void loop() {
  analogWrite(11,200);
  analogWrite(6,200);
  digitalWrite(10,1);
  digitalWrite(9,0);
  digitalWrite(5,1);
  digitalWrite(4,0);
  
}
