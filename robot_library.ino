#include <robot.h>

Robot* robot = new Robot();

void setup () {
  robot = new Robot();
  robot->setup();
}

void loop () {
  robot->followWall()
  }

  void diagnostic(){

    robot->forward(2000);
    robot->brakeAll(1500);
    robot->reverse(1500);
    robot->brakeAll(1500);
    robot->turnRight(2000);
    robot->brakeAll(1500);
    robot->turnLeft(1500);
    robot->brakeAll(1500);
  }

