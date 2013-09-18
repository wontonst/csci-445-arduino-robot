#include "dcmotor.h"

DcMotor::DcMotor(int pinright,int pinleft){
this->pinR = pinright;
this->pinL = pinleft;
}
void DcMotor::setup(){
    pinMode(this->pinL,OUTPUT);    //set pin 3 as output
    pinMode(this->pinR,OUTPUT);
}

void DcMotor::forward(){
    digitalWrite(this->pinR, HIGH);
    digitalWrite(this->pinL, LOW);
}
void DcMotor::reverse(){
    digitalWrite(this->pinR, LOW);
    digitalWrite(this->pinL, HIGH);
}
void DcMotor::brake(){
    digitalWrite(this->pinR,LOW);
    digitalWrite(this->pinL,LOW);
}