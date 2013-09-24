#ifndef IRSENSOR_H_
#define IRSENSOR_H_

#include "irobotpart.h"
#include <Arduino.h>

class IrSensor : public IRobotPart {

private:
	int pin;
	int last_value;

protected:

public:
	IrSensor(int pin);
	void setup();

	int getRawOutput();///<get the raw output from the IR sensor (not very useful)
	double getRawVoltage();///<get the raw voltage from the IR sensor (not very useful)
	double getDistanceCm();///<get the calculated distance in CM from the IR sensor

	int getLastRaw();///< get the last checked raw value (not very useful)
	double getLastVoltage();///<get the last checked value's voltage (not very useful)
	double getLastDistanceCm();///<get the last distance retrieved in cm

	double rawToVoltage(int raw);///<convert raw output to voltage
	double voltageToDistanceCm(double voltage);///<convert voltage to distance in cm
};


#endif