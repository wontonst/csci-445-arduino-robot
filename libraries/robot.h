#ifndef ROBOT_H_
#define ROBOT_H_

#include "dcmotor.h"
#include "irsensor.h"
#include "Arduino.h"

/**
@brief high-level abstraction of the robot
*/
class Robot {
private:
	DcMotor* dc_wheel_left;///<left wheel controller
	DcMotor* dc_wheel_right;///<right wheel controller
	IrSensor* ir_sensor_front;///<forward-facing IR sensor
protected:

public:
	static const int IR_SENSOR_FRONT_PIN = 0;///<forward IR sensor pin number

	static const int DC_WHEEL_LEFT_PIN_L  = 6;
	static const int DC_WHEEL_LEFT_PIN_R = 5 ;
	static const int DC_WHEEL_RIGHT_PIN_L = 4;
	static const int DC_WHEEL_RIGHT_PIN_R = 3;

	Robot();
	
	void setup();
	
	void brakeAll();
	void brakeAll(int time);
	void forward();
	void forward(int time);
	void reverse();
	void reverse(int time);

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

	void turnLeftX1(int time);
	void turnLeftX2(int time);
	void turnLeftX3(int time);

	void followWall();

};

#endif
