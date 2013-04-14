#include <iostream>
#include "Observer.h"
#include "PirateLine.h"
#include "Tortoise.h"
#include "Hare.h"
using namespace std;

Observer::Observer()
{
	//PirateLine d;
	plays = 1;
	//cout<<"ASDASD"<<endl;
	tSuc=tPart=tFail=0;//setting all counters to 0
	hSuc=hPart=hFail=0;
	d1.setSize(0);
	d1.buildPirate(10);

	restart();
	
	
	//PirateLine d2(d1);




	/*cout << "Before Clear size:  "<< d1.getSize() << endl;
	d1.clear();
	cout << "After Clear size:  "<< d1.getSize() << endl;
	*/


	//battle1(d1);
	//beginBattle();
	//cout<<"ASDASD"<<endl;
}
void Observer::restart()
{
	Tortoise temp1(0,30,5,8);
	Hare	 temp2(0,30,8,5);
	int i = 0;
	while(i<plays)
	{
		d1.setSize(0);
		d1.buildPirate(10);
		PirateLine d2(d1);
		tort1 = temp1;
		tort2 = temp1;
		hare1 = temp2;
		hare2 = temp2;
		battle1(d1);
		battle2(d2);
		i++;
	}
}
void Observer::battle1(PirateLine battle)//tortoise yields swords
{
	cout<<"Battle 1 called"<<endl;
	tort1.swordPlay(true);
	while(((tort1.getHealth()>0||hare1.getHealth()>0))&&battle.empty()==false)//continue fighitng so long as both heroes arend dead
	{
		if(tort1.getHealth()>0)//check if tort is still alive
		{
		int tDamage = tort1.getStrength()-battle.front()->getArmor();//if alive, calc damage
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
		int hDamage = hare1.getStrength()-battle.back()->getArmor();//if alive, calc damage
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
		if(battle.empty()==true) break;
	}
	if(tort1.getHealth()==0&&hare1.getHealth()==0)
	{
		tFail++;
	}
	else if((tort1.getHealth()>0)&&(hare1.getHealth()>0))
	{
		tSuc++;
	}
	else if(tort1.getHealth()>0&&!(hare1.getHealth()>0))
	{
		tPart++;
	}
	else if(!(tort1.getHealth())>0&&(hare1.getHealth()>0))
	{
		tPart++;
	}
	cout<<" Tort Health "<< tort1.getHealth()<<endl;
	cout<<" Hare Health "<< hare1.getHealth()<<endl;
}

void Observer::battle2(PirateLine battle)
{
	cout<<"Battle 2 called"<<endl;
	hare2.swordPlay(true);
	while(((hare2.getHealth()>0||tort2.getHealth()>0))&&battle.empty()==false)//continue fighitng so long as both heroes arend dead
	{
		if(hare2.getHealth()>0)//check if tort is still alive
		{
		int hDamage = hare2.getStrength()-battle.front()->getArmor();//if alive, calc damage
			battle.getFront()->getData()->damage(hDamage);//retrieve pirate and apply damage
			if(battle.front()->getHealth()>0)//if pirate isnt dead strike back!
			{
				int pDamage = battle.front()->attack()-hare2.getArmor();
				tort1.damage(pDamage);//damage the tort
			} 
			else
			{
				battle.popFront();//if the pirate died pop it off the front
				if(battle.empty()==true)//check if deque is empty
					break;
			}
		}
		if(tort2.getHealth()>0)//check if hare is still alive
		{
		int tDamage = tort2.getStrength()-battle.back()->getArmor();//if alive, calc damage
			battle.getBack()->getData()->damage(tDamage);//retrieve pirate and apply damage
			if(battle.back()->getHealth()>0)//if pirate isnt dead strike back!
			{
				int pDamage = battle.back()->attack() - tort2.getArmor() ;
				tort2.damage(pDamage);//damage the hare
			} 
			else//if the pirate died pop it off the back
			{
				battle.popBack();
				if(battle.empty()==true)//check if the Deque is empty
					break;
			}
		}
		if(battle.empty()==true) break;
	}
	if(tort2.getHealth()==0&&hare2.getHealth()==0)
	{
		hFail++;
	}
	else if((tort2.getHealth()>0)&&(hare2.getHealth()>0))
	{
		hSuc++;
	}
	else if(tort2.getHealth()>0&&!(hare2.getHealth()>0))
	{
		tPart++;
	}
	else if(!(tort2.getHealth())>0&&(hare2.getHealth()>0))
	{
		hPart++;
	}
}

void Observer::scoreKeeper()
{
	
}

int Observer::getTSUC()
{
	return (tSuc/plays)*100;	
}
int Observer::getTPART()
{
	return (tPart/plays)*100;
}
int Observer::getTFAIL()
{
	return (tFail/plays)*100;
}
int Observer::getHSUC()
{
	return (hSuc/plays)*100;	
}
int Observer::getHPART()
{
	return (hPart/plays)*100;
}
int Observer::getHFAIL()
{
	return (hFail/plays)*100;
}
