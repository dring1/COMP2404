#ifndef PIRATE_H
#define PIRATE_H

#include <iostream>
#include <string>
#include "Warrior.h"
#include "random.h"
using namespace std;

class Pirate: public Warrior
{
public:
	Pirate();
	void genType();
	string getType();
	virtual void move();
	virtual void collide(Warrior*);
	virtual void bounds();
private:
	string type;
};
#endif