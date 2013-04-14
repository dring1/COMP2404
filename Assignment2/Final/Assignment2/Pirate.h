#ifndef PIRATE_H
#define PIRATE_H

#include "random.h"

class Pirate//class definition
{
public://function prototypes
	Pirate();
	void setX(int);
	void setHealth(int);
	void setStrength(int);
	void setArmor(int);
	void update();
	int  getX();
	int  getHealth();
	int	 getStrength();
	int  getArmor();
	int  attack();
	void damage(int);

private://private data members
	int x;
	int health;
	int armor;
	int strength;
};
#endif