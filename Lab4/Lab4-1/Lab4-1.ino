float f(int x){
  float area=3.14*x*x;
  return area;
}
void setup() {
  Serial.begin(9600);
  Serial.println("輸入x=10");
  Serial.print("面積為:");
  Serial.println(f(10));
  Serial.println("輸入x=20");
  Serial.print("面積為:");
  Serial.println(f(20));
}
void loop() {
}
