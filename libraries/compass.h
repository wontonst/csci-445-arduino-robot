#ifndef COMPASS_H_
#define COMPASS_H_

#include <Arduino.h>
#include <Wire.h>
#include "irobotpart.h"
#include "robot.h"

class Compass : IRobotPart{

public:
Compass();
int getValue();
void setup();
void debug();
void turnTo(Robot* robot, int angle);
bool atProperHeading(int angle);
int headingDifference(int angle);

private:

};

#endif