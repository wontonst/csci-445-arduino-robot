#include "seriallistener.h"
SerialListener::SerialListener(){
this->value= -1;
}
void SerialListener::read(){
  while (Serial.available())  {
    this->value = Serial.read();
//    Serial.print("character received: ");
   // Serial.println(number);
  }
}
float SerialListener::get(){
return this->value;
}

