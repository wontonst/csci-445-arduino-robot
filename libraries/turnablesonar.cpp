#include "turnablesonar.h"

TurnableSonar::TurnableSonar(int sonarpin, int servopin) {
	this->servo = new ServoMotor(servopin);
	this->sonar = new Sonar(sonarpin);
	this->setDensity(5);
}
void TurnableSonar::setup() {
	this->servo->setup();
	this->sonar->setup();
}
void TurnableSonar::setDensity(int d) {
	this->density = d;
	if(this->batchdata != NULL)
		delete[] batchdata;
	this->batchdata = new int[d];
}
void TurnableSonar::sensorPass() {
	if (this->servo->getAngle() >= 90) {
		rightLeftPass();
		return;
	}
	leftRightPass();
}
void TurnableSonar::leftRightPass() {
	int angle = 0;
	int increment = 180/this->density;
	this->servo->turnTo(angle);
	delay(500);
	for(int i = 0; i != this->density; i++) {
		this->batchdata[i] = this->sonar->getCmSampled(SAMPLE_SIZE);
		delay(50);
		angle += increment;
		this->servo->turnTo(angle);
		if(i+1 != this->density)
			delay(300);
	}
}
void TurnableSonar::rightLeftPass() {
	int angle = 180;
	int increment = 180/this->density;
	this->servo->turnTo(angle);
	delay(500);
	for(int i = this->density-1; i != -1; i--) {
		this->batchdata[i] = this->sonar->getCmSampled(SAMPLE_SIZE);
		delay(50);
		angle -= increment;
		this->servo->turnTo(angle);
		if(i-1 != -1)
			delay(300);
	}
}

int TurnableSonar::getValueAt(int angle){
return this->batchdata[angle/this->density];
}
bool TurnableSonar::circleFinished() {
	for(int i = 0 ; i != 5; i++) {
		for(int ii  = i+1; ii < 5; ii++) {
			if(this->batchdata[i]-this->batchdata[ii] > 10)
				return false;
		}
	}
	return true;
}
int TurnableSonar::getGreatestAngle() {
	int g = 0;
	for(int i = 0 ; i != 5; i++) {
		if(this->batchdata[i] == 0)return i*this->density;
		if(this->batchdata[i] > this->batchdata[g])
			g = i;
	}
	return g*this->density;
}
bool TurnableSonar::hasMultipleZeroes() {
	bool has = false;
	for(int i = 0; i  != 5; i ++) {
		if(this->batchdata[i] == 0) {
			if(has == true) return true;
			has = true;
		}
	}
	return false;
}
bool TurnableSonar::hasZeroes() {
	for(int i = 0 ; i != 5; i++) {
		if(this->batchdata[i] == 0)return true;
	}
	return false;
}
void TurnableSonar::turnTest() {
	sensorPass();
}