#include "King.h"

King::King()//default constructor
{
	moveDown = false;//bool to control movement
	setHealth(1000);//set health
}

//virtual move set move accordingly
void King::move()
{
	if(moveDown == false) setY(getY()-1);
	else if(moveDown==true) setY(getY()+1);
	if(getY()==1) moveDown= true;
	else if(getY()==4) moveDown = false;
}

//virtual collide
void King::collide(Warrior *war)
{
	//do nothing
}

//virtual bounds
void King::bounds()
{
	//do nothing
}