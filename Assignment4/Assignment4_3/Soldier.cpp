#include "Soldier.h"
#include "random.h"

Soldier::Soldier():Warrior(100000,3,15)
{
	
}

void Soldier::move()
{
	int temp_y = getY();
	setX(getX()-1);
	int rNum = randomInt(1,3);
	if(rNum==1)
		setY(getY()-1);
	else if(rNum==2)
		setY(getY()+0);
	else if(rNum==3)
		setY(getY()+1);
	if((getY()<0||getY()>5))
	{
		setY(temp_y);
	} 
}