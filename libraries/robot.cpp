#include "robot.h"

Robot::Robot() {
	this->dc_wheel_left = new DcMotor(Robot::DC_WHEEL_LEFT_PIN_L, Robot::DC_WHEEL_LEFT_PIN_R);
	this->dc_wheel_right = new DcMotor(Robot::DC_WHEEL_RIGHT_PIN_L,Robot::DC_WHEEL_RIGHT_PIN_R);
	this->ir_sensor_left = new IrSensor(Robot::IR_SENSOR_LEFT_PIN);
	this->sonar_sensor_turnable_front = new TurnableSonar(Robot::SONAR_SENSOR_FRONT_PIN,Robot::SERVO_SONAR_FRONT_PIN);
}
void Robot::setup() {
	this->dc_wheel_left->setup();
	this->dc_wheel_right->setup();
	this->ir_sensor_left->setup();
	this->sonar_sensor_turnable_front->setup();
}
void Robot::brakeAll() {
	brakeLeft();
	brakeRight();
}
void Robot::brakeAll(int time) {
	brakeAll();
	delay(time);
}
void Robot::forward() {
	this->forwardRight();
	this->forwardLeft();
}
void Robot::forward(int time) {
	this->forward();
	delay(time);
}

void Robot::reverse() {
	this->reverseRight();
	this->reverseLeft();
}
void Robot::reverse(int time) {
	this->reverse();
	delay(time);
}
void Robot::turnRight() {
	this->reverseRight();
	this->forwardLeft();
}
void Robot::turnRight(int time) {
	this->turnRight();
	delay(time);
}
void Robot::turnLeft() {
	this->reverseLeft();
	this->forwardRight();
}
void Robot::turnLeft(int time) {
	this->turnLeft();
	delay(time);
}
void Robot::brakeLeft() {
	this->dc_wheel_left->brake();
}
void Robot::brakeLeft(int time) {
	this->brakeLeft();
	delay(time);
}
void Robot::brakeRight() {
	this->dc_wheel_right->brake();
}
void Robot::brakeRight(int time) {
	this->brakeRight();
	delay(time);
}
void Robot::forwardLeft() {
	this->dc_wheel_left->forward();
}
void Robot::forwardLeft(int time) {
	this->forwardLeft();
	delay(time);
}
void Robot::forwardRight() {
	this->dc_wheel_right->forward();
}
void Robot::forwardRight(int time) {
	this->forwardRight();
	delay(time);
}
void Robot::reverseLeft() {
	this->dc_wheel_left->reverse();
}
void Robot::reverseLeft(int time) {
	this->dc_wheel_left->reverse();
	delay(time);
}
void Robot::reverseRight() {
	this->dc_wheel_right->reverse();
}
void Robot::reverseRight(int time) {
	this->dc_wheel_right->reverse();
	delay(time);
}


void Robot::turnLeftX1(int time) {
	for(int i = 0 ; i  != 10; i++) {
		this->forward(100);
		this->turnLeft(100);
		time -= 200;
		if(time <= 0)return;
	}
}
void Robot::turnLeftX2(int time) {
	this->brakeLeft();
	this->forwardRight(time);
}
void Robot::turnLeftX3(int time) {
	this->forward();
	int next = 50;
	while(time > 0) {
		if(next < time)
			next = time;
		this->reverseLeft(50);
		time -= 50;
		if(time <= 0)break;
		if(next < time)
			next = time;
		this->forward(50);
		time -= 50;
	}
}

void Robot::followWall() {
	this->brakeAll();
	delay(2000);
	while(true) {
		double currd = this->ir_sensor_left->getDistanceCm();
		if(currd < 35.0) {
			this->brakeAll(100);
			this->turnRight(200);
		} else if(currd > 40.0) {
			this->brakeAll(100);
			this->turnLeft(200);
		} else forward(200);
	}
}

void Robot::turnTest() {
	this->sonar_sensor_turnable_front->turnTest();
}

void Robot::circleTest() {

	this->sonar_sensor_turnable_front->sensorPass();
	while(true){//!this->sonar_sensor_turnable_front->circleFinished()) {
	/*	if(this->sonar_sensor_turnable_front->hasZeroes()) {
			switch(sonar_sensor_turnable_front->getDirection()) {
			case 0:
				this->turnLeft(800);
				break;
			case 1:
				this->forward(1000);
				break;
			case 2:
				this->turnRight(800);
				break;
			}
			if(sonar_sensor_turnable_front->getDirection() != 4)
				continue;
		}*/
		switch(this->sonar_sensor_turnable_front->getGreatest()) {
		case 4:
			this->turnLeft(800);
			this->brakeAll(100);
			this->forward(600);
			this->brakeAll(100);
			break;
		case 3:
			this->turnLeft(500);
			this->brakeAll(100);
			this->forward(600);
			this->brakeAll(100);
			break;
		case 2:
			this->forward(600);
			this->brakeAll(100);
			break;
		case 1:
			this->turnRight(500);
			this->brakeAll(100);
			this->forward(600);
			this->brakeAll(100);
			break;
		case 0:
			this->turnRight(800);
			this->brakeAll(100);
			this->forward(600);
			this->brakeAll(100);
			break;
		}
		this->sonar_sensor_turnable_front->sensorPass();
	}

}