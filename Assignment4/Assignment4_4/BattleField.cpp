#include "BattleField.h"
#include "ncurses.h"
#include <typeinfo>

BattleField::BattleField()
{
	
}

BattleField::~BattleField()
{
	
}


void BattleField::startScreen()
{
	initscr();
		move(11,20);
        addstr("||===========================================||");
        move(12,20);
        addstr("||                                           ||");
        move(13,20);
        addstr("||           THE TORTOISE CHRONICLES         ||");
        move(14,20);
        addstr("||                 THE PRIZE                 ||");
        move(15,20);
        addstr("||                                           ||");
        move(16,20);
        addstr("||===========================================||");
    	move(19,20);
        addstr("       HAROLD = 'H'  TIMMY = 'T' KING = 'K'    ");
		move(23,20);
		refresh();
		clear();
		sleep(2);
        refresh();
}

void BattleField::update(Controller *control)
{
	Node<Warrior> *temp = control->getList()->getFront();
	while(temp!=0)
	{
		Warrior *cast = dynamic_cast<Timmy*>(temp->getData());
		if(cast!=0){
			
		}
		cast = dynamic_cast<Harold*>(temp->getData());
		if(cast!=0){
			
		}
		cast = dynamic_cast<King*>(temp->getData());
		if(cast!=0){
			
		}
		cast = dynamic_cast<Pirate*>(temp->getData());
		if(cast!=0){
			
		}
		cast = dynamic_cast<Soldier*>(temp->getData());
		if(cast!=0){
			
		}

		temp = temp->getNext();
	}
}

void BattleField::graveYard(Controller* control)
{
	
}