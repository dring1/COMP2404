#include <iostream>
#include "Observer.h"//import all proper and required classes and functions
#include "PirateLine.h"
#include "Tortoise.h"
#include "Display.h"
using namespace std;

int main()
{ 
	Observer obs;//create controller which will call the models
	Display view;//create simple view
	int x = obs.getPlays();
	double TSUC = obs.getTSUC();
	double TPART = obs.getTPART();
	double TFAIL = obs.getTFAIL();
	double HSUC  = obs.getHSUC();
	double HPART = obs.getHPART();
	double HFAIL = obs.getHFAIL();
	//view.flushVal(obs.getPlays(),(obs.getTSUC()/x)*100,(obs.getTPART()/x)*100,
	//(obs.getTFAIL()/x)*100,(obs.getHSUC()/x)*100,(obs.getHPART()/x)*100,
	//(obs.getHFAIL()/x)*100);//output the results in table
	view.flushVal(x,TSUC,TPART,TFAIL,HSUC,HPART,HFAIL);
	cout << obs.getTSUC() << endl;
	cout << obs.getTPART() << endl;
	cout << obs.getTFAIL() << endl;
	return 0;//end the program
} 	 