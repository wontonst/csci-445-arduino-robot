
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
}
void loop () {
  //diagnostic();
  robot->grab(false);
  delay(1000);
  
  //while(true){
  //  robot->grabIfTriggered();
  //}
  
  
  if (Serial.available())  {
    char number = Serial.read();
    Serial.print("character received: ");
    Serial.println(number);
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

void charToAction(char rpi_input){

}




