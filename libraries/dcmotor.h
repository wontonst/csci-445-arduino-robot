#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "irobotpart.h"
class DcMotor : public IRobotPart{

private:
int pinR;
int pinL;

public:
DcMotor(int pinright, int pinleft);
void setup();

void forward();
void backward();
void brake();

};


#endif