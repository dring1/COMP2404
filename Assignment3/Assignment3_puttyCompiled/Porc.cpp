#include "Porc.h"


//derived class from Pirate Base Class


Porc::Porc():Pirate(2,"Porc")//set inheritance to pirate
{
	//Pirate::setSpace(2);
}

ostream &operator<<(ostream& out, const Porc& p)
{
	out << "--- Porc id:" << p.getID() << " space:"<< p.getCellNum()<< endl; 

	return out;
}
