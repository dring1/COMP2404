#ifndef OBSERVER_H
#define OBSERVER_H

#include "PirateLine.h"
#include "Tortoise.h"
#include "Hare.h"

class Observer
{
public:
	Observer();
	void restart();
	void battle1(PirateLine);
	void battle2(PirateLine);
	void scoreKeeper();
	int  getTSUC();
	int  getTPART();
	int  getTFAIL();
	int  getHSUC();
	int  getHPART();
	int  getHFAIL();

private:
	int tSuc,tPart,tFail;
	int hSuc,hPart,hFail;
	PirateLine d1;
	int plays;
	Tortoise tort1,tort2;
	Hare hare1,hare2;
};
#endif