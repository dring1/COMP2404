#include "Pirate.h"

Pirate::Pirate():Warrior(20,randomInt(2,4),randomInt(4,7))
{
	
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