
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
  if(done)return;
  robot->finalInit();
//  robot->findAndGrab();
 // done=true;
//   robot->diagnostic(); 
  robot->finalPartOne();
  robot->finalPartTwo();  
  robot->finalPartThree();
  done=true;
  //while(true){
  //  robot->grabIfTriggered();
  //}  
}

void charToAction(char rpi_input){

}






