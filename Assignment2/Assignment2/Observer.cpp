#include <iostream>
#include "Observer.h"
#include "PirateLine.h"
#include "Tortoise.h"
#include "Hare.h"
using namespace std;

Observer::Observer()
{
	//PirateLine d;
	Tortoise temp1(0,30,5,8);
	tort1 = temp1;
	tort2 = temp1;
	Hare	temp2(0,30,8,5);
	hare1 =temp2;
	hare2 = temp2;
	d1.setSize(0);
	d1.buildPirate(10);
	PirateLine d2(d1);
	beginBattle();
	
}
void Observer::beginBattle()
{
	
}
void Observer::battle1(PirateLine battle)//tortoise yields swords
{
	tort1.swordPlay(true);
	while((tort1.getHealth()>0&&hare1.getHealth()>0))//continue fighitng so long as both heroes arend dead
	{
		if(tort1.getHealth()>0)//check if tort is still alive
		{
		int tDamage = tort1.getStrength()-battle.front()->getArmor();//if alive, calc damage
			battle.getFront->data->damage(tDamage);//retrieve pirate and apply damage
			if(battle.front()->getHealth()>0)//if pirate isnt dead strike back!
			{
				int pDamage = battle.front()->attack();
				tort1
			} 
		}
	}
}

void Observer::battle2(PirateLine battle)
{
	
}

void Observer::scoreKeeper()
{
	
}