
#include <robot.h>
#include <Servo.h>
//#include <sonar.h>
//#include <servomotor.h>

Robot* robot = new Robot();


//Sonar* s1 = new Sonar(Robot::SONAR_SENSOR_FRONT_PIN);
//ServoMotor* sm = new ServoMotor(Robot::SERVO_SONAR_FRONT_PIN);

void setup () {
  Serial.begin(9600);
  robot->setup();
  //sm->setup();
}
void loop () {
  //Serial.println("DIAG");
  //Serial.println("DIAG DONE");
  //diagnostic();
    robot->grab(false);
  if (Serial.available())  {
    char number = Serial.read();
    Serial.print("character received: ");
    Serial.println(number);
    
   /* 
    if(number == 'M'){
      robot->reverse(400);
    }
    else if(number == 'L'){
      robot->turnLeft(400);
    }
    else if(number == 'R'){
      Serial.println("RIGHT!");
      robot->turnRight(400);
    }
    robot->brakeAll(1);*/
}
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



