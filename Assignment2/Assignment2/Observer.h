#ifndef OBSERVER_H
#define OBSERVER_H

#include "PirateLine.h"
#include "Tortoise.h"
#include "Hare.h"

class Observer
{
public:
	Observer();
	void beginBattle();
	void battle1(PirateLine);
	void battle2(PirateLine);
	void scoreKeeper();

private:
	int tSuc,tPart,tFail;
	int hSuc,hPart,hFail;
	PirateLine d1;
	Tortoise tort1,tort2;
	Hare hare1,hare2;
};
#endif