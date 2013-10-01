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
	return microsecondsToInches(this->getRaw());
}
long Sonar::getCm() {
	return microsecondsToCentimeters(this->getRaw());
}

long Sonar::getRawSampled(int samples) {
	int tot = 0;
	for(int i = 0; i != samples; i++) {
		tot += this->getCm();
	}
	return tot/samples;
}
long Sonar::getInchesSampled(int samples) {
return microsecondsToInches(this->getRawSampled(samples));
}
long Sonar::getCmSampled(int samples) {
	return microsecondsToCentimeters(this->getRawSampled(samples));
}

long Sonar::microsecondsToInches(long microseconds) {
	return microseconds / 74 / 2;
}

long Sonar::microsecondsToCentimeters(long microseconds) {
	return microseconds / 29 / 2;
}