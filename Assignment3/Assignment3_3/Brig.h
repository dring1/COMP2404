#ifndef BRIG_H
#define BRIG_H

#include <iomanip>
#include <string>
#include "Cell.h"
#include "Pirate.h"
using namespace std;


class Brig
{
friend ostream& operator<<(ostream&,Brig&);


public:
	Brig(int); 
	Brig(const Brig &); //copy constructor

	void setDefSpace(int);
	int getDefSpace();


	Brig& operator+=(Pirate &);
	Brig& operator+=(const List&);
	Brig& operator-=(Pirate &);
	Brig& operator-=(const List&);
	List* operator[](int);

private:
	//static int next_id_num;
	int default_space;
	Cell *arrayCells;
	
};
#endif