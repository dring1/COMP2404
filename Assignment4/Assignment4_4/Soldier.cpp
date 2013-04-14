#include "Soldier.h"
#include "random.h"
#include "King.h"
#include "Timmy.h"
#include "Harold.h"
#include "Pirate.h"
#include <iostream>

using namespace std;

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

void Soldier::collide(Warrior *war)
{
	Soldier *temp = dynamic_cast<Soldier*>(war);
	if(temp!=0)//it is a soldier
	{
		setHealth(0);

	}
	else
	{
		King *kTemp = dynamic_cast<King*>(war);
		if(kTemp!=0){//not the king then attack
			war->damage(getStrength());
			cout<<"damaging"<<endl;
		}
		Timmy *timmyTemp = dynamic_cast<Timmy*>(war);
		if(timmyTemp!=0){//not the king then attack
			war->damage(getStrength());
			cout<<"damaging"<<endl;
		}
		Harold *haroldTemp = dynamic_cast<Harold*>(war);
		if(haroldTemp!=0){//not the king then attack
			war->damage(getStrength());
			cout<<"damaging"<<endl;
		}
		Pirate *pirateTemp = dynamic_cast<Pirate*>(war);
		if(pirateTemp!=0){//not the king then attack
			war->damage(getStrength());
			cout<<"damaging"<<endl;
		}
	}
}

void Soldier::bounds()
{
	if(getX()<0)
		setHealth(0);
}