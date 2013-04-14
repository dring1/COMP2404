#include "King.h"

King::King()
{
	moveDown = false;
}


void King::move()
{
	if(moveDown == false) setY(getY()-1);
	else if(moveDown==true) setY(getY()+1);
	if(getY()==1) moveDown= true;
	else if(getY()==4) moveDown = false;
}