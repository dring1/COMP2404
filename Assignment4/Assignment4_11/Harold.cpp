#include "Harold.h"
#include "random.h"
//default constructor
Harold::Harold():Warrior(30,5,8)//call base class constructor
{
	
}

void Harold::move()//virtual move function
{
	//generate move location accordingly
	int temp_x = getX();
	int temp_y = getY();
	setX(getX()+1);
	int rNum = randomInt(1,3);
	if(rNum==1)
		setY(getY()-1);
	else if(rNum==2)
		setY(getY()+0);
	else if(rNum==3)
		setY(getY()+1);
	if(getX()<0||getX()>24||getY()<0||getY()>5)
	{
		setX(temp_x);
		setY(temp_y);
	} 
}

//virtual collide
void Harold::collide(Warrior *war)
{
	//nothing	
}
//virtual bounds
void Harold::bounds()
{
	//nothing
}