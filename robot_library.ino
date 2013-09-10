// Community of Robots//
 
// #include<library.c>
 
//Dc motor example code//
 
int motorpinRR = 3;                  //define digital output pin no.
int motorpinRL = 4;                  //define digital output pin no.
int motorpinLR = 5;
int motorpinLL = 6;
 
void setup () {
    pinMode(motorpinRR,OUTPUT);        //set pin 3 as output
    pinMode(motorpinRL,OUTPUT);
    pinMode(motorpinLR,OUTPUT);        // set pin 4 as output
    pinMode(motorpinLL,OUTPUT);
}

int current_velocity = 0;
 
void loop () {
    turnLeftAdvanced(0);
    c_forward(2000);
  c_brakeAll(1500);
    c_reverse(2000);
    c_brakeAll(1500);
    c_turnRight(2000);
    c_brakeAll(1500);
    c_turnLeft(5000);
    c_brakeAll(1500);
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
    digitalWrite(motorpinRR, HIGH);
    digitalWrite(motorpinRL, LOW);
    digitalWrite(motorpinLR, HIGH);
    digitalWrite(motorpinLL,LOW);
}
void c_forward(int time){
  s_forward();
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
void turnLeftAdvanced(int time){
  for(int i = 0 ;i  != 10; i++){
  c_forward(100);
  c_turnLeft(100);
  time -= 200;
  if(time <= 0)return;
  }
}
