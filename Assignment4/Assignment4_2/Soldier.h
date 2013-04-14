#ifndef SOLDIER_H
#define SOLDIER_H

#include "Warrior.h"

class Soldier: public Warrior
{
public:
	Soldier();
	virtual void move();
};
#endif