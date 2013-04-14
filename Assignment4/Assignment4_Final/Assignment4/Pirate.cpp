#include "Pirate.h"

Pirate::Pirate():Warrior(20,randomInt(2,4),randomInt(4,7))//call base class constructor
{
	genType();
}

void Pirate::genType()
{
	//give the pirate a type for from dorc/borc/porc
	//randomly generated
	int rnum = randomInt(1,3);
	if(rnum==1) type = 'd';
	else if(rnum == 2) type = 'b';
	else type = 'p';
}


//return the type |||Used for display not for polymorphism|||
char Pirate::getType()
{
	return type;
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