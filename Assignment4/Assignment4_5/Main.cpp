#include <iostream>
#include "ncurses.h"
#include "DList.h"
#include "Timmy.h"
#include "Harold.h"
#include "Controller.h"
#include "BattleField.h"
#include <stdlib.h>
#include <typeinfo>


int main()
{
	Controller *master= new Controller();
	//master->game();
	BattleField *b = new BattleField(master);

	b->startScreen();

	b->gameBoard();

	while(master->alive()&&master->getCaptured()==false)
	{

		master->game();
		cout<<"Here"<<endl;
		
		b->update(master);
	}

	return 0;

}