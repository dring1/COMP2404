#ifndef PIRATE_H
#define PIRATE_H

#include <iostream>
#include "Warrior.h"
#include "random.h"
using namespace std;

class Pirate: public Warrior
{
public:
	Pirate();
	virtual void move();
	virtual void collide(Warrior*);
	virtual void bounds();

};
#endif