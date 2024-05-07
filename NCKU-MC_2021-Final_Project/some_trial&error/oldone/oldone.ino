 #include <Ultrasonic.h>
 Ultrasonic ultrasonic(2,3); 
 unsigned long time;
 int  go_str = 65;  //半電80 
 int  go_turn = 70; //半電95
 int  go_noturn = 70;
 int  backk = 20;
 int  black=150;
 int  wait_turn = 30;
 int  wait_lilturn = 25;
 int  wait_str = 40;
 int  wait_stop = 30;
 int  n=0;
 int  k=0;
 int  cm_first,cm_f,duration_b, cm_b,duration_f; 
 int  first=0;
 int  cross=0;
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
    analogWrite(11,go_str+5);
    analogWrite(6,go_str);
    digitalWrite(10,0);    
    digitalWrite(9,1);
    digitalWrite(5,0);    
    digitalWrite(4,1);
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
void go_stop(){
    analogWrite(11,0);
    analogWrite(6,0);
    digitalWrite(10,0);    
    digitalWrite(9,1);
    digitalWrite(5,0);    
    digitalWrite(4,1); 
}

void go_back(){
    analogWrite(11,backk);
    analogWrite(6,backk);
    digitalWrite(10,1);    
    digitalWrite(9,0);
    digitalWrite(5,1);    
    digitalWrite(4,0); 
}

void front(){
    digitalWrite(2, LOW);
    delay(0.01);
    digitalWrite(2, HIGH);     // 給 Trig 高電位，持續 10微秒
    delay(0.01);
    digitalWrite(2, LOW);
    duration_f = pulseIn(3, HIGH);   // 收到高電位時的時間
    cm_f = (duration_f/2) / 29.1; 
}
void loop() {
  time=millis();
  int side_r   =analogRead(A2);
  int middle_r =analogRead(A3);
  int middle_l =analogRead(A4);  
  int side_l   =analogRead(A5);
  if((time/1000)>140){
    front();
    }

  if(cm_first<20 and cm_first>0){//第一關進去
      while(1){
        Serial.println("innnnnnn");
          go_stop();
          delay(100);
          int middle_r=analogRead(A3);
          int middle_l=analogRead(A4); 
          analogWrite(11,85);
          analogWrite(6,120);
          digitalWrite(10,1);    
          digitalWrite(9,0);
          digitalWrite(5,0);    
          digitalWrite(4,1); 
          delay(30);
          go_stop();
          delay(100);
          n=1;
          
          if(middle_r>black and middle_l>black){
          go_stop();
          delay(150);
          first==1;
          break;
              }
          }
          
    }
  else if(side_r<black and middle_r>black and middle_l>black and side_l>black and (time/1000)>60 and cross==0){
      while(1){
      go_stop();//岔路進
      delay(10);
      analogWrite(11,83);
      analogWrite(6,75);
      digitalWrite(10,0);    
      digitalWrite(9,1);
      digitalWrite(5,0);    
      digitalWrite(4,1);
      delay(430);
      go_stop();
      delay(10);
       
      if(side_r<black){
        break;
        
        }
      }
      cross==8;
    }
    else if(side_r>black and ( middle_r>black or middle_l>black)and cross==8){
      while(1){
      go_stop();//岔路out
      delay(10);
      analogWrite(11,80);
      analogWrite(6,85);
      digitalWrite(10,0);    
      digitalWrite(9,1);
      digitalWrite(5,0);    
      digitalWrite(4,1);
      delay(450);
      go_stop();
      delay(10);
       
      if(side_l<black){
        break;
        
        }
      }
      cross==10;
    }

    else if(cm_f<50 and cm_f>40 and middle_l<black and middle_r<black and side_l<black and side_r<black and (time/1000)>120 ){ //倒車入庫
      while(1){//自轉
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
          n=4;//倒車
          digitalWrite(8, LOW);
          delayMicroseconds(5);
          digitalWrite(8, HIGH);     // 給 Trig 高電位，持續 10微秒
          delayMicroseconds(5);
          digitalWrite(8, LOW);
          duration_b = pulseIn(7, HIGH);   // 收到高電位時的時間
          cm_b = (duration_b/2) / 29.1;
          analogWrite(11,85);
          analogWrite(6,90);
          digitalWrite(10,1);    digitalWrite(9,0);
          digitalWrite(5,1);    digitalWrite(4,0);  
          if(cm_b>0 and cm_b<23){
            go_stop();
            delay(100000000);
            break;
          }
         }
    }
    else if (cm_b>0 and cm_b<28  and n==4){ //停車
      go_stop();
      delay(5000);
      exit(0); 
    }

    else if(side_r<black and middle_r>black and middle_l<black and side_l<black){
      go_right();//中右黑
      delay(wait_lilturn);
      go_stop();
      delay(wait_stop);
    }
    else if (side_r<black and middle_r<black and middle_l>black and side_l<black){
      go_left();//中左黑
      delay(wait_lilturn);
      go_stop();
     delay(10);
    }
    else if(side_r>black and middle_r>black and middle_l<black and side_l<black){
      go_right();//中右黑 大右黑
      delay(wait_turn);
      go_stop();
     delay(wait_stop);
    }
    else if(side_r<black and middle_r<black and middle_l>black and side_l>black){
      go_left();//中左黑 大左黑
      delay(wait_turn);
      go_stop();
     delay(wait_stop);
    }

    else if(side_r>black and middle_r<black and middle_l<black and side_l<black){
      go_right(); //大右黑
      delay(wait_turn);
      go_stop();
     delay(wait_stop);
    }
    else if(side_r<black and middle_r<black and middle_l<black and side_l>black){
      go_left(); //大左黑
      delay(wait_turn);
      go_stop();
     delay(wait_stop);
    }

   else{
     go_straight();
     delay(wait_str);
     go_back();
     delay(wait_stop);
    }
}
