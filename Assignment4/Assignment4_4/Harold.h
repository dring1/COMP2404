#ifndef HAROLD_H
#define HAROLD_H

#include "Warrior.h"

class Harold: public Warrior
{
public:
	Harold();
	virtual void move();
	virtual void collide(Warrior*);
	virtual void bounds();
};
#endif