#include <robot.h>


int motorpinRR = 3;                  //define digital output pin no.
int motorpinRL = 4;                  //define digital output pin no.
int motorpinLR = 5;
int motorpinLL = 6;
 
Robot* robot = new Robot();
 
void setup () {
//  robot = new Robot();
    pinMode(motorpinRR,OUTPUT);        //set pin 3 as output
    pinMode(motorpinRL,OUTPUT);
    pinMode(motorpinLR,OUTPUT);        // set pin 4 as output
    pinMode(motorpinLL,OUTPUT);
}
 
void loop () {
    c_forward(2000);
  c_brakeAll(1500);
    c_reverse(2000);
    c_brakeAll(1500);
    c_turnRight(2000);
    c_brakeAll(1500);
    c_turnLeft(5000);
    c_brakeAll(1500);
}
void testTurns(){
 
    turnLeftX1(2000); 
}
void s_brakeAll(){
    s_brakeLeft();
    s_brakeRight();
}
 void c_brakeAll(int time){
   s_brakeAll();
   delay(time);
 }
void s_forward(){
  s_forwardRight();
  s_forwardLeft();
}
void c_forward(int time){
  s_forwardLeft();
  s_forwardRight();
    delay(time);
}
 
void s_reverse(){
    digitalWrite(motorpinRR, LOW);
    digitalWrite(motorpinRL, HIGH);
    digitalWrite(motorpinLR, LOW);
    digitalWrite(motorpinLL,HIGH);
}
 void c_reverse(int time){
   s_reverse();
    delay(time);
 }
void s_turnRight()
{
    digitalWrite(motorpinRR, HIGH);
    digitalWrite(motorpinRL, LOW);
    digitalWrite(motorpinLR, LOW);
    digitalWrite(motorpinLL,HIGH);
}
 void c_turnRight(int time){
   s_turnRight();
    delay(time);
 }
void s_turnLeft()
{
    digitalWrite(motorpinRR, LOW);
    digitalWrite(motorpinRL, HIGH);
    digitalWrite(motorpinLR, HIGH);
    digitalWrite(motorpinLL,LOW);
}
void c_turnLeft(int time){
  s_turnLeft();
delay(time);
}
void s_brakeLeft(){
    digitalWrite(motorpinLR,LOW);
    digitalWrite(motorpinLL,LOW);
}
void s_brakeRight(){
    digitalWrite(motorpinRR,LOW);
    digitalWrite(motorpinRL,LOW);
}
void c_brakeLeft(int time){
  s_brakeLeft();
  delay(time);
}
void c_brakeRight(int time){
  s_brakeRight();
  delay(time);
}
void s_forwardLeft(){
    digitalWrite(motorpinLR, HIGH);
    digitalWrite(motorpinLL,LOW);
}
void c_forwardLeft(int time){
  s_forwardLeft();
  delay(time);
}
void s_forwardRight(){
    digitalWrite(motorpinRR, HIGH);
    digitalWrite(motorpinRL, LOW);
}
void c_forwardRight(int time){
  s_forwardRight();
  delay(time);
}
void turnLeftX1(int time){
  for(int i = 0 ;i  != 10; i++){
  c_forward(100);
  c_turnLeft(100);
  time -= 200;
  if(time <= 0)return;
  }
}
  
  void turnLeftX2(int time){
    s_brakeLeft();
    
  }
  double irRawtoV(int r){
 return r*.0048828125; 
}
double irVtoCm(double v){
  return 60.419 * pow( v, -1.13);
  //return -0.00000197 * pow(v,3) + 0.00068306 * pow(v,2) - 0.08114672 * v + 3.85711882;

//  return -2 * pow(10,-6) * pow(v,3) + .0007 * pow(v,2) - .0811 * v + 3.8571;
 //return 35.205 * pow(v,-.867); 
}
  

