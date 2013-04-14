#include <iostream>
#include "Observer.h"//import all proper and required classes and functions
#include "PirateLine.h"
#include "Tortoise.h"
#include "Hare.h"
#include "Display.h"
using namespace std;

int main()
{ 
	Observer obs;//create controller which will call the models
	Display view;//create simple view
	Hare h;
	Tortoise t;
	int x = obs.getPlays();
	double TSUC = obs.getTSUC();
	TSUC = (TSUC/x)*100;
	double TPART = obs.getTPART();
	TPART = (TPART/x)*100;
	double TFAIL = obs.getTFAIL();
	TFAIL = (TFAIL/x)*100;
	double HSUC  = obs.getHSUC();
	HSUC = (HSUC/x)*100;
	double HPART = obs.getHPART();
	HPART = (HPART/x)*100;
	double HFAIL = obs.getHFAIL();
	HFAIL = (HFAIL/x)*100;

	view.heroStats(t.getStrength(),t.getHealth(),t.getArmor(),
	h.getStrength(),h.getHealth(),h.getArmor());
	view.flushVal(x,TSUC,TPART,TFAIL,HSUC,HPART,HFAIL);
	return 0;//end the program
} 	 