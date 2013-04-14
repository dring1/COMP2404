#include "random.h"
#include "Tortoise.h"

Tortoise::Tortoise(): x(0),health(30),strength(5),armor(8)
{
	
}
Tortoise::Tortoise(int xx,int h,int str ,int a)//x,y,health,strength,armor
{
	x = xx;	
	health = h;
	strength = str;
	armor = a;
}
/*Tortoise::Tortoise(const Tortoise &) //Copy constructor
{
	
}
*/
void Tortoise::swordPlay(bool s_)
{
	sword = s_;
}
void Tortoise::setHealth(int h_)
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
bool Tortoise::getSword()
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
	if(d>0) health = health - d;
	if(health<0) health = 0;
}