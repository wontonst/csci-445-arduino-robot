#ifndef SONAR_H_
#define SONAR_H_
#include "irobotpart.h"
#include "Arduino.h"

class Sonar : IRobotPart{

private:
int pin;
public:
Sonar(int pin);
void setup();
long getRaw();
long getInches();
long getCm();

long microsecondsToInches(long microseconds);
long microsecondsToCentimeters(long microseconds);

};

#endif