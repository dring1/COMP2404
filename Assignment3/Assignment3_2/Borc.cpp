
#include "Borc.h"



Borc::Borc():Pirate(5,"Borc")
{
	//Pirate::setSpace(5);
}

ostream &operator<<(ostream& out, const Borc& b)
{
	out << "--- Borc id:" << b.getID() << " space:"<< b.getCellNum()<< endl; 

	return out;
}
