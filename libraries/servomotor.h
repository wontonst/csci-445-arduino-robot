#ifndef SERVOMOTOR_H_
#define SERVOMOTOR_H_

#include "irobotpart.h"
#include "Servo.h"

class ServoMotor : IRobotPart{
private:
int pin;
int angle;
Servo servo;

public:
ServoMotor(int pin);
void setup();
void turnTo(int i);
int getAngle();

};


#endif