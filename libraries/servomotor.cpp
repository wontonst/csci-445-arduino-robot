#include "servomotor.h"

ServoMotor::ServoMotor(int p) {
	this->pin = p;
}

void ServoMotor::setup() {
	servo.attach(this->pin);
}

void ServoMotor::turnTo(int i) {
	this->servo.write(i);
}

