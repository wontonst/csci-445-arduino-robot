#ifndef IRSENSOR_H_
#define IRSENSOR_H_

#include "irobotpart.h"
#include <Arduino.h>

class IrSensor : public IRobotPart{

private:
int pin;
int last_value;

protected:

public:
IrSensor(int pin);
void setup();

int getRawOutput();
double getRawVoltage();
double getDistanceCm();

int getLastRaw();
double getLastVoltage();
double getLastDistanceCm();

double rawToVoltage(int raw);
double voltageToDistanceCm(double voltage);
};


#endif