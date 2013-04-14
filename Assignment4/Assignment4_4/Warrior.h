#ifndef WARRIOR_H
#define WARRIOR_H

class Warrior
{
public:
	Warrior();
	Warrior(int,int,int);

	void setHealth(int);
	void setArmor(int);
	void setStrength(int);


	int getHealth();
	int getArmor();
	int getStrength();

	void damage(int);

	void setX(int);
	void setY(int);

	int getX();
	int getY();

	virtual void move();
	virtual void collide(Warrior*);
	virtual void bounds();


private:
	int health;
	int armor;
	int strength;
	int x;
	int y;

};
#endif