#include "turnablesonar.h"

TurnableSonar::TurnableSonar(int sonarpin, int servopin) {
	this->servo_sonar_front = new ServoMotor(servopin);
	this->sonar_sensor_front = new Sonar(sonarpin);

//	this->batchdata = new int[5];
//	this->batchkeys = new int[5];
}

void TurnableSonar::setup() {
	this->servo_sonar_front->setup();
	this->sonar_sensor_front->setup();
}


void TurnableSonar::turnTest() {
	sensorPass();

}
void TurnableSonar::sensorPass() {
	this->leftRightPass();
	/*int angle = 180;
	for(int i = 4 ; i != -1; i--) {
		this->servo_sonar_front->turnTo(angle);
		delay(300);
		this->batchdata[i] = (this->batchdata[i] + this->sonar_sensor_front->getCm()) /2;
		delay(300);
		angle -= 45;
	}*/
}
void TurnableSonar::leftRightPass() {

		this->servo_sonar_front->turnTo(0);
		delay(200);
		this->batchdata[1] = this->sonar_sensor_front->getCm();
		delay(200);		this->servo_sonar_front->turnTo(45);
		delay(200);
		this->batchdata[2] = this->sonar_sensor_front->getCm();
		delay(200);		this->servo_sonar_front->turnTo(90);
		delay(200);
		this->batchdata[3] = this->sonar_sensor_front->getCm();
		delay(200);		this->servo_sonar_front->turnTo(135);
		delay(200);
		this->batchdata[4] = this->sonar_sensor_front->getCm();
		delay(200);		this->servo_sonar_front->turnTo(180);
		delay(200);
		this->batchdata[0] = this->sonar_sensor_front->getCm();
		delay(200);
/*	int angle = 0;
	for(int i = 0; i != 5; i++) {
		this->servo_sonar_front->turnTo(angle);
		delay(300);
		this->batchdata[i] = this->sonar_sensor_front->getCm();
		delay(300);
		angle += 45;
	}*/
}
void TurnableSonar::rightLeftPass() {
	int angle = 180;
	for(int i = 4; i != -1; i--) {
		this->servo_sonar_front->turnTo(angle);
		delay(300);
		this->batchdata[i] = this->sonar_sensor_front->getCm();
		delay(300);
		angle -= 45;
	}
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
int TurnableSonar::getGreatest() {
	int g = 0;
	for(int i = 0 ; i != 5; i++) {
		if(this->batchdata[i] > this->batchdata[g])
			g = i;
	}
	return g;
}
bool TurnableSonar::hasMultipleZeroes() {
	bool has = false;
	for(int i = 0; i  != 5; i ++) {
		if(this->batchdata[i] == 10000) {
			if(has == true) return true;
			has = true;
		}
	}
	return false;
}
bool TurnableSonar::hasZeroes() {
	for(int i = 0 ; i != 5; i++) {
		if(this->batchdata[i] == 10000)return true;
	}
	return false;
}
int TurnableSonar::getDirection() {
	if(this->batchdata[0] == 10000)return 2;
	if(this->batchdata[2] == 10000)return 1;
	if(this->batchdata[4] == 10000)return 0;
	return 4;
}