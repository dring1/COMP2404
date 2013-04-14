#include "Brig.h"
#include "Pirate.h"
#include "Cell.h"

static int next_id_num = 0;

Brig::Brig(int s):default_space(s)
{
	next_id_num++;
	//int N = 10;
	//Cell cells[N];
	//Cell cells[10](default_space);
	Cell c[] = {Cell(0,default_space), Cell(next_id_num,default_space)};
	for(int i = 0; i<2;i++)
		cells[i] = c[i];
}

Brig::Brig(const Brig &copy)
{
	default_space = copy.default_space;
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
