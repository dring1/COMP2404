#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "Controller.h"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "ncurses.h"
using namespace std;

class BattleField
{
public:
	BattleField();
	~BattleField();
	void startScreen();
	void update(Controller*);
	void graveYard(Controller*);
private:



};
#endif