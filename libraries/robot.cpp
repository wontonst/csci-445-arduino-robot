#include "robot.h"

Robot::Robot()
{
	this->dc_wheel_left = new DcMotor(Robot::DC_WHEEL_LEFT_PIN_L, Robot::DC_WHEEL_LEFT_PIN_R);
	this->dc_wheel_right = new DcMotor(Robot::DC_WHEEL_RIGHT_PIN_L,Robot::DC_WHEEL_RIGHT_PIN_R);
	//this->ir_sensor_left = new IrSensor(Robot::IR_SENSOR_LEFT_PIN);
	this->sonar_sensor_turnable_front = new TurnableSonar(Robot::SONAR_SENSOR_FRONT_PIN,Robot::SERVO_SONAR_FRONT_PIN);
	//this->flex_sensor = new FlexSensor(Robot::FLEX_SENSOR_PIN);
	//this->left_arm = new ServoMotor(Robot::SERVO_LEFT_ARM_PIN);
	//this->right_arm = new ServoMotor(Robot::SERVO_RIGHT_ARM_PIN);
	this->compass = new Compass();
}
void Robot::setup()
{
	if(this->dc_wheel_left != NULL)
		this->dc_wheel_left->setup();
	if(this->dc_wheel_right != NULL)
		this->dc_wheel_right->setup();
	if(this->ir_sensor_left != NULL)
		this->ir_sensor_left->setup();
	if(this->sonar_sensor_turnable_front != NULL)
		this->sonar_sensor_turnable_front->setup();
	if(this->flex_sensor!= NULL)
		this->flex_sensor->setup();
	if(this->left_arm != NULL)
		this->left_arm->setup();
	if(this->right_arm != NULL)
		this->right_arm->setup();
	if(this->compass != NULL)
		this->compass->setup();
}


void Robot::wallFollow()
{
	this->sonar_sensor_turnable_front->turnTo(90);
	delay(200);
	int distance_from_wall = this->sonar_sensor_turnable_front->getValue();
	if (distance_from_wall > 100) {
		this->sonar_sensor_turnable_front->turnTo(0);
		int distance_from_parallel_wall = this->sonar_sensor_turnable_front->getValue();

		while (distance_from_parallel_wall != 5) {
			if (distance_from_parallel_wall > 5) {
				while(distance_from_parallel_wall > 5) {
					this->turnRight(1000);
					distance_from_parallel_wall = this->sonar_sensor_turnable_front->getValue();

				}
			}

			if (distance_from_parallel_wall < 5) {
				while (distance_from_parallel_wall<5) {
					this->turnLeft(1000);
					distance_from_parallel_wall = this->sonar_sensor_turnable_front->getValue();
				}
			}
		}

		while(distance_from_wall >100) {
			this->forward(3000);
			this->sonar_sensor_turnable_front->turnTo(90);
			distance_from_wall = this->sonar_sensor_turnable_front->getValue();
		}
	}
}

bool Robot::grabIfTriggered()
{
//this->flex_sensor->debug();
	if(this->flex_sensor->triggered()) {
		this->grab(true);
		return true;
	}
	return false;

}
void Robot::grab(bool grasp)
{
	if(this->left_arm == NULL || this->right_arm == NULL)return;
	if(grasp) {
		this->right_arm->turnTo(145);
		this->left_arm->turnTo(35);
	} else {
		this->right_arm->turnTo(180);
		this->left_arm->turnTo(0);
	}
}
void Robot::brakeAll()
{
	brakeLeft();
	brakeRight();
}
void Robot::brakeAll(int time)
{
	brakeAll();
	delay(time);
}
void Robot::forward()
{
	this->forwardRight();
	this->forwardLeft();
}
void Robot::forward(int time)
{
	this->forward();
	delay(time);
}

void Robot::reverse()
{
	this->reverseRight();
	this->reverseLeft();
}
void Robot::reverse(int time)
{
	this->reverse();
	delay(time);
}
void Robot::turnRight()
{
	this->reverseRight();
	this->forwardLeft();
}
void Robot::turnRight(int time)
{
	this->turnRight();
	delay(time);
}
void Robot::turnLeft()
{
	this->reverseLeft();
	this->forwardRight();
}
void Robot::turnLeft(int time)
{
	this->turnLeft();
	delay(time);
}
void Robot::brakeLeft()
{
	this->dc_wheel_left->brake();
}
void Robot::brakeLeft(int time)
{
	this->brakeLeft();
	delay(time);
}
void Robot::brakeRight()
{
	this->dc_wheel_right->brake();
}
void Robot::brakeRight(int time)
{
	this->brakeRight();
	delay(time);
}
void Robot::forwardLeft()
{
	this->dc_wheel_left->forward();
}
void Robot::forwardLeft(int time)
{
	this->forwardLeft();
	delay(time);
}
void Robot::forwardRight()
{
	this->dc_wheel_right->forward();
}
void Robot::forwardRight(int time)
{
	this->forwardRight();
	delay(time);
}
void Robot::reverseLeft()
{
	this->dc_wheel_left->reverse();
}
void Robot::reverseLeft(int time)
{
	this->dc_wheel_left->reverse();
	delay(time);
}
void Robot::reverseRight()
{
	this->dc_wheel_right->reverse();
}
void Robot::reverseRight(int time)
{
	this->dc_wheel_right->reverse();
	delay(time);
}


void Robot::turnLeftX1(int time)
{
	for(int i = 0 ; i  != 10; i++) {
		this->forward(100);
		this->turnLeft(100);
		time -= 200;
		if(time <= 0)return;
	}
}
void Robot::turnLeftX2(int time)
{
	this->brakeLeft();
	this->forwardRight(time);
}
void Robot::turnLeftX3(int time)
{
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
void Robot::frontSonarTest()
{
	this->sonar_sensor_turnable_front->sonarDiagnostic();
}
void Robot::followWall(double distance_from_wall)
{
	this->brakeAll();
	delay(2000);
	while(true) {
		double currd = this->ir_sensor_left->getDistanceCm();
		if(currd < distance_from_wall) {
			this->brakeAll(100);
			this->turnRight(200);
		} else if(currd > 40.0) {
			this->brakeAll(100);
			this->turnLeft(200);
		} else forward(200);
	}
}

void Robot::turnTest()
{
	this->sonar_sensor_turnable_front->turnTest();
}

void Robot::circleTest()
{
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

void Robot::finalInit()
{
//	this->grab(false);
	this->sonar_sensor_turnable_front->turnTo(0);
	delay(1000);
}
void Robot::finalPartOne()
{
//this->compass->debug();
//	this->debugTurn();
	this->turnTo(Robot::NORTH_ANGLE + 90);
	this->driveToForwardWallMaintainRight();
	this->mazeLeft();
//	Serial.println("finishmaze");
	//this->findAndGrab();
	//reverse(400);
	this->forwardUntilWall();
	//turn around
	this->turnTo(Robot::NORTH_ANGLE);
}
void Robot::finalPartTwo()
{
	this->grab(true);
	this->forwardUntilWall();
	this->turnTo(Robot::NORTH_ANGLE-90);
	this->forwardUntilWall();
	this->turnTo(Robot::NORTH_ANGLE-180);
	this->forwardUntilWall();
//leaving maze
	this->turnTo(Robot::NORTH_ANGLE-85);
	this->forwardUntilWall();
	this->turnTo(Robot::NORTH_ANGLE+2);
	this->forwardUntilWall();
	this->turnTo(Robot::NORTH_ANGLE+98);
//angled approach towards first maze wall
	this->forwardUntilWall();
	this->turnTo(Robot::NORTH_ANGLE);
	this->forwardUntilWall(70);
	this->turnTo(Robot::NORTH_ANGLE-90);
	this->forwardUntilWall();

//at maze
	this->mazeRight();
	this->forwardUntilWall();
	this->reverse(200);
	this->turnTo(NORTH_ANGLE);
}
void Robot::finalPartThree()
{
	this->grab(true);
	this->forwardUntilWall();
	this->turnTo(Robot::NORTH_ANGLE+90);
	this->forwardUntilWall();
	this->turnTo(Robot::NORTH_ANGLE+180);
	this->forwardUntilWall();
	this->turnTo(Robot::NORTH_ANGLE+90);
	this->forwardUntilWall();
	this->turnTo(Robot::NORTH_ANGLE+150);
//facing far wall
	this->forwardUntilWall();
	this->turnTo(Robot::NORTH_ANGLE+90);
	this->forwardUntilWall();
	this->turnTo(Robot::NORTH_ANGLE);
	this->forwardUntilWall();
	this->grab(false);
	this->reverse(1000);
	this->brakeAll();
}
void Robot::mazeLeft()
{
	this->turnTo(Robot::NORTH_ANGLE);
	this->forwardUntilWall();
	this->turnTo(Robot::NORTH_ANGLE+90);
	this->forwardUntilWall();
	this->turnTo(Robot::NORTH_ANGLE+175);
}
void Robot::mazeRight()
{
	this->turnTo(Robot::NORTH_ANGLE);
	this->forwardUntilWall();
	this->turnTo(Robot::NORTH_ANGLE-90);
	this->forwardUntilWall();
	this->turnTo(Robot::NORTH_ANGLE-180);
}
void Robot::forwardUntilWall()
{
	this->forwardUntilWall(18);
}
void Robot::forwardUntilWall(int distance)
{
	this->sonar_sensor_turnable_front->turnTo(0);
	delay(300);
	while(this->sonar_sensor_turnable_front->getValue() > distance) {
		this->forward(170);
	}
	this->brakeAll();
}
void Robot::driveToForwardWallMaintainRight()
{
	int desired = 18;
	int margin = 3;
	float distance_from_wall;
	while(true) {
		this->sonar_sensor_turnable_front->turnTo(0);
		delay(550);
		distance_from_wall = this->sonar_sensor_turnable_front->getValue();

		if(distance_from_wall < 20)break;

		this->forward(900);
		distance_from_wall = this->sonar_sensor_turnable_front->getValue();

		if(distance_from_wall < 20)break;

		this->brakeAll();

		this->sonar_sensor_turnable_front->turnTo(90);
		delay(550);
		bool good=false;
		while(!good) {
			this->brakeAll();
			int dfsw = this->sonar_sensor_turnable_front->getValue();
			if(dfsw < desired-margin) {
				this->turnLeft(180);
			} else if(dfsw > desired+margin) {
				this->turnRight(180);
			} else good=true;
			forward(300);
		}
		this->brakeAll();
	}
}
void Robot::turnTo(int angle)
{
	this->turnTo(angle,Robot::DEFAULT_TURN_ACCURACY);
}
void Robot::turnTo(int angle, int accuracy_offset)
{
//	Serial.print("Turn to ");
//	Serial.println(angle);
	while(angle > 359) angle -= 359;
	while(angle < 0)angle += 359;

	while(!this->compass->atProperHeading(angle,accuracy_offset)) {
		delay(100);
//		Serial.print("Compensating...");
		int difference = this->compass->headingDifference(angle);
		if(difference > 0) {
			this->turnRight(150);
			//this->brakeAll(70);
			this->turnRight(50);
		} else {
			this->turnLeft(150);
			//this->brakeAll(70);
			this->turnLeft(50);
		}
		this->brakeAll(300);
//		Serial.println("done");
	}
}//first turn good next two turns bad
void Robot::debugTurn()
{
	while(true)
		for(int i = 0 ; i != 7; i++) {
			this->turnTo(45*i,15);
			delay(1000);
		}
}
void Robot::diagnostic()
{
	this->forward(2000);
	Serial.println("FORWARD TESTED");
	this->brakeAll(1500);
	Serial.println("BRAKE TESTED");
	this->reverse(1500);
	Serial.println("REVERSE TESTED");
	this->brakeAll(1500);
	this->turnRight(2000);
	Serial.println("RIGHT TURN TESTED");
	this->brakeAll(1500);
	this->turnLeft(1500);
	Serial.println("LEFT TURN TESTED");
	this->brakeAll(1500);
	Serial.println("DIAGNOSTIC COMPLETE");
}


void Robot::findAndGrab()
{
//	while(true) {
	//	if(this->grabIfTriggered())break;
	//forward(200);
	//}
	int angle = 30;
	while(true) {
		forward();
		if(this->grabIfTriggered())break;
		if(this->sonar_sensor_turnable_front->getValue() < 9) {
			this->reverse(1000);
			this->turnTo(Robot::NORTH_ANGLE + 180 + angle);
			angle-=5;
			if(angle < -30)angle = 30;
		}
	}

}