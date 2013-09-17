#include "motor.h"

Motor::Motor(int pinright,int pinleft){
this->pinR = pinright;
this->pinL = pinleft;
}
void Motor::setup(){
    pinMode(this->pinL,OUTPUT);    //set pin 3 as output
    pinMode(this->pinR,OUTPUT);
}

void Motor::forward(){

}
void Motor::reverse(){

}
void Motor::brake(){

}