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
	//create controller
	Controller *master= new Controller();
	//create display with controller as parameter
	BattleField *b = new BattleField(master);

	//load display
	b->startScreen();

	b->gameBoard();

	//gameplay so long as conditions are met
	while(master->alive()&&master->getCaptured()==false)
	{

		master->game();//1 iteration of game play in controller
		b->update(master);//update the display
		//super rare case of happening
		//when it did infinite loop
		if((master->getTim()->getX()==24&&master->getTim()->getY()==0)&&master->getHar()->getHealth()==0) break;
		if((master->getTim()->getX()==24&&master->getTim()->getY()==5)&&master->getHar()->getHealth()==0) break;
		if((master->getHar()->getX()==24&&master->getHar()->getY()==0)&&master->getTim()->getHealth()==0) break;
		if((master->getHar()->getX()==24&&master->getHar()->getY()==0)&&master->getTim()->getHealth()==0) break;
		//extremely rare chance of happening when both heros get stuck in the corner, program infinitely loops and seg faults this resolves it
		if((master->getTim()->getX()==24&&master->getTim()->getY()==0)&&
		master->getHar()->getX()==24&&master->getHar()->getY()==5) break;
		if((master->getTim()->getX()==24&&master->getTim()->getY()==5)&&
		master->getHar()->getX()==24&&master->getHar()->getY()==0) break;

	}
	if(master->getCaptured()==true&&master->alive())
		b->winner(master);
	else
		b->loser();
	return 0;

}