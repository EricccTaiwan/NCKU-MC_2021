 unsigned long time;     //輸入時間函式      
 int  go_str = 75;       //設定go_str為整數代表直走的PWN為75
 int  go_turn = 70;      //設定go_trun為整數代表轉彎的PWN為70
 int  go_noturn = 70;    //設定go_notrun為整數代表不轉彎的PWN為70 
 int  backk = 20;        //設定backk為整數代表反轉的PWN為20
 int  black=150;         //設定black為整數代表黑色的讀數為150
 int  wait_turn = 30;    //設定wait_turn為整數代表直角轉彎的延遲為30毫秒
 int  wait_lilturn = 25; //設定wait_lilturn為整數代表普通轉彎的延遲為25毫秒
 int  wait_str = 35;     //設定wait_str為整數代表直走的延遲為25毫秒
 int  wait_stop = 30;    //設定wait_stop為整數代表停止的延遲為25毫秒
 int  n=0;               //設定n為整數0
 int  cm_f,duration_b, cm_b,duration_f; //設定cm_f,duration_b, cm_b,duration_f為整數
 void setup() {          //開始setup設定
 Serial.begin(9600);     //設定鮑率9600
 pinMode(11,OUTPUT);     //右側馬達速度控制腳位11
 pinMode(10,OUTPUT);     //右側馬達輸出腳位10
 pinMode(9,OUTPUT);      //右側馬達輸出腳位9
 pinMode(6,OUTPUT);      //左側馬達速度控制腳位6
 pinMode(5,OUTPUT);      //左側馬達速度控制腳位5
 pinMode(4,OUTPUT);      //左側馬達速度控制腳位4
 pinMode(A5,INPUT);      //紅外線感測器輸入腳位A5
 pinMode(A4,INPUT);      //紅外線感測器輸入腳位A4
 pinMode(A3,INPUT);      //紅外線感測器輸入腳位A3
 pinMode(A2,INPUT);      //紅外線感測器輸入腳位A2
 pinMode(2, OUTPUT);     //超音波感測器trig腳位2 
 pinMode(3, INPUT);      //超音波感測器ehco腳位3 
 pinMode(8, OUTPUT);     //超音波感測器trig腳位8 
 pinMode(7, INPUT);      //超音波感測器echo腳位7 
}                        //結束setup設定
void go_straight(){            //開始go_straight函式設定
    analogWrite(11,go_str+5);  //設定右側馬達腳位11的PWN為go_str+5
    analogWrite(6,go_str);     //設定左側馬達腳位6的PWN為go_str+5
    digitalWrite(10,0);        //設定右側馬達腳位10為低電壓
    digitalWrite(9,1);         //設定右側馬達腳位9為高電壓
    digitalWrite(5,0);         //設定左側馬達腳位5為低電壓
    digitalWrite(4,1);         //設定左側馬達腳位4為高電壓
  }                            //結束go_straight函式設定
void go_right(){               //開始go_right函式設定
    analogWrite(11,go_noturn); //設定右側馬達腳位11的PWN為go_noturn
    analogWrite(6,go_turn+5);  //設定左側馬達腳位6的PWN為go_turn+5
    digitalWrite(10,1);        //設定右側馬達腳位10為高電壓
    digitalWrite(9,0);         //設定右側馬達腳位9為低電壓
    digitalWrite(5,0);         //設定左側馬達腳位5為低電壓 
    digitalWrite(4,1);         //設定左側馬達腳位4為高電壓
}                              //結束go_right函式設定  
void go_left(){                //開始go_left函式設定
    analogWrite(11,go_turn);   //設定右側馬達腳位11的PWN為go_turn
    analogWrite(6,go_noturn);  //設定左側馬達腳位6的PWN為go_noturn
    digitalWrite(10,0);        //設定右側馬達腳位10為低電壓
    digitalWrite(9,1);         //設定右側馬達腳位9為高電壓
    digitalWrite(5,1);         //設定左側馬達腳位5為高電壓
    digitalWrite(4,0);         //設定左側馬達腳位4為低電壓
}                              //結束go_left函式設定
void go_stop(){                //開始go_stop函式設定
    analogWrite(11,0);         //設定右側馬達腳位11的PWN為0
    analogWrite(6,0);          //設定左側馬達腳位6的PWN為0
    digitalWrite(10,0);        //設定右側馬達腳位10為低電壓
    digitalWrite(9,1);         //設定右側馬達腳位9為高電壓
    digitalWrite(5,0);         //設定左側馬達腳位5為低電壓
    digitalWrite(4,1);         //設定左側馬達腳位4為高電壓
}                              //結束go_stop函式設定
void go_back(){                //開始go_back函式設定
    analogWrite(11,backk);     //設定右側馬達腳位11的PWN為backk
    analogWrite(6,backk);      //設定左側馬達腳位6的PWN為backk
    digitalWrite(10,1);        //設定右側馬達腳位10為高電壓
    digitalWrite(9,0);         //設定右側馬達腳位9為低電壓
    digitalWrite(5,1);         //設定左側馬達腳位5為低電壓
    digitalWrite(4,0);         //設定左側馬達腳位4為高電壓
}                              //結束go_back函式設定
void front(){                  //開始front函式設定
    digitalWrite(2, LOW);      //trig腳位2輸出低電壓
    delayMicroseconds(5);      //延遲5微秒
    digitalWrite(2, HIGH);     //給 Trig高電位，持續5微秒
    delayMicroseconds(5);      //延遲5微秒
    digitalWrite(2, LOW);      //trig腳位2輸出低電壓
    duration_f = pulseIn(3, HIGH);   //echo腳位3收到高電位時的時間
    cm_f = (duration_f/2) / 29.1;    //將時間換算成距離cm
}                              //結束front函式設定
void loop() {                  //開始loop設定
  time=millis();               //宣告變數time回傳從開機到現在的毫秒數
  int side_r   =analogRead(A2);//宣告變數side_r為A2類比訊號輸入
  int middle_r =analogRead(A3);//宣告變數middle_r為A3類比訊號輸入
  int middle_l =analogRead(A4);//宣告變數middle_l為A4類比訊號輸入  
  int side_l   =analogRead(A5);//宣告變數side_l為A5類比訊號輸入
  if ((time/1000)>95){         //開始if迴圈，條件當時間大於95秒
    front();                   //呼叫front函式
  }                            //結束if迴圈
  if(side_r>black and side_l>black and (time/1000)<60){  //開始if迴圈，條件為side_r和side_l的讀值大於black和時間小於60秒
      go_straight();           //呼叫go_straight函式
      delay(50);               //延遲50毫秒
      go_right();              //呼叫go_right函式
      delay(200);              //延遲200微秒
      go_stop();               //呼叫go_stop函式
      delay(wait_stop);        //延遲wait_stop微數
    }                          //結束if迴圈
   else if(cm_f<50 and cm_f>40 and middle_l<black and middle_r<black and side_l<black and side_r<black ){ //開始else if迴圈，條件為前方超音波距離小於50公分和大於40公分和middle_r和middle_l的讀值大於black和side_r和side_l的讀值小於black   
      while(1){                //呼叫whie迴圈
          go_stop();           //呼叫go_stop函式
          delay(50);           //延遲50微秒
          int middle_r=analogRead(A3); //宣告變數middle_r為A3類比訊號輸入
          int middle_l=analogRead(A4); //宣告變數middle_l為A4類比訊號輸入
          analogWrite(11,110); //設定右側馬達腳位11的PWN為110
          analogWrite(6,110);  //設定左側馬達腳位6的PWN為110
          digitalWrite(10,1);  //設定右側馬達腳位10為高電壓
          digitalWrite(9,0);   //設定右側馬達腳位9為低電壓
          digitalWrite(5,0);   //設定左側馬達腳位5為低電壓 
          digitalWrite(4,1);   //設定左側馬達腳位4為高電壓
          delay(15);           //延遲15毫秒
          go_stop();           //呼叫go_stop函式
          delay(50);           //延遲50毫秒
        if(middle_l>black and middle_r>black){  //開始if迴圈，條件為middle_l和middle_r的讀值大於black
          go_stop();           //呼叫go_stop函式
          delay(100);          //延遲100毫秒
          break;               //跳出while迴圈
        }                      //結束if迴圈
      }                        //結束while迴圈
        while(1){              //開始while迴圈
          n=4;                 //宣告整數n等於4
          digitalWrite(8, LOW);//trig腳位8輸出低電壓
          delayMicroseconds(5);//延遲5微秒
          digitalWrite(8, HIGH);//給trig腳位8高電位，持續5微秒
          delayMicroseconds(5);//延遲5微秒
          digitalWrite(8, LOW);//trig腳位8輸出低電壓
          duration_b = pulseIn(7, HIGH);   //echo腳位7收到高電位時的時間
          cm_b = (duration_b/2) / 29.1;    //將時間換算成距離cm
          analogWrite(11,95);  //設定右側馬達腳位11的PWN為95
          analogWrite(6,90);   //設定左側馬達腳位6的PWN為110
          digitalWrite(10,1);  //設定右側馬達腳位10為高電壓  
          digitalWrite(9,0);   //設定右側馬達腳位9為低電壓
          digitalWrite(5,1);   //設定左側馬達腳位5為高電壓  
          digitalWrite(4,0);   //設定左側馬達腳位4為低電壓
          delay(100);          //延遲100毫秒
          if(cm_b>0 and cm_b<20){  //開始if迴圈，條件為後方超音波距離小於20公分和大於0公分
            go_stop();         //呼叫go_stop函式
            delay(1000);       //延遲1000毫秒
            break;             //跳出while迴圈
          }                    //結束if迴圈
        }                      //結束while迴圈
    }                          //結束else if迴圈
    else if (cm_b>0 and cm_b<25 and n==4){      //開始else if迴圈，條件為後方超音波距離小於25公分和大於0公分和n等於4
      go_stop();               //呼叫go_stop函式
      delay(500);              //延遲500毫秒
      exit(0);                 //停止void_loop()
    }                          //結束else if迴圈
    else if(side_r<black and middle_r>black and middle_l<black and side_l<black){   //開始else if迴圈，條件為side_r和side_l讀值小於black和middle_r和middle_l讀值小於black
      go_right();              //呼叫go_right函式
      delay(wait_lilturn);     //延遲wait_lilturn毫秒
      go_stop();               //呼叫go_stop函式
      delay(wait_stop);        //延遲wait_stop毫秒
    }                          //結束else if迴圈
    else if (side_r<black and middle_r<black and middle_l>black and side_l<black){   //開始else if迴圈，條件為side_r和middle_r和side_l讀值小於black和middle_l讀值小於black
      go_left();               //呼叫go_left函式
      delay(wait_lilturn);     //延遲wait_lilturn毫秒
      go_stop();               //呼叫go_stop函式
     delay(10);                //延遲10毫秒
    }                          //結束else if迴圈
    else if(side_r>black and middle_r>black and middle_l<black and side_l<black){    //開始else if迴圈，條件為side_r和middle_r讀值大於black和middle_l和side_l讀值小於black
      go_right();              //呼叫go_right函式
      delay(wait_turn);        //延遲wait_lilturn毫秒
      go_stop();               //呼叫go_stop函式
     delay(wait_stop);         //延遲wait_stop毫秒
    }                          //結束else if迴圈 
    else if(side_r<black and middle_r<black and middle_l>black and side_l>black){  //開始else if迴圈，條件為side_r和middle_r小於black和middle_l和side_l大於black 
      go_left();//中左黑 大左黑
      delay(wait_turn);
      go_stop();
     delay(wait_stop);
    }
    else if(side_r>black and middle_r>black and middle_l>black and side_l<black){ //開始else if 迴圈，條件為side_r和middle_r和middle_l大於black和side_l小於black
      go_right();//中右黑 大右黑
      delay(wait_turn);
      go_stop();
     delay(wait_stop);
    }
    else if(side_r<black and middle_r>black and middle_l>black and side_l>black){ //開始else if 迴圈，條件為side_r小於black和middle_r和middle_l和side_l大於black
      go_left();//中左黑 大左黑
      delay(wait_turn);
      go_stop();
     delay(wait_stop);
    }
    else if(side_r>black and middle_r<black and middle_l<black and side_l<black){  //開始else if迴圈，條件為side_r大於black和middl_r和middle_l和side_l小於black
      go_right(); //大右黑
      delay(wait_turn);
      go_stop();
     delay(wait_stop);
    }
    else if(side_r<black and middle_r<black and middle_l<black and side_l>black){  //開始else if迴圈，條件為side_r和middle_r和middle_l小於black和side_l大於black
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
