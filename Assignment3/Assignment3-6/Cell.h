#ifndef CELL_H
#define CELL_H

#include "List.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


class Cell // class definition
{
	friend ostream& operator<<(ostream&, const Cell&);

public: //function prototypes

	
	Cell();
	Cell(int,int);

	void setID(int);
	int getID() const;

	void setSpace(int);
	int getSpace() const;

	void setRSpace(int);
	int getRSpace() const;

	List* getList() const;
	
	void update();

	bool used();
	

	Cell& operator+=(Pirate &);
	Cell& operator-=(Pirate &);
	
private://private data members
	int ID;
	int remaining_space;
	int space;
	List *list;

};
#endif