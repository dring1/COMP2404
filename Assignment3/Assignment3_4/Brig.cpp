#include "Brig.h"
#include "Pirate.h"
#include "Cell.h"
#include "Node.h"

static int next_id_num = 1000;

ostream& operator<<(ostream &out,const Brig &brig){

	return out;
}

Brig::Brig(int s):default_space(s)
{
	next_id_num++;
	arrayCells = new Cell[10];
}

Brig::Brig(const Brig &copy)
{
	default_space = copy.default_space;
	for(int i = 0;i<10;i++)
	{
		arrayCells[i] = copy.arrayCells[i];
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

void Brig::push(Pirate &p)
{
	
	for(int i = 0;i<10;i++){
		if(p.getSpace()<=(default_space - arrayCells[i].getSpace()))
		{
			if(p.getType()=="Porc"&&!(arrayCells[i].getList()->checkBorc())){
				arrayCells[i]+=p;
				arrayCells[i].update();
				break;
			}
			else if(p.getType()=="Borc"&&!(arrayCells[i].getList()->checkPorc())){
				arrayCells[i]+=p;
				arrayCells[i].update();
				break;
			}
		}
	}

}

void Brig::pop(Pirate &p)
{
	for(int i = 0;i<10;i++){
		if(arrayCells[i].getList()->getSize()>0)
			if(arrayCells[i].getList()->contains(p)){
				arrayCells[i]-=p;
				arrayCells[i].update();
			}
	}
}


Brig& Brig::operator+=(Pirate &p)
{	
	/*for(int i = 0;i<10;i++){
		if(p.getSpace()<=(default_space - arrayCells[i].getSpace()))
		{
			if(p.getType()=="Porc"&&!(arrayCells[i].getList()->checkBorc())){
				arrayCells[i]+=p;
				break;
			}
			else if(p.getType()=="Borc"&&!(arrayCells[i].getList()->checkPorc())){
				arrayCells[i]+=p;
				break;
			}
		}
	}*/
	push(p);
	return *this;
}

Brig& Brig::operator+=(const List &pirates)
{
	Node *temp = pirates.getFront();
	//for(int p = 0;p<pirates.getSize();p++){
	while(temp!=0){
		/*for(int i = 0;i<10;i++){
			if(temp->getData()->getType()=="Porc"&&!(arrayCells[i].getList()->checkBorc())){
				arrayCells[i]+=*temp->getData();
				break;
			}
			else if(temp->getData()->getType()=="Borc"&&(arrayCells[i].getList()->checkPorc())){
				arrayCells[i]+=*temp->getData();
				break;
			}
		}*/
		push(*temp->getData());
		temp = temp->getNext();
	}

	return *this;
}

Brig& Brig::operator-=(Pirate &p)
{
	pop(p);
	return *this;
}

Brig& Brig::operator-=(const List& pirates)
{
	Node *temp = pirates.getFront();
	while(temp!=0){
		pop(*temp->getData());
		temp = temp->getNext();
	}
	return *this;
}

List* Brig::operator[](int cellNumber)
{
	return arrayCells[cellNumber].getList();
}