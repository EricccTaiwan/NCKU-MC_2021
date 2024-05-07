int e,r,l,r1,l1,ro,lo;
float lmotorspeed,rmotorspeed,kp,kr,kl,distance;
int  go_turn = 60; //半電95
int  go_noturn = 30;
int  wait_turn = 10;
int  black=150;
void setup() {
Serial.begin(9600);
 pinMode(11,OUTPUT); //右輪
 pinMode(10,OUTPUT); 
 pinMode(9,OUTPUT); 
 pinMode(6,OUTPUT); //左輪
 pinMode(5,OUTPUT); 
 pinMode(4,OUTPUT);
 pinMode(A5,INPUT);
pinMode(A4,INPUT);
pinMode(A3,INPUT);
pinMode(A2,INPUT);
}
void go_stop(){
    analogWrite(11,0);
    analogWrite(6,0);
    digitalWrite(10,1);    
    digitalWrite(9,0);
    digitalWrite(5,1);    
    digitalWrite(4,0); 
}
void go_right(){
    analogWrite(11,go_noturn);
    analogWrite(6,go_turn);
    digitalWrite(10,1);
    digitalWrite(9,0);
    digitalWrite(5,0); 
    digitalWrite(4,1);        
}
void go_left(){
    analogWrite(11,go_turn);
    analogWrite(6,go_noturn);
    digitalWrite(10,0);    
    digitalWrite(9,1);
    digitalWrite(5,1);    
    digitalWrite(4,0);  
}
void loop() {


kp=0.15;
kr=1;
kl=1;
l1=analogRead(A5);
l=analogRead(A4);
r=analogRead(A3);
r1=analogRead(A2);
Serial.println(r);
Serial.println(l);
if(r>150){
  r=1;
}
else if(r<150){
  r=0;
}
if(l>150){
  l=1;
}
else if(l<150){
  l=0;
}
e=r-l;//循跡
if(r==0 and l==0){
  if (r1>black and l1<black){
  go_right();
  delay(20);
  go_stop();
  delay(50);
  } 
  else if (r1<black and l1>black){
  go_left();
  delay(20);
  go_stop();
  delay(50);
  }
  
}
else if(e==0){
  analogWrite(11,65);//48
  analogWrite(6,65);//50
  digitalWrite(10,0);    
  digitalWrite(9,1);
  digitalWrite(5,0);    
  digitalWrite(4,1);
  delay(100);
  go_stop();
  delay(30);
}
else if(e!=0){
  analogWrite(11,45-25*e);//48
  analogWrite(6,45+25*e);//50
  digitalWrite(10,0);    
  digitalWrite(9,1);
  digitalWrite(5,0);    
  digitalWrite(4,1);
  delay(100);
  go_stop();
  delay(30);

}
else{
    analogWrite(11,65);//48
  analogWrite(6,65);//50
  digitalWrite(10,0);    
  digitalWrite(9,1);
  digitalWrite(5,0);    
  digitalWrite(4,1);
  delay(100);
  go_stop();
  delay(30);
}


}
