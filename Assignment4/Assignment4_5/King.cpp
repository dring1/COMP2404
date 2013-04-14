#include "King.h"

King::King()
{
	moveDown = false;
	setHealth(1000);
}


void King::move()
{
	if(moveDown == false) setY(getY()-1);
	else if(moveDown==true) setY(getY()+1);
	if(getY()==1) moveDown= true;
	else if(getY()==4) moveDown = false;
}

void King::collide(Warrior *war)
{
	
}

void King::bounds()
{
	
}