#include "compass.h"
#define COMPASS_ADDRESS 0x60 //defines address of compass
#include <Wire.h>



Compass::Compass(){

}
void Compass::setup(){
  Wire.begin(); //conects I2C
}
void Compass::debug(){
while(true){
Serial.print(this->getValue());
Serial.println();
}
}
int Compass::getValue(){
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