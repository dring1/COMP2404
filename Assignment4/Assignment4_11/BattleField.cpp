#include "BattleField.h"
#include "ncurses.h"
#include <typeinfo>
#include "random.h"
#include <iostream>
#include <string>
using namespace std;
//include required header files and libraries

BattleField::BattleField(Controller *control)//default constructor takes a Controller as a param
{
	//2D vector by create a vector within a vector 
	vector<vector<char> > vec(6,vector<char>(25,'x'));
	//initialize 2D vector to warrior vector
	WarriorVector  = vec;
}

//valgrind chunked really hard when running the program
//while curses was refreshing the display
//
BattleField::~BattleField()//destructor
{
	
}

//Little bonus screen for the user
void BattleField::startScreen()
{

	initscr();//initialize screen to use ncurses
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
	//contains outer layer of board
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

//refreshes the display
//vector contains all values of the display
void BattleField::update(Controller *control)
{
	gameBoard();
	reset();//reset values of vector
	buildVector(control);//build the vector up to date
	for(int i = 0;i<6;i++)//loop through locations in 2D vector
	{
		for(int j = 0;j<25;j++)
		{
			move(i+1,j+1);//move to location to align properly
			if(WarriorVector[i][j]=='x')//to display proper characters 
				addstr(" ");			// check chars to corresponding Warrior
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

			refresh();//refresh the display
		}
	}
	
	graveYard(control);//check if anyone has died on the field since battle
	refresh();
	sleep(1);
	endwin();

}
//displays + if a hero died
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
//reset the vector to default values
//rebuild to have appropriate values in 2D vector 
//to corresponding locations from warrior list
void BattleField::buildVector(Controller* control)
{

	//WarriorVector.clear();

	reset();
	Node<Warrior> *temp = control->getList()->getFront();
	int xx = 0;
	endwin();

	//loop and cast 
	//check which warrior we have and add the appropriate character to the 2D vector
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
			Pirate *p =dynamic_cast<Pirate*>(temp->getData());
			type = p->getType();

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
//reset the vector 
//to default values
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
//test code
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
//if there is a winner display 
//the appropriate winner!
void BattleField::winner(Controller *control)
{
	move(8,5);
	string champ = control->getChampion();
	if(champ=="Harold")
		addstr("WINNER IS HAROLD!");
	if(champ=="Timmy")
		addstr("WINNER IS TIMMY !");	
	move(9,0);
	//make the ta's life a little easier
	//can see the game board at the end without it dissappearing
	addstr("HIT ANY KEY TO END THE GAME");
	getch();
	refresh();
	endwin();
}
//if both heros died then display the loser screen
void BattleField::loser()
{
	move(10,25);
	addstr("HEROS ARE DEAD :(");
	move(11,25);
	addstr("   GAME OVER");
	move(9,0);
	//make the ta's life a little easier
	//can see the game board at the end without it dissappearing
	addstr("HIT ANY KEY TO END THE GAME");
	getch();
	refresh();
	endwin();
}