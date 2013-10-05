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
	if(d <= 1)return;
	this->density = d;
	if(this->batchdata != NULL)
		delete[] batchdata;
	this->batchdata = new int[d];
	for(int i = 0 ; i!= d; i++) {
		this->batchdata[i] = -1;
	}
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
	int increment = 165/(this->density-1);
	this->servo->turnTo(angle);
	delay(500);
	for(int i = 0; i != this->density; i++) {
		this->batchdata[i] = this->sonar->getCmSampled(SAMPLE_SIZE);
		//Serial.println(this->sonar->getCmSampled(10));
		delay(50);
		angle += increment;
		this->servo->turnTo(angle);
		//if(i+1 != this->density)
			delay(200);
	}
}
void TurnableSonar::rightLeftPass() {
	int angle = 165;
	int increment = 165/(this->density-1);
	this->servo->turnTo(angle);
	delay(500);
	for(int i = this->density-1; i != -1; i--) {
		this->batchdata[i] = this->sonar->getCmSampled(SAMPLE_SIZE);
		delay(50);
		angle -= increment;
		this->servo->turnTo(angle);
		//if(i-1 != -1)
			delay(200);
	}
}

int TurnableSonar::getValueAt(int angle) {
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
void TurnableSonar::printSonarValues() {
	Serial.print("(");
	for(int i = 0 ; i != this->density; i++) {
		Serial.print(this->batchdata[i]);
		Serial.print(" ");
	}
	Serial.println(")");
}
void TurnableSonar::sonarDiagnostic() {
	for(int i = 2; i != 20; i++) {
		this->setDensity(i);
		this->sensorPass();
		this->sensorPass();
		this->printSonarValues();
	}
}