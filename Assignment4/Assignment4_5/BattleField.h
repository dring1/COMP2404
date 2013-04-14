#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "Controller.h"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include "ncurses.h"
using namespace std;

class BattleField
{
public:
	BattleField(Controller*);
	~BattleField();
	void startScreen();
	void gameBoard();
	void update(Controller*);
	void graveYard(Controller*);
	void buildVector(Controller *);
	void reset();
private:
	vector<vector<char> > *WarriorVector;
};
#endif