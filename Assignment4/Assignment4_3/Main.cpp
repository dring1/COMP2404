#include <iostream>
#include "ncurses.h"
#include "DList.h"
#include "Timmy.h"
#include "Harold.h"
#include "Controller.h"
#include <typeinfo>


int main()
{
	Controller *master = new Controller();
	cout << master->getList()->getSize()<<endl;
	for(int i = 0;i<50;i++){
		master->generate();
	}
	Node<Warrior> *temp = master->getList()->getFront();
	while(temp!=0)
	{
		Soldier *s = dynamic_cast<Soldier*>(temp->getData());
		if(s!=0) cout<<"Soldier!"<< s->getStrength()<<endl;
		Timmy *t = dynamic_cast<Timmy*>(temp->getData());
		if(t!=0) cout<<"Timmy"<< t->getStrength()<<endl;
		Pirate *p = dynamic_cast<Pirate*>(temp->getData());
		if(p!=0) cout<<"Pirate!"<< p->getStrength()<<endl;
		King *k = dynamic_cast<King*>(temp->getData());
		if(k!=0) cout<<"King!"<< k->getStrength()<<endl;
		Harold *h = dynamic_cast<Harold*>(temp->getData());
		if(h!=0) cout<<"Harold!"<< h->getStrength() <<endl;
		temp = temp->getNext();
	}
	cout << master->getList()->getSize()<<endl;
	

	return 0;

}