#ifndef BRIG_H
#define BRIG_H

#include <iomanip>
#include <string>
#include "Cell.h"
#include "Pirate.h"
using namespace std;


class Brig
{
friend ostream& operator<<(ostream&,const Brig&);


public:
	Brig(int); 
	Brig(const Brig &); //copy constructor

	void setDefSpace(int);//getters/setters
	int getDefSpace();
	void push(Pirate &);
	void pop(Pirate &);
	int inUse() const;
	void printOut() const;


	Brig& operator+=(Pirate &);//overloaded operators
	Brig& operator+=(const List&);
	Brig& operator-=(Pirate &);
	Brig& operator-=(const List&);
	List& operator[](int);

private:
	//private data members
	//static int next_id_num;
	int default_space;
	Cell *arrayCells;
	
};
#endif