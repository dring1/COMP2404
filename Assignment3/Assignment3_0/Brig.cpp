#include "Pirate"


Brig::Bring(int s):default_space(s)
{
	
}

Brig::Brig(const Brig &copy)
{
	default_space = copy.getDefSpace();
	next_id_num = copy.getNextID();
	for(int i = 0;i<10;i++)
	{
		cells[i] = copy.cells[i];
	}
	
}

void Brig::setDefSpace(int s)
{
	default_space = s;
}

int Brig::getDefSpace()
{
	return default_space;
}

void Brig::setNextID(int id)
{
	next_id_num = id;
}

int Brig::getNextID()
{
	return next_id_num;
}