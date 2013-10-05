#ifndef AOSACTION_H_
#define AOSACTION_H_

class AOSAction {
private:
	int runtime;
	int delaytime;
public:
	AOSAction(int runtime);
	AOSAction(int runtime, int delaytime);
	virtual void perform();
	virtual void tick(long elapsed) = 0;
	virtual void terminate();

};

#endif