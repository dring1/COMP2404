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
private:
	string type;
};
#endif