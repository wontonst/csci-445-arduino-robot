#include "irsensor.h"

IrSensor::IrSensor(int pin) {
	this->pin = pin;
}
void IrSensor::setup() {

}
void IrSensor::debug() {
	while(true) {
		Serial.print("Raw: ");
		Serial.print(this->getDistanceCm());
		Serial.print("Sampled: ");
		Serial.println(this->getDistanceCmSampled(10));
	}
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
int IrSensor::getRawOutputSampled(int samples) {
	int raw = 0;
	for(int i = 0; i != samples; i++) {
		raw += this->getRawOutput();
	}
	return raw/samples;
}
double IrSensor::getRawVoltageSampled(int samples) {
	return IrSensor::rawToVoltage(this->getRawOutputSampled(samples));
}
double IrSensor::getDistanceCmSampled(int samples) {
	return IrSensor::voltageToDistanceCm(this->getRawVoltageSampled(samples));
}
double IrSensor::rawToVoltage(int raw) {
	return raw*.0048828125;
}
double IrSensor::voltageToDistanceCm(double voltage) {
	return 60.419 * pow( voltage, -1.13);
}