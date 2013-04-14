#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "Controller.h"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include "ncurses.h"
using namespace std;
//class definition
class BattleField
{
public://function prototypes
	BattleField(Controller*);
	~BattleField();
	void startScreen();
	void gameBoard();
	void update(Controller*);
	void graveYard(Controller*);
	void buildVector(Controller *);
	void reset();
	void outPut();
private://private data members
	//2D vector from standard template library
	vector<vector<char> > WarriorVector;
};
#endif