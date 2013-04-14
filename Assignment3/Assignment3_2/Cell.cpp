#include "Cell.h"


ostream &operator<<(ostream& out,const Cell& cell)
{

	out<<"Cell " << cell.getID()<<":  space remaining="<<
	cell.getSpace()<<endl;
	cell.getList()->superPrint();
	return out;
}

Cell::Cell(int id,int s): ID(id), remaining_space(s)
{
	
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
	remaining_space= s;
}

int Cell::getSpace() const
{
	return remaining_space;
}

List* Cell::getList() const
{
	return list;
}


Cell &Cell::operator+=(Pirate &p)
{
	//list->push(&p);
	*list+p;
	return *this;
}

Cell &Cell::operator-=(Pirate &p)
{
	*list-=p;
	return *this;
}