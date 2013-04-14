#include "Dorc.h"
#include <iostream>
#include <iomanip>
using namespace std;
//include appropriate header files

//Derived class of pirate
Dorc::Dorc():Pirate(4,"Dorc")//set inheritance to base class Pirate
{

	//Pirate::setSpace(4);
}

ostream &operator<<(ostream& out, const Dorc& d)//overloaded stream insertion
{
	out << "--- Dorc id:" << d.getID() << " space:"<< d.getCellNum()<< endl; 

	return out;
}
