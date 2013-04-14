#include "BattleField.h"
#include "ncurses.h"
#include <typeinfo>
#include "random.h"
#include <iostream>
#include <string>
using namespace std;

BattleField::BattleField(Controller *control)
{
	vector<vector<char> > vec(6,vector<char>(25,'x'));
	WarriorVector  = vec;
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
		sleep(1);
        refresh();
}

void BattleField::gameBoard()
{
	initscr();
	move(0,0);
	addstr("|-------------------------|");
	move(1,0);
	addstr("|                         |");
	move(2,0);
	addstr("|                         ~");
	move(3,0);
	addstr("|                         ~");
	move(4,0);
	addstr("|                         ~");
	move(5,0);
	addstr("|                         ~");
	move(6,0);
	addstr("|                         |");
	move(7,0);
	addstr("|-------------------------|");
	refresh();
}

void BattleField::update(Controller *control)
{
	gameBoard();
	reset();
	//sleep(1);
	buildVector(control);
	for(int i = 0;i<6;i++)
	{
		for(int j = 0;j<25;j++)
		{
			move(i+1,j+1);
			if(WarriorVector[i][j]=='x')
				addstr(" ");
			else if(WarriorVector[i][j]=='K')
				addstr("K");
			else if(WarriorVector[i][j]=='T')
				addstr("T");
			else if(WarriorVector[i][j]=='H')
				addstr("H");
			else if(WarriorVector[i][j]=='s')
				addstr("s");
			else if(WarriorVector[i][j]=='p')
				addstr("p");
			else if(WarriorVector[i][j]=='b')
				addstr("b");
			else if(WarriorVector[i][j]=='d')
				addstr("d");

			refresh();
		}
	}
	
	graveYard(control);
	refresh();
	sleep(1);
	endwin();

}

void BattleField::graveYard(Controller* control)
{
	if(control->getTim()->getHealth()==0)
	{
		int x = control->getTDX();
		int y = control->getTDY();
		move(y+1,x+1);
		addstr("+");
	}	
	if(control->getHar()->getHealth()==0)
	{
		int x = control->getHDX();
		int y = control->getHDY();
		move(y+1,x+1);
		addstr("+");
	}	
}

void BattleField::buildVector(Controller* control)
{

	//WarriorVector.clear();

	reset();
	Node<Warrior> *temp = control->getList()->getFront();
	int xx = 0;
	endwin();
	while(temp!=0)
	{
		int x = temp->getData()->getY();
		int y = temp->getData()->getX();
		//cout<<x<<" "<<y<<endl;
		char type=' ';
		Warrior *cast = dynamic_cast<Timmy*>(temp->getData());
		if(cast!=0){
			type = 'T';

			WarriorVector[x][y] = type ;
		}
		cast = dynamic_cast<Harold*>(temp->getData());
		if(cast!=0){
			type = 'H';

			WarriorVector[x][y] = type ;
		}
		cast = dynamic_cast<King*>(temp->getData());
		if(cast!=0){
			type = 'K';

			WarriorVector[x][y] = type ;
		}
		cast = dynamic_cast<Pirate*>(temp->getData());
		if(cast!=0){
			int rNum = randomInt(1,3);
			if(rNum==1) type = 'd';
			else if(rNum==2) type = 'b';
			else type= 'p';

			WarriorVector[x][y] = type ;
		}
		cast = dynamic_cast<Soldier*>(temp->getData());
		if(cast!=0){
			type = 's';
			WarriorVector[x][y] = type ;
		}
		temp = temp->getNext();
		//cout<<"HERE"<<endl;
		//cout<<xx++<<endl;
		//exit(1);
	}
}

void BattleField::reset()
{
	char x = 'x';
	for (int i = 0; i < 6; i++)
	{
		for(int j =0;j<25;j++ )
		{
			WarriorVector[i][j]=x;	
		}
		cout<<endl;
	}
	refresh();
}

void BattleField::outPut()
{
	for (int i = 0; i < 6; i++)
	{
		for(int j =0;j<25;j++ )
		{
			cout<<WarriorVector[i][j];	
		}
		cout<<endl;
	}
}

void BattleField::winner(Controller *control)
{
	move(25,10);
	string champ = control->getChampion();
	if(champ=="Harold")
		addstr("WINNER IS HAROLD!");
	if(champ=="Timmy")
		addstr("WINNER IS TIMMY !");		
	getch();
	refresh();
	endwin();
}

void BattleField::loser()
{
	move(10,25);
	addstr("HEROS ARE DEAD :(");
	move(11,25);
	addstr("   GAME OVER");
	refresh();
	endwin();
}