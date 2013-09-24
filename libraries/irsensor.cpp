#include "irsensor.h"

IrSensor::IrSensor(int pin) {
	this->pin = pin;
}
void IrSensor::setup(){

}

int IrSensor::getLastRaw() {
	return this->last_value;
}
double IrSensor::getLastVoltage() {
	return IrSensor::rawToVoltage(this->getLastRaw());
}
double IrSensor::getLastDistanceCm() {
	return IrSensor::voltageToDistanceCm(this->getLastVoltage());
}

int IrSensor::getRawOutput() {
	return analogRead(this->pin);
}
double IrSensor::getRawVoltage() {
	return IrSensor::rawToVoltage(this->getRawOutput());
}
double IrSensor::getDistanceCm() {
	return IrSensor::voltageToDistanceCm(this->getRawVoltage());
}

 double IrSensor::rawToVoltage(int raw) {
	return raw*.0048828125;
}
 double IrSensor::voltageToDistanceCm(double voltage) {
	return 60.419 * pow( voltage, -1.13);
}