int  go_str = 115;  //半電80 
 int  go_turn = 125; //半電95
 int  go_noturn = 0;
 int  black=150;
 int  wait_turn = 25;
 int  wait_str = 25;
 unsigned long time;

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
    analogWrite(6,go_str+20);
    digitalWrite(10,1);    digitalWrite(9,0);
    digitalWrite(5,1);    digitalWrite(4,0);
    Serial.println("go straight"); 
    
  }
void go_right(){
    analogWrite(11,go_noturn);
    analogWrite(6,go_turn);
    digitalWrite(10,1);digitalWrite(9,0);
    digitalWrite(5,1); digitalWrite(4,0);  
    Serial.println("go right");       
}
void go_left(){
    analogWrite(11,go_turn);
    analogWrite(6,go_noturn);
    digitalWrite(10,1);    digitalWrite(9,0);
    digitalWrite(5,1);    digitalWrite(4,0); 
   Serial.println("go left"); 
}
void go_stop(){
    analogWrite(11,0);
    analogWrite(6,0);
    digitalWrite(10,1);    digitalWrite(9,0);
    digitalWrite(5,1);    digitalWrite(4,0); 
    //Serial.println("go stop");  
}
void go_back(){
    analogWrite(11,100);
    analogWrite(6,140);
    digitalWrite(10,0);    digitalWrite(9,1);
    digitalWrite(5,0);    digitalWrite(4,1); 
    Serial.println("go back");  
}

void loop() {
   time=millis();
  //delay(1000);
  Serial.print("timeeeeeeeee   ");
  Serial.println(time/1000);
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
  digitalWrite(2, LOW);
  delayMicroseconds(5);
  digitalWrite(2, HIGH);     // 給 Trig 高電位，持續 10微秒
  delayMicroseconds(5);
  digitalWrite(2, LOW);
  duration_f = pulseIn(3, HIGH);   // 收到高電位時的時間
  cm_f = (duration_f/2) / 29.1;  
  Serial.println(cm_f);
  digitalWrite(8, LOW);
  delayMicroseconds(5);
  digitalWrite(8, HIGH);     // 給 Trig 高電位，持續 10微秒
  delayMicroseconds(5);
  digitalWrite(8, LOW);
  duraton_b = pulseIn(7, HIGH);   // 收到高電位時的時間
  cm_b = (duraton_b/2) / 29.1; 
Serial.println(cm_b);

  


    if(cm_f<45 and cm_f>40 and middle_l<black and middle_r<black and side_l<black and side_r<black ){
      while(1){
          int middle_r=analogRead(A3);
          int middle_l=analogRead(A4); 
          analogWrite(11,105);
          analogWrite(6,140);
          digitalWrite(10,1);    digitalWrite(9,0);
          digitalWrite(5,0);    digitalWrite(4,1); 
          delay(13);
          go_stop();
          delay(100);
        if(middle_l>black and middle_r>black){
          go_stop();
          delay(100);
          break;
        }
      }
        while(1){
          analogWrite(11,135);
          analogWrite(6,160);
          digitalWrite(10,0);    digitalWrite(9,1);
          digitalWrite(5,0);    digitalWrite(4,1); 
          delay(20);
          go_stop();
          delay(30);
            digitalWrite(8, LOW);
            delayMicroseconds(5);
            digitalWrite(8, HIGH);     // 給 Trig 高電位，持續 10微秒
            delayMicroseconds(5);
            digitalWrite(8, LOW);
            duraton_b = pulseIn(7, HIGH);   // 收到高電位時的時間
          cm_b = (duraton_b/2) / 29.1; 
          if(cm_b>0 and cm_b<18){
            break;
          }
        }
      
    }
    else if (cm_b>0 and cm_b<28 and middle_l<black and middle_r<black and side_l<black and side_r<black){
      go_stop();
      delay(10000);
      
    }
    
    else if(side_r<black and middle_r>black and middle_l<black and side_l<black){
      go_right();//中右黑
      delay(wait_turn);
    }
    else if (side_r<black and middle_r<black and middle_l>black and side_l<black){
      go_left();//中左黑
      delay(wait_turn);
    }
    else if(side_r>black and middle_r>black and middle_l<black and side_l<black){
      go_right();//中右黑 大右黑
      delay(wait_turn);
    }
    else if(side_r<black and middle_r<black and middle_l>black and side_l>black){
      go_left();//中左黑 大左黑
      delay(wait_turn);
    }
    
    else if(side_r>black and middle_r<black and middle_l<black and side_l<black){
      go_right(); //大右黑
      delay(wait_turn);
    }
    else if(side_r<black and middle_r<black and middle_l<black and side_l>black){
      go_left(); //大左黑
      delay(wait_turn);
    }
    
   
   else{
     go_straight();
     delay(wait_str);
    }
  go_stop();
  delay(30);
   
}
