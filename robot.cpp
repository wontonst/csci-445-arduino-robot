#include "robot.cpp"

void Robot::brakeAll(){
    brakeLeft();
    brakeRight();
}
 void Robot::brakeAll(int time){
   brakeAll();
   delay(time);
}
void Robot::forward(){
  forwardRight();
  forwardLeft();
}
void Robot::forward(int time){
	this->forward();
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

