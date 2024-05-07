void setup() {
  // put your setup code here, to run once:
   pinMode(11,OUTPUT); //右輪
 pinMode(10,OUTPUT); 
 pinMode(9,OUTPUT); 
 pinMode(6,OUTPUT); //左輪
 pinMode(5,OUTPUT); 
 pinMode(4,OUTPUT);

}

void loop() {
    analogWrite(11,0);//63
    analogWrite(6,68);
    digitalWrite(10,0);
    digitalWrite(9,1);
    digitalWrite(5,0);
    digitalWrite(4,1);
    Serial.println("go straight");

}
