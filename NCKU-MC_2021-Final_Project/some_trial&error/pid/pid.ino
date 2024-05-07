void setup() {
Serial.begin(9600);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
}
void loop() {
int e,r,l,r1,l1;
int rmotorspeed,lmotorspeed,routput,loutput;
float kp=0.05;

r1=analogRead(A2);
r=analogRead(A3);
l=analogRead(A4);
l1=analogRead(A5);

e=l-r;

lmotorspeed=70-kp*e;
rmotorspeed=70+kp*e;

digitalWrite(5,1);
digitalWrite(4,0);
analogWrite(6,rmotorspeed);
analogWrite(11,lmotorspeed);
digitalWrite(10,1);
digitalWrite(9,0);

Serial.print(l1);
Serial.print(" ");
Serial.print(l);
Serial.print(" ");
Serial.print(r);
Serial.print(" ");
Serial.println(r1);

}
