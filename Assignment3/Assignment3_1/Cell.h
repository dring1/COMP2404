#ifndef CELL_H
#define CELL_H

#include "List.h"
#include <iostream>

using namespace std;


class Cell // class definition
{

	friend ostream &operator<<(ostream &,const Cell&);
public: //function prototypes

	

	Cell(int,int);
	
	void setID(int);
	int getID();

	void setSpace(int);
	int getSpace();

	List* getList();
		
	Cell& operator+=(Pirate &);
	Cell& operator-=(Pirate &);
	
private://private data members
	int ID;
	int remaining_space;
	List *list;

};
#endif