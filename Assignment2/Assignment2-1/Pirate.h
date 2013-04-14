#ifndef PIRATE_H
#define PIRATE_H

#include "random.h"

class Pirate
{
public:
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

private:
	int x;
	int health;
	int armor;
	int strength;
};
#endif