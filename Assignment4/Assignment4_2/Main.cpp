#include <iostream>
#include "ncurses.h"
#include "DList.h"
#include "Timmy.h"
#include "Harold.h"
#include "Controller.h"


int main(){
	//DList<Warrior> WarriorList();
	Controller *master = new Controller();
	cout << master->getList()->getSize()<<endl;
	for(int i = 0;i<50;i++)
		master->generate();
	cout << master->getList()->getSize()<<endl;
	

	return 0;

}