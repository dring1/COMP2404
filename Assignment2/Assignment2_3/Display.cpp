#include <iostream>
#include "Display.h"
using namespace std;


Display::Display()
{
	
}

void Display::flushVal(int n,int ts,int tp, int tf, int hs,int hp,int hf)
{
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
{
	cout<<"+-------------------------------------------------+"<<endl;
	cout<<"|               |  Strength   |  Health  | Armor  |"<<endl;
	cout<<"+-------------------------------------------------+"<<endl;
	cout<<"|     Tortoise  |    "<<tStr<<"    |    "<<tHP<<"    |     "<<tArm<<"    |"<<endl;
	cout<<"+-------------------------------------------------+"<<endl;
	cout<<"|     Hare      |    "<<hStr<<"    |    "<<hHP<<"    |     "<<hArm<<"    |"<<endl;
	cout<<"+-------------------------------------------------+"<<endl;
}
