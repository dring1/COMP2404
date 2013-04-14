#include <iostream>
#include "Observer.h"
#include "PirateLine.h"
#include "Tortoise.h"
#include "Display.h"
using namespace std;

int main()
{ 
	Observer obs;
	Display view;
	view.flushVal(100,obs.getTSUC(),obs.getTPART(),
	obs.getTFAIL(),obs.getHSUC(),obs.getHPART(),
	obs.getHFAIL());
	/*cout <<"Tort Successes "<< obs.getTSUC()<<endl;
	cout <<"Tort Partial "<< obs.getTPART()<<endl;
	cout <<"Tort Fail "<< obs.getTFAIL()<<endl;
	*/
	return 0;
} 	 