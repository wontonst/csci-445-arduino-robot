
#include <robot.h>
#include <Servo.h>
#include <Wire.h>

//#include <sonar.h>
//#include <servomotor.h>

Robot* robot = new Robot();
bool done =false;


//Sonar* s1 = new Sonar(Robot::SONAR_SENSOR_FRONT_PIN);
//ServoMotor* sm = new ServoMotor(Robot::SERVO_SONAR_FRONT_PIN);

void setup () {
  Serial.begin(9600);
  robot->setup();
}
void loop () {
  if(done)delay(1000);
                                              // diagnostic(); 
  robot->finalInit();
   robot->finalPartOne();  
  done=true;
  //while(true){
  //  robot->grabIfTriggered();
  //}  
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

void charToAction(char rpi_input){

}





