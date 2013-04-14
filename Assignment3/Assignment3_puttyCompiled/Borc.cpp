
#include "Borc.h"

//include h file
//derived class of pirate
Borc::Borc():Pirate(5,"Borc")//set inheritance to pirate 
{//initialize base constructor
	//Pirate::setSpace(5);
}

ostream &operator<<(ostream& out, const Borc& b)
{
	out << "--- Borc id:" << b.getID() << " space:"<< b.getCellNum()<< endl; 

	return out;
}
