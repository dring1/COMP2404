#include "random.h"
#include "Tortoise.h"

Tortoise::Tortoise(): x(0),health(30),strength(5),armor(8)
{
	//default constructor
}
Tortoise::Tortoise(int xx,int h,int str ,int a)//x,y,health,strength,armor
{//constructor
	x = xx;	
	health = h;
	strength = str;
	armor = a;
}

void Tortoise::swordPlay(bool s_)
{
	sword = s_;
	if(sword == true)//adjust strength value according to sword
		strength+=3;
}
void Tortoise::setHealth(int h_)//getters and setter for private data members
{
	health = h_;
}
void Tortoise::setStrength(int s_)
{
	strength = s_;
}
void Tortoise::setArmor(int a_)
{
	armor = a_;
}
void Tortoise::setX(int x_)
{
	x = x_;
}
void Tortoise::update()
{
	
}
bool Tortoise::getSword()//getters and setter for private data members
{
	return sword;
}
int  Tortoise::getX()
{
	return x;
}
int	 Tortoise::getHealth()
{
	return health;
}
int  Tortoise::getStrength()
{
	return strength;
}
int  Tortoise::getArmor()
{
	return armor;
}
void Tortoise::damage(int d)
{
	if(d>0) health = health - d;//ignore damage if it is negative
	if(health<0) health = 0;//adjust health accordingly
}