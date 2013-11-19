#include "servomotor.h"

ServoMotor::ServoMotor(int p) {
	this->pin = p;
}

void ServoMotor::setup() {
	servo.attach(this->pin);
}
void ServoMotor::debug() {
	while(true) {
		for(int i = 0 ; i != 180; i+=45) {
			Serial.print("Moving to ");
			Serial.print(i);
			this->turnTo(i);
			delay(1000);
		}
	}
}

void ServoMotor::turnTo(int i) {
	this->servo.write(i);
	this->angle = i;
}

int ServoMotor::getAngle() {
	return this->angle;
}