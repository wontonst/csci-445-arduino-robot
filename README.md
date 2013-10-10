Arduino Robot OOP-Styled
======================

Classes included with this project and reference material used.

Robot - central control mechanism

Sensors
--------------

+ IrSensor
http://communityofrobots.com/tutorial/kawal/how-use-sharp-ir-sensor-arduino
+ Sonar
http://arduino.cc/en/Tutorial/ping
+ FlexSensor
http://bildr.org/2012/11/flex-sensor-arduino/



Motors
--------------
+ DcMotor
http://communityofrobots.com/tutorial/kawal/how-drive-dc-motor-using-l293d-arduino
+ ServoMotor
http://arduino.cc/en/Tutorial/Knob


!!Sample Code
Here's some simple code to test robot movement. Before this code can run, you must adjust the pin numbers in robot.h to the pins you're using on your Arduino board.
```
Robot* robot = new Robot();
  robot->forward(2000);
  robot->brakeAll(1500);
  robot->reverse(1500);
  robot->brakeAll(1500);
  robot->turnRight(2000);
  robot->brakeAll(1500);
  robot->turnLeft(1500);
  robot->brakeAll(1500);
```