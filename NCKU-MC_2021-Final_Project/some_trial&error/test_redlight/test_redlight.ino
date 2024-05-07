void setup() {
Serial.begin(9600);
pinMode(A5,INPUT);
pinMode(A4,INPUT);
pinMode(A3,INPUT);
pinMode(A2,INPUT);
}

void loop() {
int a2=analogRead(A2);
int a3=analogRead(A3);
int a4=analogRead(A4);
int a5=analogRead(A5);
Serial.print("a2 ");
Serial.println(a2);
Serial.print("a3 ");
Serial.println(a3);
Serial.print("a4 ");
Serial.println(a4);
Serial.print("a5 ");
Serial.println(a5);

}
