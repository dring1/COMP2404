#ifndef TORTOISE_H
#define TORTOISE_H

class Tortoise 
{
public:
	Tortoise();
	Tortoise(int , int);
	int horizMove();
	int  move();
	void adjustE(int);
	void update();
	int getEnergy();
	void setEnergy(int );
	void setTurn(bool );
	bool getTurn();
	int getX();
	int getY();
	void setX(int);
	void setY(int);
private:	
	int x,y;
	int MoveUp;
	int MoveSide;
	int energy;
	bool turn;
	
};
#endif
