#include "dcmotor.h"
#include "irsensor.h"

class Robot {
private:
	DcMotor* dc_wheel_left;
	DcMotor* dc_wheel_right;
	IrSensor* ir_sensor_front;
protected:

public:
	static const int IR_SENSOR_FRONT_PIN = 0;

	static const int DC_WHEEL_LEFT_PIN_L  = 6;
	static const int DC_WHEEL_LEFT_PIN_R = 5 ;
	static const int DC_WHEEL_RIGHT_PIN_L = 4;
	static const int DC_WHEEL_RIGH_PIN_R = 3;

	Robot();
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

	void turnLeftX1(int time);
	void turnLeftX2(int time);
	void turnLeftX3(int time);

};
