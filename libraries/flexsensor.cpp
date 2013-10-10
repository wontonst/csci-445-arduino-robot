#include "flexsensor.h"
 FlexSensor::FlexSensor(int pin) {
	this->pin =pin;
}
int FlexSensor::read() {
	return analogRead(this->pin);
}
bool FlexSensor::triggered() {
	int red = this->read();
	return red < 370 || red > 500;
}
void FlexSensor::setup() {

}
void FlexSensor::debug() {
	while(true) {
		Serial.print(this->read());
		delay(100);
	}
}