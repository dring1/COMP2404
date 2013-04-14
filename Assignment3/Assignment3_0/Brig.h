#ifndef BRIG_H
#define BRIG_H

#include "Cell.h"
#include "Pirate.h";

class Brig
{
public:
	Brig(int); 
	Brig(const Brig &) //copy constructor

	void setDefSpace(int);
	int getDefSpace();

	void setNextID(int);
	int getNextID();

private:
	static int next_id_num;
	Cell cells [10];
	int default_space;
};
#endif