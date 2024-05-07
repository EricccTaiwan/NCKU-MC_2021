 int  go_str = 60;  //半電80 
 int  go_turn = 60; //半電95
 int  go_noturn =30;
 int  black=200;
 int  wait_turn = 5;
 int  wait_str = 5;
 unsigned long time;
 int n=0;
 int k=0;
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
    digitalWrite(10,0);    digitalWrite(9,1);
    digitalWrite(5,0);    digitalWrite(4,1);
    Serial.println("go straight"); 
    
  }
void go_right(){
    analogWrite(11,go_noturn);
    analogWrite(6,go_turn);
    digitalWrite(10,0);digitalWrite(9,1);
    digitalWrite(5,0); digitalWrite(4,1);  
    Serial.println("go right");       
}
void go_left(){
    analogWrite(11,go_turn);
    analogWrite(6,go_noturn);
    digitalWrite(10,0);    digitalWrite(9,1);
    digitalWrite(5,0);    digitalWrite(4,1); 
   Serial.println("go left"); 
}
void go_stop(){
    analogWrite(11,0);
    analogWrite(6,0);
    digitalWrite(10,1);    digitalWrite(9,0);
    digitalWrite(5,1);    digitalWrite(4,0); 
    //Serial.println("go stop");  
}


void loop() {
  time=millis();
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
  digitalWrite(8, LOW);
  delayMicroseconds(5);
  digitalWrite(8, HIGH);     // 給 Trig 高電位，持續 10微秒
  delayMicroseconds(5);
  digitalWrite(8, LOW);
  duraton_b = pulseIn(7, HIGH);   // 收到高電位時的時間
  cm_b = (duraton_b/2) / 29.1; 

  Serial.print("cm_f          ");
  Serial.println(cm_f);
    if(cm_f<55 and cm_f>40 and middle_l<black and middle_r<black and side_l<black and side_r<black){
      while(1){
          go_stop();
          delay(50);
          int middle_r=analogRead(A3);
          int middle_l=analogRead(A4); 
          analogWrite(11,110);
          analogWrite(6,110);
          digitalWrite(10,1);    digitalWrite(9,0);
          digitalWrite(5,0);    digitalWrite(4,1); 
          delay(15);
          go_stop();
          delay(50);
        if(middle_l>black and middle_r>black){
          go_stop();
          delay(100);
          break;
        }
      }
        while(1){
          n=4;
          analogWrite(11,115);
          analogWrite(6,135);
          digitalWrite(10,1);    digitalWrite(9,0);
          digitalWrite(5,1);    digitalWrite(4,0); 

            digitalWrite(8, LOW);
            delayMicroseconds(5);
            digitalWrite(8, HIGH);     // 給 Trig 高電位，持續 10微秒
            delayMicroseconds(5);
            digitalWrite(8, LOW);
            duraton_b = pulseIn(7, HIGH);   // 收到高電位時的時間
          cm_b = (duraton_b/2) / 29.1; 
          if(cm_b>0 and cm_b<25){
            break;
          }
        }

    }
      
    
    else if (cm_b>0 and cm_b<28  and n==4){
      go_stop();
      delay(5000);
      exit(0); 
    }
  

    else if(cm_f<16 and cm_f>5){
      while(1){
          go_stop();
          delay(100);
          int middle_r=analogRead(A3);
          int middle_l=analogRead(A4); 
          analogWrite(11,85);
          analogWrite(6,120);
          digitalWrite(10,1);    digitalWrite(9,0);
          digitalWrite(5,0);    digitalWrite(4,1); 
          delay(30);
          go_stop();
          delay(100);
          if(middle_r>black and middle_l>black){
          go_stop();
          delay(150);
          break;
          n=1;
          k=1;
              }
          }
    }
    
    else if(cm_f<115 and cm_f>106 and n==1){
      while(1){
          int middle_r=analogRead(A3);
          int middle_l=analogRead(A4); 
          analogWrite(11,145);
          analogWrite(6,177);
          digitalWrite(10,0);    digitalWrite(9,1);
          digitalWrite(5,1);    digitalWrite(4,0); 

              if(side_l<black and middle_l>black ){
                go_stop();
                delay(150);
                n=2;
                break;
              }
        
          }
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
}
