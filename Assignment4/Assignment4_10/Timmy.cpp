#include "Timmy.h"

#include "random.h"
#include <iostream>
using namespace std;
Timmy::Timmy():Warrior(30,8,5)//call base class constructor
{
	
}
//virtual move 
void Timmy::move()
{
	//set move accordingly to outline
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


	//cout<<"PEWPEW"<<endl;
}


//virtual collide
void Timmy::collide(Warrior *war)
{
	//nothing
}
//vitual bounds
void Timmy::bounds()
{
	//nothing
}