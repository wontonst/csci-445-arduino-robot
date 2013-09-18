#ifndef IRSENSOR_H_
#define IRSENSOR_H_
#include "irobotpart.h"

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

static double rawToVoltage(int raw);
static double voltageToDistanceCm(double voltage);
};


#endif