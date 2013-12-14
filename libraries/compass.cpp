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

	delay(100);
	return bearing;
}
int Compass::getValueSampled()
{
	int tot = 0;
	for(int i = 0 ; i != 5; i++) {
		tot += this->getValue():
		       }
	       return tot/5;
}
void Compass::turnTo(Robot* robot, int angle, int accuracy_offset)
{
	while(!this->atProperHeading(angle,accuracy_offset) {
	int difference = this->headingDifference(angle);
	if(difference < 0){
	
	}else{
	
	}
	}
}
int Compass::headingDifference(int angle)
{
	int difference = this->getValueSampled() - angle;
	if(difference < -360)
		difference += 360;
	if(difference > 360)
		difference -= 360);
		return difference;
	}
bool Compass::atProperHeading(int angle, int accuracy_offset)
{
	int heading = this->getValueSampled();
	if(angle - heading < accuracy_offset || heading-angle < accuracy_offset)
		return true;
	if(heading > 360-accuracy_offset) {
		if(heading + accuracy_offset - 360 > angle)
			return true;
	}
	if(heading < offset) {
		if(heading - accuracy_offset + 360 > angle)
			return true;
	}
	return false;
}