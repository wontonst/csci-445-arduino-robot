#ifndef COMPASS_H_
#define COMPASS_H_

#include <Arduino.h>
#include <Wire.h>
#include "irobotpart.h"

class Compass : IRobotPart{

public:
Compass();

int getValue();
int getValueSampled();

void setup();
void debug();

bool atProperHeading(int angle, int accuracy_offset);
int headingDifference(int angle);

private:

};

#endif