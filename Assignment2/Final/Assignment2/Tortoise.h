#ifndef TORTOISE_H
#define TORTOISE_H

class Tortoise//class definition
{
public://function prototypes
	Tortoise();
	Tortoise(int,int,int,int);//x,y,health,strength,armor
	void swordPlay(bool);
	void setHealth(int);
	void setStrength(int);
	void setArmor(int);
	void setX(int);
	void update();
	bool getSword();
	int  getX();
	int	 getHealth();
	int  getStrength();
	int  getArmor();
	void damage(int);

private://private data members
	bool sword;
	int x;
	int health;
	int strength;
	int armor;
};

#endif