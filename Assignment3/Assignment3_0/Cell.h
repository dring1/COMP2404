#ifndef CELL_H
#define CELL_H

#include "List.h"

class Cell // class definition
{
public: //function prototypes
	Cell(int);
	
	void setID(int);
	int getID();

	void setSpace(int);
	int getSpace();

	List* getList();
		
private://private data members
	int ID;
	int remaining_space;
	List *list;

};
#endif