
class Robot{
  private:
  
  protected:
  
  public:
  ContinuousMovement continuous;
  
};



class Motor{

private:
int pinR;
int pinL;
public:
Motor(int pinright, int pinleft);
protected:

};
  
  #include "motor.h"

Motor::Motor(int pinright,int pinleft){
this->pinR = pinright;
this->pinL = pinleft;
}

