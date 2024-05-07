 int duration_f, cm_f,duraton_b, cm_b; 
 int go_turn = 200;
 int go_str =150;
 int  black=480;
 int  wait_turn =80;
 int  wait_str=100;
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
    analogWrite(11,0);
    analogWrite(6,go_turn);
    digitalWrite(10,1);digitalWrite(9,0);
    digitalWrite(5,1); digitalWrite(4,0);  
    Serial.println("go right");       
}

void go_left(){
    analogWrite(11,go_turn);
    analogWrite(6,0);
    digitalWrite(10,1);    digitalWrite(9,0);
    digitalWrite(5,1);    digitalWrite(4,0); 
    Serial.println("go left"); 
}
void go_stop(){
    analogWrite(11,0);
    analogWrite(6,0);
    digitalWrite(10,1);    digitalWrite(9,0);
    digitalWrite(5,1);    digitalWrite(4,0); 
    Serial.println("go stop");  
}

void loop() {
  digitalWrite(2, LOW);
  delayMicroseconds(5);
  digitalWrite(2, HIGH);     // 給 Trig 高電位，持續 10微秒
  delayMicroseconds(10);
  digitalWrite(2, LOW);
  duration_f = pulseIn(3, HIGH);
  cm_f = (duration_f/2) / 29.1; 
  
  digitalWrite(8, LOW);
  delayMicroseconds(5);
  digitalWrite(8, HIGH);     // 給 Trig 高電位，持續 10微秒
  delayMicroseconds(10);
  digitalWrite(8, LOW);
  duraton_b = pulseIn(7, HIGH);   // 收到高電位時的時間
  cm_b = (duraton_b/2) / 29.1;         // 將時間換算成距離 cm_b 或 inch  
  int side_r=analogRead(A2);
  int middle_r=analogRead(A3);
  int middle_l=analogRead(A4);  
  int side_l=analogRead(A5);
  Serial.print("middle_r  ");
  Serial.println(middle_r);
  Serial.print("middle_l  ");
  Serial.println(middle_l);
  Serial.print("side_r  ");
  Serial.println(side_r);
  Serial.print("side_l  ");
  Serial.println(side_l);
  Serial.println("..........");
  //delay(1000);


  if((middle_r>black or middle_l>black) and side_r<black and side_l<black){ 
  Serial.println("two_black"); //中間兩個黑色<直走>或其中一黑兩白
  go_straight(); //黑>black 白<black
  delay(wait_str);
  }

  else if(middle_r<black and middle_l<black and side_r>black and side_l<black){
  Serial.println("one_right"); //最右邊黑色<右轉>
  go_right();
  delay(wait_turn);
  }

  
  else if(middle_r<black and middle_l<black and side_r<black and side_l>black){
  Serial.println("one_left");  //最左邊黑色<左轉>
  go_left();
  delay(wait_turn);
  }
  
  else if(middle_r<black and middle_l>black and side_r>black and side_l<black){
  Serial.println("two_right");
  go_right(); //右邊兩個黑色<右轉>
  delay(wait_turn);
  }
  
  else if(middle_r>black and middle_l<black and side_r<black and side_l>black){
  Serial.println("two_left");
  go_left();   //左邊兩個黑色<左轉>
  delay(wait_turn);
  }

  else if(middle_r>black and middle_l>black and side_r>black and side_l<black){
  Serial.println("three_right");
  go_right(); //中2+右邊黑色<右轉>
  delay(wait_turn);
  }
  
  else if(middle_r>black and middle_l>black and side_r<black and side_l>black){
  Serial.println("three_left");
  go_left();   //中2+左邊黑色<左轉>
  delay(wait_turn);
  }

  else if(middle_r>black and middle_l>black and side_r>black and side_l>black){
  Serial.println("all black");
  go_straight();   //全黑
  delay(wait_str);
  }
  
  else if(middle_r<black and middle_l<black and side_r<black and side_l<black){
  Serial.println("all white");
  go_straight();   //全白go
  delay(wait_str);
  }
  
  else{
    analogWrite(11,go_str-50);
    analogWrite(6,go_str-50);
    digitalWrite(10,1);    
    digitalWrite(9,0);
    digitalWrite(5,1);    
    digitalWrite(4,0);
    Serial.println("go straightttt");
    delay(30);   
  }
  go_stop();
  delayMicroseconds(5);
  Serial.println("end");
   
}
