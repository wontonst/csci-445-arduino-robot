#include "dcmotor.h"

Motor::Motor(int pinright,int pinleft){
this->pinR = pinright;
this->pinL = pinleft;
}
void Motor::setup(){
    pinMode(this->pinL,OUTPUT);    //set pin 3 as output
    pinMode(this->pinR,OUTPUT);
}

void Motor::forward(){
    digitalWrite(this->pinR, HIGH);
    digitalWrite(this->pinL, LOW);
}
void Motor::reverse(){
    digitalWrite(this->pinR, LOW);
    digitalWrite(this->pinL, HIGH);
}
void Motor::brake(){
    digitalWrite(this->pinR,LOW);
    digitalWrite(this->pinL,LOW);
}