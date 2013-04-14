#include <iostream>
#include "ncurses.h"
#include "DList.h"
#include "Timmy.h"
#include "Harold.h"
#include "Controller.h"
#include "BattleField.h"
#include <typeinfo>


int main()
{
	Controller *master= new Controller();
	master->game();
	BattleField *b = new BattleField();
	b->startScreen();

	return 0;

}