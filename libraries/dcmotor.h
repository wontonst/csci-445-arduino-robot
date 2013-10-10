#ifndef DCMOTOR_H_
#define DCMOTOR_H_
#include "irobotpart.h"
#include <Arduino.h>

class DcMotor : public IRobotPart{

private:
int pinR;
int pinL;

public:
DcMotor(int pinright, int pinleft);
void setup();
void debug();

void forward();
void reverse();
void brake();

};
#endif



