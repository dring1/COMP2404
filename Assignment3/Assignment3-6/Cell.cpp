#include "Cell.h"


ostream &operator<<(ostream& out,const Cell& cell)
{

	out<<"--Cell " << cell.getID()<<":  space remaining="<<
	cell.getRSpace()<<endl;
	cell.getList()->superPrint();
	return out;
}

Cell::Cell()
{
	list = new List();

}

Cell::Cell(int id,int s): ID(id),space(s)
{
	list = new List();

}



void Cell::setID(int _id)
{
	ID = _id;
}

int Cell::getID() const
{
	return ID;
}

void Cell::setSpace(int s)
{
	space= s;
}

int Cell::getSpace() const
{
	return space;
}

void Cell::setRSpace(int s)
{
	remaining_space=s;
}

int Cell::getRSpace() const
{
	return remaining_space;
}


List* Cell::getList() const
{
	return list;
}

void Cell::update()
{
	setRSpace(space-list->occupied());
}

bool Cell::used()
{
	if(list->getSize()>0)
		return true;
	return false;
}


Cell &Cell::operator+=(Pirate &p)
{
	*list+p;
	return *this;
}

Cell &Cell::operator-=(Pirate &p)
{
	*list-p;
	return *this;
}