#ifndef REFEREE_H
#define REFEREE_H

#include "Hare.h"
#include "Tortoise.h"
#include "Snack.h"
class Referee
{
public:
	Referee(int,int,int,int);
	void Snack_Generation(int,int);
	Snack* getArr();
	bool winner();
	int getWinner();
	bool collision_H();
	void collision_T();
	bool crash();
	void collisions();
	void printO();
	void gamePlay();
	void play();
	void update();
	void move();
	void moveX();
	void moveY(bool,bool);
	void turns();
	Tortoise getTort();
	Hare getHare();	
private:
	Hare H;
	Tortoise T;
	int x;
	int y;
	bool hWins;
	bool tWins;
//	Snack Arr[(int)((18*98)*0.15)];
	Snack Arr[265];
};
#endif
