#include "Cell.h"


Cell::Cell(int id): ID(id)
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
	return list->getFront();
}