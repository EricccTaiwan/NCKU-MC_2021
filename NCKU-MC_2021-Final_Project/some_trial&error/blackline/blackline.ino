 int  go_str = 60;
 int  go_turn = 70;
 int  go_noturn = 10;
 int  black=480;
 int  wait_turn = 10;
 int  wait_str = 10;
 int  k=0;
 int  black_sr=500;
    
 int duration_f, cm_f,duraton_b, cm_b; 
 void setup() {
 Serial.begin(9600);
 pinMode(11,OUTPUT); //右輪
 pinMode(10,OUTPUT); 
 pinMode(9,OUTPUT); 
 pinMode(6,OUTPUT); //左輪
 pinMode(5,OUTPUT); 
 pinMode(4,OUTPUT);
  
 pinMode(A5,INPUT); //最左
 pinMode(A4,INPUT); //中左
 pinMode(A3,INPUT); //中右
 pinMode(A2,INPUT); //最右

 pinMode(2, OUTPUT);        // 前面 trig 
 pinMode(3, INPUT);         // 前面echo
 pinMode(8, OUTPUT);        // 後面trig
 pinMode(7, INPUT);         // 後面echo

}
void go_straight(){
    analogWrite(11,go_str);
    analogWrite(6,go_str);
    digitalWrite(10,1);    digitalWrite(9,0);
    digitalWrite(5,1);    digitalWrite(4,0);
    Serial.println("go straight"); 
    
  }
void go_right(){
    analogWrite(11,go_noturn);
    analogWrite(6,go_turn);
    digitalWrite(10,1);digitalWrite(9,0);
    digitalWrite(5,1); digitalWrite(4,0);  
    //Serial.println("go right");       
}
void go_big(){
    analogWrite(11,200);
    analogWrite(6,150);
    digitalWrite(10,1);digitalWrite(9,0);
    digitalWrite(5,1); digitalWrite(4,0);  
    //Serial.println("go right");       
}
void go_left(){
    analogWrite(11,go_turn);
    analogWrite(6,go_noturn);
    digitalWrite(10,1);    digitalWrite(9,0);
    digitalWrite(5,1);    digitalWrite(4,0); 
   // Serial.println("go left"); 
}
void go_stop(){
    analogWrite(11,0);
    analogWrite(6,0);
    digitalWrite(10,1);    digitalWrite(9,0);
    digitalWrite(5,1);    digitalWrite(4,0); 
    //Serial.println("go stop");  
}
void go_back(){
    analogWrite(11,go_str);
    analogWrite(6,go_str);
    digitalWrite(10,0);    digitalWrite(9,1);
    digitalWrite(5,0);    digitalWrite(4,1); 
    Serial.println("go back");  
}

void loop() {
    digitalWrite(10,1);    digitalWrite(9,0);
    digitalWrite(5,1);    digitalWrite(4,0);
  int side_r=analogRead(A2);
  int middle_r=analogRead(A3);
  int middle_l=analogRead(A4);  
  int side_l=analogRead(A5);
  Serial.print("side_r  ");
  Serial.println(side_r);
  Serial.print("middle_r  ");
  Serial.println(middle_r);
  Serial.print("middle_l  ");
  Serial.println(middle_l);
  Serial.print("side_l  ");
  Serial.println(side_l);
  delay(1000);
  digitalWrite(2, LOW);
  delayMicroseconds(5);
  digitalWrite(2, HIGH);     // 給 Trig 高電位，持續 10微秒
  delayMicroseconds(10);
  digitalWrite(2, LOW);
  duration_f = pulseIn(3, HIGH);   // 收到高電位時的時間
  cm_f = (duration_f/2) / 29.1;  
  //Serial.println(cm_f);
    if(cm_f>0 and cm_f<25){
      go_right();
      delay(wait_turn*3.5);
    }
    if(side_r>black_sr && side_l<black){
      go_right();
      delay(wait_turn);
    }
    else if (side_r<black_sr && side_l>black){
      go_left();
      delay(wait_turn);
    }
    else if (side_r < black_sr and side_l < black and middle_r < black and middle_l < black){
            go_stop();
      delay(50);
      analogWrite(11,20);
      analogWrite(6,105);
      delay(200);
      go_stop();
      delay(50);
      analogWrite(11,93);
      analogWrite(6,30);
      delay(200);

    }
    else{
      go_straight();
      delay(wait_str);
    }
  //go_stop();
  //delay(10);  
   
}
