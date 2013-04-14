#include <iostream>
#include "Display.h"
using namespace std;


Display::Display()//display constructor
{
	
}

void Display::flushVal(int n,double ts,double tp, double tf, double hs,double hp,double hf)//takes the int values of the stats containe in the controller
{//attempt
	cout<<"+---------------------------------------------------------+"<<endl;
	cout<<"|  Swordsman   |   % success   | % part succ.  |  % fail  |"<<endl;
	cout<<"+---------------------------------------------------------+"<<endl;
	cout<<"|  Tortoise    |       " << ts << "       |       " <<  tp << "       |    "
	<< tf << "   | " << endl;
	cout<<"+---------------------------------------------------------+"<<endl;
	cout<<"|  Hare        |       " << hs << "     |       " <<  hp << "       |      "
	<< hf << "   |" << endl;
	cout<<"+---------------------------------------------------------+"<<endl;


	cout<<"\nTotal runs: " << n << endl;
}


void heroStats(int tStr,int tHP,int tArm,int hStr,int hHP,int hArm)
{//display hero stats as a little something extra
	cout<<"+-------------------------------------------------+"<<endl;
	cout<<"|               |  Strength   |  Health  | Armor  |"<<endl;
	cout<<"+-------------------------------------------------+"<<endl;
	cout<<"|     Tortoise  |    "<<tStr<<"    |    "<<tHP<<"    |     "<<tArm<<"    |"<<endl;
	cout<<"+-------------------------------------------------+"<<endl;
	cout<<"|     Hare      |    "<<hStr<<"    |    "<<hHP<<"    |     "<<hArm<<"    |"<<endl;
	cout<<"+-------------------------------------------------+"<<endl;
}
