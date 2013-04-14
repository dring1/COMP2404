#include "Porc.h"

Porc::Porc():Pirate(2,"Porc")
{
	//Pirate::setSpace(2);
}

ostream &operator<<(ostream& out, const Porc& p)
{
	out << "--- Porc id:" << p.getID() << " space:"<< p.getCellNum()<< endl; 

	return out;
}
