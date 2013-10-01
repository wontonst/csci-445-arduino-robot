#include <robot.h>

#include <Servo.h>

Robot* robot = new Robot();

void setup () {
  Serial.begin(9600);
  robot = new Robot();
  robot->setup();
  
}

void loop () {
  leftTurnTest();
  //robot->followWall();
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

void leftTurnTest(){
  
  robot->turnRight(200);
  robot->brakeAll(5000);
  robot->turnLeft(200);
  robot->brakeAll(5000);
  
  robot->turnRight(400);
  robot->brakeAll(5000);
  robot->turnLeft(400);
  robot->brakeAll(5000);
  
  robot->turnRight(600);
  robot->brakeAll(5000);
  robot->turnLeft(600);
  robot->brakeAll(5000);
  
  robot->turnRight(800);
  robot->brakeAll(5000);
  robot->turnLeft(800);
  robot->brakeAll(5000);
  
  robot->turnRight(1000);
  robot->brakeAll(5000);
  robot->turnLeft(1000);
  robot->brakeAll(5000);
  
  robot->turnRight(2000);
  robot->brakeAll(5000);
  robot->turnLeft(2000);
  robot->brakeAll(10000);
  
  
}
