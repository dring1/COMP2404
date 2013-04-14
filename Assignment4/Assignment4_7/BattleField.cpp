#include "BattleField.h"
#include "ncurses.h"
#include <typeinfo>
#include "random.h"
#include <iostream>
using namespace std;

BattleField::BattleField(Controller *control)
{
	vector<vector<char> > vec(6,vector<char>(25,'x'));
	//WarriorVector = new vector< vector<char> >(25,vector<char>(6));
	/*for (int i = 0; i < 6; i++)
	{
		for(int j =0;j<25;j++ )
		{
			//cout<<j<<endl;
			vec[i][j]='P';
			cout<<vec[i][j];
			//WarriorVector[i][j].front() = 'x';
			
		}
		cout<<endl;
	}*/
	WarriorVector  = vec;
	/*	for (int i = 0; i < 6; i++)
	{
		for(int j =0;j<25;j++ )
		{
			//cout<<j<<endl;
			WarriorVector[i][j]='P';
			cout<<WarriorVector[i][j];
			//WarriorVector[i][j].front() = 'x';
			
		}
		cout<<endl;
	}*/
	//exit(1);
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
	initscr();
	clear();
	gameBoard();

	reset();
	buildVector(control);
	endwin();
	//endwin();
	outPut();

	exit(1);
	for(int i = 1;i<7;i++)
	{
		for(int j = 1;j<26;j++)
		{
			move(i,j);
			/*char *c= WarriorVector[i][j];
			if(c=='x')
				addstr(" ");
			else
			 addstr(c+"");*/
		}
	}
	refresh();
	sleep(1);


}

void BattleField::graveYard(Controller* control)
{
	
}

void BattleField::buildVector(Controller* control)
{
	WarriorVector.clear();
	reset();
	Node<Warrior> *temp = control->getList()->getFront();
	while(temp!=0)
	{
		int y = temp->getData()->getX();
		int x = temp->getData()->getY();
		char type;
		Warrior *cast = dynamic_cast<Timmy*>(temp->getData());
		if(cast!=0){
			type = 'T';
		}
		cast = dynamic_cast<Harold*>(temp->getData());
		if(cast!=0){
			type = 'H';
		}
		cast = dynamic_cast<King*>(temp->getData());
		if(cast!=0){
			type = 'K';
		}
		cast = dynamic_cast<Pirate*>(temp->getData());
		if(cast!=0){
			int rNum = randomInt(1,3);
			if(rNum==1) type = 'd';
			else if(rNum==2) type = 'b';
			else type= 'p';
		}
		cast = dynamic_cast<Soldier*>(temp->getData());
		if(cast!=0){
			type = 's';
		}
		WarriorVector[x][y] = type ;
		temp = temp->getNext();
	}
}

void BattleField::reset()
{
	char x = 'x';
	for (int i = 0; i < 6; i++)
	{
		for(int j =0;j<25;j++ )
		{
			//cout<<j<<endl;
			WarriorVector[i][j]=x;
			//cout<<WarriorVector[i][j];
			//WarriorVector[i][j].front() = 'x';
			
		}
		cout<<endl;
	}
	refresh();
	//exit(1);
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