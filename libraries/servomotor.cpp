#include "servomotor.h"

ServoMotor::ServoMotor(int p) {
	this->pin = p;
}

void ServoMotor::setup() {
	servo.attach(this->pin);
	this->turnTo(90);
	delay(100);
}

void ServoMotor::turnTo(int i) {
	this->servo.write(i);
	this->angle = i;
}

int ServoMotor::getAngle(){
return this->angle;
}