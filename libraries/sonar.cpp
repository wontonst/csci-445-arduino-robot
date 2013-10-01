#include "sonar.h"

Sonar::Sonar(int i) {
	this->pin = i;
}

void Sonar::setup() {
}
long Sonar::getRaw() {
	pinMode(this->pin, OUTPUT);
	digitalWrite(this->pin, LOW);
	delayMicroseconds(2);
	digitalWrite(this->pin, HIGH);
	delayMicroseconds(5);
	digitalWrite(this->pin, LOW);
	pinMode(this->pin, INPUT);
	return pulseIn(this->pin, HIGH);
}
long Sonar::getInches() {
int result = this->getRaw();
	if(result == 0) return 10000;
	return microsecondsToInches(result);
}
long Sonar::getCm() {
int result = this->getRaw();
	if(result == 0) return 10000;
	
	Serial.println(result);
	return microsecondsToCentimeters(result);
}

long Sonar::microsecondsToInches(long microseconds) {
	return microseconds / 74 / 2;
}

long Sonar::microsecondsToCentimeters(long microseconds) {
	return microseconds / 29 / 2;
}