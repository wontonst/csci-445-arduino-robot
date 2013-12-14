#include "compass.h"
#define COMPASS_ADDRESS 0x60 //defines address of compass
#include <Wire.h>



Compass::Compass()
{

}
void Compass::setup()
{
	Wire.begin(); //conects I2C
}
void Compass::debug()
{
	while(true) {
		Serial.print(this->getValue());
		Serial.println();
		delay(500);
	}
}
int Compass::getValue()
{
	byte highByte;
	byte lowByte;

	Wire.beginTransmission(COMPASS_ADDRESS);      //starts communication with cmps03
	Wire.write(2);                         //Sends the register we wish to read
	Wire.endTransmission();

	Wire.requestFrom(COMPASS_ADDRESS, 2);        //requests high byte
	while(Wire.available() < 2);         //while there is a byte to receive
	highByte = Wire.read();           //reads the byte as an integer
	lowByte = Wire.read();
	int bearing = ((highByte<<8)+lowByte)/10;

	delay(200);
	return bearing;
}
int Compass::getValueSampled()
{
	int tot = 0;
	for(int i = 0 ; i != 5; i++) {
		tot += this->getValue();
	}
	return tot/5;
}
int Compass::headingDifference(int angle)
{
	int difference = angle-this->getValue();
	if(difference < 0) {
		if(difference < -180)
			return difference +360;
	}
	if(difference > 180)
		difference -= 360;
	return difference;
	/*
		10 330
		-40

		270 10
		100

		330, 10
		40

		200 240
		40

		240 200
		-40

		20 201
		-179

		20 199
		179

		20 200
		+-180
		*/
}
bool Compass::atProperHeading(int angle, int accuracy_offset)
{
	int diff= this->headingDifference(angle);
	if(diff < 0)diff = diff*-1;
	return (diff < accuracy_offset);
}