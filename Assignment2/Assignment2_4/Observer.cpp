#include <iostream>
#include "Observer.h"
#include "PirateLine.h"
#include "Tortoise.h"
#include "Hare.h"
using namespace std;

Observer::Observer()
{
	plays = 100;
	tSuc=tPart=tFail=0;//setting all counters to 0
	hSuc=hPart=hFail=0;
	d1.setSize(0);
	d1.buildPirate(10);
	restart();

}
void Observer::restart()//meat of the program
{//creates/deletes on end of scope on loop
	Tortoise temp1(0,30,5,8);//create the default values for tort and hare
	Hare	 temp2(0,30,8,5);
	int i = 0;
	while(i<plays)//run the game i to plays time
	{
		d1.setSize(0);//default size
		d1.buildPirate(10);//build 10 pirates
		PirateLine d2(d1);//Call copy constructor, tested immensely, fully functional
		tort1 = temp1;//store the default values into the heroes
		tort2 = temp1;
		hare1 = temp2;
		hare2 = temp2;
		battle1(d1);//run battle sequence first deque
		battle2(d2);//run battle sequence 2nd deque
		i++;
		//d1.clear();
		//d2.clear();
	}
}
void Observer::battle1(PirateLine battle)//tortoise yields swords
{
	//cout<<"  " <<battle.empty()<<endl;
	//cout<<"  " <<tort1.getHealth()<<endl;
	//cout<<"  " <<hare1.getHealth()<<endl;
	tort1.swordPlay(true);//tort starts at head and has sword
	while((tort1.getHealth()>0||hare1.getHealth()>0)&&battle.empty()==false)//continue fighitng so long as both heroes arend dead
	{
		if(tort1.getHealth()>0)//check if tort is still alive
		{
			int tDamage = tort1.getStrength()-(battle.front()->getArmor());//if alive, calc damage
			battle.getFront()->getData()->damage(tDamage);//retrieve pirate and apply damage
			if(battle.front()->getHealth()>0)//if pirate isnt dead strike back!
			{
				int pDamage = battle.front()->attack()-tort1.getArmor();
				tort1.damage(pDamage);//damage the tort
			} 
			else
			{
				battle.popFront();//if the pirate died pop it off the front
				if(battle.empty()==true)//check if deque is empty
					break;
			}
		}
		if(hare1.getHealth()>0)//check if hare is still alive
		{
			int hDamage = hare1.getStrength()-(battle.back()->getArmor());//if alive, calc damage
			battle.getBack()->getData()->damage(hDamage);//retrieve pirate and apply damage
			
			if(battle.back()->getHealth()>0)//if pirate isnt dead strike back!
			{
				int pDamage = battle.back()->attack() - hare1.getArmor() ;
				hare1.damage(pDamage);//damage the hare
			} 
			else//if the pirate died pop it off the back
			{
				battle.popBack();
				if(battle.empty()==true)//check if the Deque is empty
					break;
				
			}
		}
		if(battle.empty()==true) break;//break out of loop if deque is empty
	}
	if(tort1.getHealth()==0&&hare1.getHealth()==0)//increment stat accordingly
	{
		tFail++;
	}
	else if((tort1.getHealth()>0)&&(hare1.getHealth()>0))
	{
		tSuc++;
	}
	else if(tort1.getHealth()>0||hare1.getHealth()>0)
	{
		tPart++;
	}
}

void Observer::battle1(PirateLine battle)//tortoise yields swords
{
	//cout<<"  " <<battle.empty()<<endl;
	//cout<<"  " <<tort1.getHealth()<<endl;
	//cout<<"  " <<hare1.getHealth()<<endl;
	tort1.swordPlay(true);//tort starts at head and has sword
	while((tort1.getHealth()>0||hare1.getHealth()>0)&&battle.empty()==false)//continue fighitng so long as both heroes arend dead
	{
		if(tort1.getHealth()>0)//check if tort is still alive
		{
			int tDamage = tort1.getStrength()-(battle.front()->getArmor());//if alive, calc damage
			battle.getFront()->getData()->damage(tDamage);//retrieve pirate and apply damage
			if(battle.front()->getHealth()>0)//if pirate isnt dead strike back!
			{
				int pDamage = battle.front()->attack()-tort1.getArmor();
				tort1.damage(pDamage);//damage the tort
			} 
			else
			{
				battle.popFront();//if the pirate died pop it off the front
				if(battle.empty()==true)//check if deque is empty
					break;
			}
		}
		if(hare1.getHealth()>0)//check if hare is still alive
		{
			int hDamage = hare1.getStrength()-(battle.back()->getArmor());//if alive, calc damage
			battle.getBack()->getData()->damage(hDamage);//retrieve pirate and apply damage
			
			if(battle.back()->getHealth()>0)//if pirate isnt dead strike back!
			{
				int pDamage = battle.back()->attack() - hare1.getArmor() ;
				hare1.damage(pDamage);//damage the hare
			} 
			else//if the pirate died pop it off the back
			{
				battle.popBack();
				if(battle.empty()==true)//check if the Deque is empty
					break;
				
			}
		}
		if(battle.empty()==true) break;//break out of loop if deque is empty
	}
	if(tort1.getHealth()==0&&hare1.getHealth()==0)//increment stat accordingly
	{
		tFail++;
	}
	else if((tort1.getHealth()>0)&&(hare1.getHealth()>0))
	{
		tSuc++;
	}
	else if(tort1.getHealth()>0||hare1.getHealth()>0)
	{
		tPart++;
	}
}


int Observer::getTSUC()//return the stats in for out of 100
{
	return tSuc;	
}
int Observer::getTPART()
{
	return tPart;
}
int Observer::getTFAIL()
{
	return tFail;
}
int Observer::getHSUC()
{
	return hSuc;	
}
int Observer::getHPART()
{
	return hPart;
}
int Observer::getHFAIL()
{
	return hFail;
}
int Observer::getPlays()
{
	return plays;//return number of plays
}
