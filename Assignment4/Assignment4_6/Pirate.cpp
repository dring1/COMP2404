#include "Pirate.h"

Pirate::Pirate():Warrior(20,randomInt(2,4),randomInt(4,7))//call base class constructor
{
	
}
//virtual move function
void Pirate::move()
{
	//set move accordingly
	setX(getX()+1);
}

//virtual collide
void Pirate::collide(Warrior *)
{
	//nothing
}
//virtual bounds
void Pirate::bounds()
{
	if(getX()>24)
		setHealth(0);
		
}