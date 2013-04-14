#include "Cell.h"


ostream& operator<<(ostream& out,const Cell &)
{
	return out;
}

Cell::Cell(int id,int s): ID(id), remaining_space(s)
{
	
}

void Cell::setID(int _id)
{
	ID = _id;
}

int Cell::getID()
{
	return ID;
}

void Cell::setSpace(int s)
{
	remaining_space= s;
}

int Cell::getSpace()
{
	return remaining_space;
}

List* Cell::getList()
{
	return list;
}


Cell &Cell::operator+=(Pirate &p)
{

	return *this;
}

Cell &Cell::operator-=(Pirate &p)
{
	return *this;
}