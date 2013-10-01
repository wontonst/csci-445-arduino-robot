#ifndef TURNABLESONAR_H_
#define TURNABLESONAR_H_

#include "irobotpart.h"
#include "servomotor.h"
#include "sonar.h"

#include <map>
#include <vector>

class TurnableSonar : IRobotPart{

private:
ServoMotor* servo_sonar_front;///<servo used to turn the sonar
Sonar* sonar_sensor_front;///<forward-facing sonar

//map<int,long> batchdata;
//vector<int> batchdatakeys;

int batchdata[5];
int batchkeys[5];

public:
TurnableSonar(int sonarpin, int servopin);
void setup();

void turnTest();

void sensorPass();
void leftRightPass();
void rightLeftPass();

bool circleFinished();
int getGreatest();
bool hasMultipleZeroes();
bool hasZeroes();
int getDirection();
};
#endif