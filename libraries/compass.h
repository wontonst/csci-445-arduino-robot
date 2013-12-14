#ifndef COMPASS_H_
#define COMPASS_H_

#include <Arduino.h>
#include <Wire.h>
#include "irobotpart.h"
//class FlexSensor : IRobotPart{
class Compass : IRobotPart{

public:
Compass();
int getValue();
void setup();
void debug();
private:

};

#endif