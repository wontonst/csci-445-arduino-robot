#ifndef ROBOT_H_
#define ROBOT_H_

#include "dcmotor.h"
#include "irsensor.h"
#include "Arduino.h"
#include "turnablesonar.h"
#include "flexsensor.h"
#include "compass.h"
#include "servomotor.h"

/**
@brief high-level abstraction of the robot
*/
class Robot {
private:
	DcMotor* dc_wheel_left;///<left wheel controller
	DcMotor* dc_wheel_right;///<right wheel controller
	IrSensor* ir_sensor_left;///<left-facing IR sensor
	TurnableSonar* sonar_sensor_turnable_front;///<forward-facing sonar, turnable
	FlexSensor* flex_sensor;
	Compass* compass;
	
	ServoMotor* left_arm;
	ServoMotor* right_arm;
protected:

public:
	static const int IR_SENSOR_LEFT_PIN = 0;///<forward IR sensor pin number

	static const int DC_WHEEL_LEFT_PIN_L  = 5;
	static const int DC_WHEEL_LEFT_PIN_R = 6 ;
	static const int DC_WHEEL_RIGHT_PIN_L = 3;
	static const int DC_WHEEL_RIGHT_PIN_R = 4;
	static const int SERVO_SONAR_FRONT_PIN = 9;
	static const int SONAR_SENSOR_FRONT_PIN = 7;
	static const int FLEX_SENSOR_PIN = A1;
	
	static const int SERVO_LEFT_ARM_PIN=12;
	static const int SERVO_RIGHT_ARM_PIN=13;
	
	static const int NORTH_ANGLE = 293;

	Robot();

	void setup();

	void brakeAll();
	void brakeAll(int time);
	void forward();
	void forward(int time);
	void reverse();
	void reverse(int time);

	void wallFollow();

	void turnRight();
	void turnRight(int time);
	void turnLeft();
	void turnLeft(int time);

	void brakeLeft();
	void brakeLeft(int time);
	void brakeRight();
	void brakeRight(int time);

	void forwardLeft();
	void forwardLeft(int time);
	void forwardRight();
	void forwardRight(int time);

	void reverseLeft();
	void reverseLeft(int time);
	void reverseRight();
	void reverseRight(int time);
	
	void debugTurn();
/**
Using the compass, attempt to turn to a certain angle.
*/
	void turnTo(int angle, int accuracy_offset);


	void turnLeftX1(int time);
	void turnLeftX2(int time);
	void turnLeftX3(int time);

	void frontSonarTest();
	void followWall(double distance_from_wall);
	void turnTest();
	void circleTest();
	
	void diagnostic();
	
	void grab(bool grasp);
	bool grabIfTriggered();
	
	
	void finalInit();
	void finalPartOne();
	void finalPartTwo();
	void finalPartThree();
	
	void forwardUntilWall();
	void driveToForwardWallMaintainRight();
	void mazeRight();
};

#endif
