#include "Pirate.h"

Pirate::Pirate():Warrior(20,randomInt(2,4),randomInt(4,7))
{
	genType();
}

void Pirate::genType()
{
	int t = randomInt(1,100);//the type has nothing to do polymorphically but with whther it is a porc/dorc/bord for the display
	if( t<34 ) type = "dorc";
	else if(t>=34&&t<67) type = "porc";
	else type = "borc";
}

void Pirate::move()
{
	setX(getX()+1);
}

void Pirate::collide(Warrior *)
{
	
}

void Pirate::bounds()
{
	if(getX()>24)
		setHealth(0);
		
}