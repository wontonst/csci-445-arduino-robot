#ifndef COMPASS_H_
#define COMPASS_H_

#include <Arduino.h>
#include <Wire.h>
#include "irobotpart.h"

/**
Class to interface with the CMPS303 connected using I2C.
*/
class Compass : IRobotPart{

private:
static const int SAMPLE_SIZE=5;

public:
Compass();
/**
Gets the raw compass bearing immediately.
*/
int getValue();
/**
Samples SAMPLE_SIZE readings and returns the average.
*/
int getValueSampled();

void setup();
void debug();

bool atProperHeading(int angle, int accuracy_offset);
int headingDifference(int angle);

private:

};

#endif