#include "irobotpart.h"

class Motor : public IRobotPart{

private:
int pinR;
int pinL;

public:
Motor(int pinright, int pinleft);
void forward();
void backward();
void brake();

protected:

};