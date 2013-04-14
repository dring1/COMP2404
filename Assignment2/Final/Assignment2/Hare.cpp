#include "random.h"
#include "Hare.h"

Hare::Hare(): x(0),health(30),strength(8),armor(5)
{
	//default constructor
}
Hare::Hare(int xx,int h,int str ,int a)//x,y,health,strength,armor
{//constructor
	x = xx;	
	health = h;
	strength = str;
	armor = a;
}

void Hare::swordPlay(bool s_)
{
	sword = s_;
	if(sword == true)//adjust strength value according to sword
		strength+=3;
}
void Hare::setHealth(int h_)//getters and setters for basic model
{
	health = h_;
}
void Hare::setStrength(int s_)
{
	strength=s_;
}
void Hare::setArmor(int a_)//getter/setters for private data members
{
	armor=a_;
}
void Hare::setX(int x_)
{
	x = x_;
}
void Hare::update()
{
	
}
bool Hare::getSword()
{
	return sword;
}
int  Hare::getX()
{
	return x;
}
int	 Hare::getHealth()
{
	return health;
}
int  Hare::getStrength()
{
	return strength;
}
int  Hare::getArmor()
{
	return armor;
}
void Hare::damage(int d)
{
	if(d>0) health = health - d;//ignore damage if it is negative ie more armor than damage
	if(health<0) health = 0;//adjust health
}