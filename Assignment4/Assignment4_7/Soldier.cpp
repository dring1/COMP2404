#include "Soldier.h"
#include "random.h"
#include "King.h"
#include "Timmy.h"
#include "Harold.h"
#include "Pirate.h"
#include <iostream>

using namespace std;

Soldier::Soldier():Warrior(100000,3,15)//call base class constructor
{
	
}
//virtual move
void Soldier::move()
{
	//set move accordingly to outline
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
//virtual collide
void Soldier::collide(Warrior *war)
{
	Soldier *temp = dynamic_cast<Soldier*>(war);
	if(temp!=0)//it is a soldier
	{
		setHealth(0);

	}
	else
	{
		//check type of parameter to ensure proper
		//collision with soldier
		King *kTemp = dynamic_cast<King*>(war);//cast to king
		if(kTemp!=0){//
			//war->damage(getStrength());
			//cout<<"damaging"<<endl;
			//king takes no damage from soldier
		}
		Timmy *timmyTemp = dynamic_cast<Timmy*>(war);//cast to timmy
		if(timmyTemp!=0){//if cast successful proceed
			war->damage(getStrength());
			//cout<<"damaging"<<endl;
			//timmy takes damage from soldier
		}
		Harold *haroldTemp = dynamic_cast<Harold*>(war);//cast to harold
		if(haroldTemp!=0){//if successful
			war->damage(getStrength());//deal damage to harold
			//cout<<"damaging"<<endl;
		}
		Pirate *pirateTemp = dynamic_cast<Pirate*>(war);
		if(pirateTemp!=0){//not the king then attack
			//war->damage(getStrength());
			//cout<<"damaging"<<endl;
		}
	}
}
//virtual bounds
void Soldier::bounds()
{
	if(getX()<0)
		setHealth(0);
}