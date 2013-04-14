#include "Cell.h"


ostream &operator<<(ostream& out,const Cell& cell)// overloaded stream insertion to output required format
{

	out<<"--Cell " << cell.getID()<<":  space remaining="<<
	cell.getRSpace()<<endl;
	cell.getList()->superPrint();
	return out;
}

Cell::Cell()//def constructor
{
	list = new List();

}

Cell::Cell(int id,int s): ID(id),space(s)//constructor with initialization
{
	list = new List();

}



void Cell::setID(int _id)//set the cells ID
{
	ID = _id;
}

int Cell::getID() const//return the cells ID
{
	return ID;
}

void Cell::setSpace(int s)//set max space
{
	space= s;
}

int Cell::getSpace() const//get max space
{
	return space;
}

void Cell::setRSpace(int s)//
{
	remaining_space=s;
}

int Cell::getRSpace() const // return remaining space in cell
{
	return remaining_space;
}


List* Cell::getList() const
{
	return list;
}

void Cell::update()// update the cells remaining space
{
	setRSpace(space-list->occupied());
}

bool Cell::used()//check if list is empty or not
{
	if(list->getSize()>0)
		return true;
	return false;
}


Cell &Cell::operator+=(Pirate &p)//cell should push p onto the cell
{
	*list+p;
	return *this;
}

Cell &Cell::operator-=(Pirate &p)//pop p from cell 
{

	*list-=p;
	return *this;
}