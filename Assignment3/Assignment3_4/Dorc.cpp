#include "Dorc.h"
#include <iostream>
#include <iomanip>
using namespace std;



Dorc::Dorc():Pirate(4,"Dorc")
{

	//Pirate::setSpace(4);
}

ostream &operator<<(ostream& out, const Dorc& d)
{
	out << "--- Dorc id:" << d.getID() << " space:"<< d.getCellNum()<< endl; 

	return out;
}
