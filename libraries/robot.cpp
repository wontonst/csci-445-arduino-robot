#include "robot.h"

Robot::Robot() {
	this->dc_wheel_left = new DcMotor(Robot::DC_WHEEL_LEFT_PIN_L, Robot::DC_WHEEL_LEFT_PIN_R);
	this->dc_wheel_right = new DcMotor(Robot::DC_WHEEL_RIGHT_PIN_L,Robot::DC_WHEEL_RIGHT_PIN_R);
	this->ir_sensor_left = new IrSensor(Robot::IR_SENSOR_LEFT_PIN);
	this->sonar_sensor_turnable_front = new TurnableSonar(Robot::SONAR_SENSOR_FRONT_PIN,Robot::SERVO_SONAR_FRONT_PIN);

	this->left_arm = new ServoMotor(12);
	this->right_arm = new ServoMotor(13);
}
void Robot::setup() {
	this->dc_wheel_left->setup();
	this->dc_wheel_right->setup();
	this->ir_sensor_left->setup();
	this->sonar_sensor_turnable_front->setup();

	this->left_arm->setup();
	this->right_arm->setup();
}

void Robot::wallFollow()
{
	this->sonar_sensor_turnable_front->turnTo(90);
	delay(200);
	int distance_from_wall = this->sonar_sensor_turnable_front->getValue();
	if (distance_from_wall > 100)
	{
		this->sonar_sensor_turnable_front->turnTo(0);
		int distance_from_parallel_wall = this->sonar_sensor_turnable_front->getValue();

		while (distance_from_parallel_wall != 5)
		{
		if (distance_from_parallel_wall > 5)
		{
			while(distance_from_parallel_wall > 5)
			{
				this->turnRight(1000);
				distance_from_parallel_wall = this->sonar_sensor_turnable_front->getValue();

			}
		}

		if (distance_from_parallel_wall < 5)
		{
			while (distance_from_parallel_wall<5)
			{
			this->turnLeft(1000);
			distance_from_parallel_wall = this->sonar_sensor_turnable_front->getValue();
			}
		}
		}

		while(distance_from_wall >100)
		{
			this->forward(3000);
			this->sonar_sensor_turnable_front->turnTo(90);
			distance_from_wall = this->sonar_turnable_front->getValue();
		}
	}
}
void Robot::grab(bool grasp) {
	if(grasp) {
		this->right_arm->turnTo(145);
		this->left_arm->turnTo(35);
	} else {
		this->right_arm->turnTo(180);
		this->left_arm->turnTo(0);
	}
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
void Robot::frontSonarTest() {
	this->sonar_sensor_turnable_front->sonarDiagnostic();
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
	int mid, left, right, farleft, farright;



	do {

		this->sonar_sensor_turnable_front->turnTo(90);
		delay(2000);
		while(this->sonar_sensor_turnable_front->getValue()  < 40) {
			reverse(150);
			brakeAll(100);
		}
		while(this->sonar_sensor_turnable_front->getValue()  < 80) {
			turnLeft(400);
			brakeAll(100);
		}

		this->sonar_sensor_turnable_front->turnTo(170);
		delay(700);
		farleft = this->sonar_sensor_turnable_front->getValue();
		//this->sonar_sensor_turnable_front->turnTo(135);
		//delay(500);
		//left = this->sonar_sensor_turnable_front->getValue();
		this->sonar_sensor_turnable_front->turnTo(90);
		delay(500);
		mid = this->sonar_sensor_turnable_front->getValue();
		//this->sonar_sensor_turnable_front->turnTo(45);
		//delay(500);
		//right = this->sonar_sensor_turnable_front->getValue();
		this->sonar_sensor_turnable_front->turnTo(10);
		delay(500);
		farright = this->sonar_sensor_turnable_front->getValue();

		if(farright > 300 || farright > 300 || mid >300) {
			forward(200);
			brakeAll(100);
		}

		Serial.print(farright);
		Serial.print(" ");
		Serial.print(right);
		Serial.print(" ");
		Serial.print(mid);
		Serial.print(" ");
		Serial.print(left);
		Serial.print(" ");
		Serial.println(farleft);
		//mid > left&&mid > right &&
		if(mid > farright && mid > farleft)break;
		if(farleft > farright) {
			turnLeft(800);
			forward(200);
			brakeAll(100);
		} else {
			turnRight(800);
			forward(200);
			brakeAll(100);
		}
	} while(farleft < 80 && farright < 80 && mid < 80);

	this->sonar_sensor_turnable_front->turnTo(90);
	delay(2000);
	forward();
	while(this->sonar_sensor_turnable_front->getValue()  > 98) {
	}
	brakeAll();
}
/*
//this->sonar_sensor_turnable_front->setDensity(7);
	this->sonar_sensor_turnable_front->sensorPass();
	int angle = this->sonar_sensor_turnable_front->getGreatestAngle();
	int value = this->sonar_sensor_turnable_front->getValueAt(90);
	while( angle != 90 || value  < 20) {
		if(value < 20) {
			reverse(200);
			this->brakeAll(100);
		}
		if(angle < 90) {
			this->turnRight(400);
			this->brakeAll(100);
		} else if (angle > 90) {
			this->turnLeft(400);
			this->brakeAll(100);
		}
		this->sonar_sensor_turnable_front->sensorPass();
		angle = this->sonar_sensor_turnable_front->getGreatestAngle();
		value = this->sonar_sensor_turnable_front->getValueAt(90);
		Serial.println(value);
	}
	delay(1000);
	Sonar* s = new Sonar(9);

	while(s->getCmSampled(5) > 20) {
		forward(100);
		brakeAll(50);
	}
}*/
/*
	this->sonar_sensor_turnable_front->sensorPass();
	do {
		int angle = this->sonar_sensor_turnable_front->getGreatestAngle();
		Serial.println(angle);
		switch(angle) {
		case 180:
			this->turnLeft(800);
			this->brakeAll(100);
			//this->forward(600);
			//this->brakeAll(100);
			break;
		case 135:
			this->turnLeft(500);
			this->brakeAll(100);
			this->forward(600);
			this->brakeAll(100);
			break;
		case 90:
			this->forward(600);
			this->brakeAll(100);
			break;
		case 45:
			this->turnRight(500);
			this->brakeAll(100);
			this->forward(600);
			this->brakeAll(100);
			break;
		case 0:
			this->turnRight(800);
			this->brakeAll(100);
			//this->forward(600);
			//this->brakeAll(100);
			break;
		}
		this->sonar_sensor_turnable_front->sensorPass();
		this->sonar_sensor_turnable_front->printSonarValues();
	}while(!this->sonar_sensor_turnable_front->circleFinished());
*/

void Robot::diagnostic() {
	this->turnRight(800);
	this->brakeAll(200);
}