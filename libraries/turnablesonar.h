#ifndef TURNABLESONAR_H_
#define TURNABLESONAR_H_

#include "irobotpart.h"
#include "servomotor.h"
#include "sonar.h"


class TurnableSonar : IRobotPart{

private:
ServoMotor* servo;///<servo used to turn the sonar
Sonar* sonar;///<forward-facing sonar

int* batchdata;
int density;

public:

static const int SAMPLE_SIZE = 4;

TurnableSonar(int sonarpin, int servopin);
void setup();

/*STANDARD FUNCTIONS*/
void setDensity(int d);
void sensorPass();
void leftRightPass();
void rightLeftPass();
int getValueAt(int angle);

int getGreatestAngle();

bool circleFinished();
bool hasMultipleZeroes();
bool hasZeroes();
int getDirection();
void turnTest();
};
#endif