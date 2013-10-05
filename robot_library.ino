
#include <robot.h>
#include <Servo.h>
#include <sonar.h>
Robot* robot = new Robot();

void setup () {
  Serial.begin(9600);
  robot = new Robot();
  robot->setup();
  
}

//Sonar* s1 = new Sonar(Robot::SONAR_SENSOR_FRONT_PIN);
void loop () {
 // leftTurnTest2();
 //robot->turnTest();
 //diagnostic();
//robot->circleTest();
//robot->frontSonarTest();
  //robot->followWall();
  //Serial.println(s1->getCmSampled(10));
  //robot->diagnostic();
 // delay(1030);
  //delay(1000000);
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

void leftTurnTest2(){
  robot->turnRight(5500);
  robot->brakeAll(5000);
  robot->turnLeft(5500);
  robot->brakeAll(5000);
  
  robot->turnRight(900);
  robot->brakeAll(5000);
  robot->turnLeft(900);
  robot->brakeAll(5000);
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
