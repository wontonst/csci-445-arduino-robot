#include <Arduino.h>
class SerialListener{

public:
SerialListener();
void read();
float get();
private:
float value;

};