#include "sonar.h"

Sonar::Sonar(int i) {
	this->pin = i;
}

void Sonar::setup() {
}
void Sonar::debug() {
	while(true) {
		Serial.print("Raw: ");
		Serial.print(this->getCm());
		Serial.print("Sampled: ");
		Serial.println(this->getCmSampled(10));
	}
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

long Sonar::getRawSampled(long samples) {
	long tot = 0;
	for(int i = 0; i != samples; i++) {
		tot += this->getRaw();
		delay(5);
	}
	return tot/samples;
}
long Sonar::getInchesSampled(long samples) {
	return microsecondsToInches(this->getRawSampled(samples));
}
long Sonar::getCmSampled(long samples) {
	return microsecondsToCentimeters(this->getRawSampled(samples));
}

long Sonar::microsecondsToInches(long microseconds) {
	return microseconds / 74 / 2;
}

long Sonar::microsecondsToCentimeters(long microseconds) {
	return microseconds / 29 / 2;
}