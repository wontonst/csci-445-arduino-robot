#include <robot.h>


int motorpinRR = 3;                  //define digital output pin no.
int motorpinRL = 4;                  //define digital output pin no.
int motorpinLR = 5;
int motorpinLL = 6;
 
Robot* robot = new Robot();
 
void setup () {
    robot = new Robot();
    pinMode(motorpinRR,OUTPUT);        //set pin 3 as output
    pinMode(motorpinRL,OUTPUT);
    pinMode(motorpinLR,OUTPUT);        // set pin 4 as output
    pinMode(motorpinLL,OUTPUT);
}
 
void loop () {
  robot->followWall();
}
  
void diagnostic(){
  
  robot->forward(2000);
robot->brakeAll(1500);
robot->reverse(1500);
robot->brakeAll(1500);
robot->turnRight(2000);
robot->brakeAll(1500);
robot->turnLeft(1500);
robot->brakeAll(1500);
}
