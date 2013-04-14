#ifndef BRIG_H
#define BRIG_H

#include "Cell.h"
#include "Pirate.h"

class Brig
{
public:
	Brig(int); 
	Brig(const Brig &); //copy constructor

	void setDefSpace(int);
	int getDefSpace();


private:
	//static int next_id_num;
	int max;
	int default_space;
	Cell cells[];
	
};
#endif