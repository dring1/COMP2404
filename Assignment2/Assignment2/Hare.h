#ifndef HARE_H
#define HARE_H

class Hare
{
public:
	Hare();
	Hare(int,int,int,int);//x,y,health,strength,armor
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

private:
	bool sword;
	int x;
	int health;
	int strength;
	int armor;
};

#endif