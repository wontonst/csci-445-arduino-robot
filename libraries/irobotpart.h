#ifndef IROBOTPART_H_
#define IROBOTPART_H_

class IRobotPart{

public:
virtual void setup() = 0;
virtual void debug() =0;
virtual ~IRobotPart() {}
};

#endif