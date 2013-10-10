#ifndef FLEXSENSOR_H_
#define FLEXSENSOR_H_

#include "irobotpart.h"
#include "Arduino.h"

class FlexSensor : IRobotPart{

private:
int pin;

public:
FlexSensor(int pin);
int read();
bool triggered();
void setup();
void debug();
};


#endif