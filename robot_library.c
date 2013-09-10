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
    /*forward(2000);
  stop(1500);
    reverse(2000);
    stop(1500);
    turnRight(2000);
    stop(1500);
    turnLeft(5000);
    stop(1500);*/
}

void stop(int time){
    breakLeft(time);
    breakRight(time);
}
 
void forward(int time){
    digitalWrite(motorpinRR, HIGH);
    digitalWrite(motorpinRL, LOW);
    digitalWrite(motorpinLR, HIGH);
    digitalWrite(motorpinLL,LOW);
    delay(time);
}
 
void reverse(int time){
    digitalWrite(motorpinRR, LOW);
    digitalWrite(motorpinRL, HIGH);
    digitalWrite(motorpinLR, LOW);
    digitalWrite(motorpinLL,HIGH);
    delay(time);
}
 
void turnRight(int time)
{
    digitalWrite(motorpinRR, HIGH);
    digitalWrite(motorpinRL, LOW);
    digitalWrite(motorpinLR, LOW);
    digitalWrite(motorpinLL,HIGH);
    delay(time);
}
 
void turnLeft(int time)
{
    digitalWrite(motorpinRR, LOW);
    digitalWrite(motorpinRL, HIGH);
    digitalWrite(motorpinLR, HIGH);
    digitalWrite(motorpinLL,LOW);
    delay(time);
}
void breakLeft(int time){
    digitalWrite(motorpinLR,LOW);
    digitalWrite(motorpinLL,LOW);
    delay(time);
}
void breakRight(int time){
    digitalWrite(motorpinRR,LOW);
    digitalWrite(motorpinRL,LOW);
  delay(time);
}
void turnLeftAdvanced(int time){
  for(int i = 0 ;i  != 10; i++){
  forward(100);
  turnLeft(100);
  }
}
