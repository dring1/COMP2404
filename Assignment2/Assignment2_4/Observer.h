#ifndef OBSERVER_H
#define OBSERVER_H

#include "PirateLine.h"
#include "Tortoise.h"
#include "Hare.h"

class Observer//class definition
{
public://function prototypes
	Observer();
	void restart();
	void battle1(PirateLine);
	void battle2(PirateLine);
	int  getTSUC();
	int  getTPART();
	int  getTFAIL();
	int  getHSUC();
	int  getHPART();
	int  getHFAIL();
	int  getPlays();

private://private data members
	int tSuc,tPart,tFail;
	int hSuc,hPart,hFail;
	PirateLine d1;
	int plays;
	Tortoise tort1,tort2;
	Hare hare1,hare2;
};
#endif