#ifndef REFEREE_H
#define REFEREE_H

class Referee
{
public:
	Referee(int,int,int,int);
	void Snack_Generation(int,int);
	Snack* getArr();
	bool winner();
	int getWinner();
	bool collision_H();
	bool collision_T();
	bool crash();
	void collisions();
	void printO();
	void gamePlay();
	void update();
	void move();
	void moveX();
	void moveY(bool,bool);
	void turns();
		
private:
	Hare H;
	Tortoise T;
	int x;
	int y;
	bool hWins;
	bool tWins;
	Snack Arr[(int)((18*98)*0.15)];
};
#endif
