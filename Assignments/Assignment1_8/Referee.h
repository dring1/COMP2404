#ifndef REFEREE_H
#define REFEREE_H

#include "Hare.h"//appropriate function access
#include "Tortoise.h"
#include "Snack.h"
class Referee//creating class for controller
{
public://functions prototypes
	Referee(int,int,int,int);//construtor
	void Snack_Generation(int,int);//functions described in greater detail in src file
	Snack* getArr();//
	bool winner();//check for winner
	int getWinner();//return winner value
	void collision_H();
	void collision_T();
	bool crash();
	void collisions();//check for all collisions on every iteration
	void printO();
	void play();//gameplay
	void update();
	void move();//movement functions
	void moveX();
	void moveY();
	void turns();
	int getTX();//getters
	int getTY();
	int getHX();
	int getHY();
	int getTE();
	int getHE();
private:
	Hare H;//models, the racers
	Tortoise T;
	int x;//hold board restriction values
	int y;
	bool hWins;//holds bool to determine winner
	bool tWins;
	Snack Arr[265];
};
#endif
