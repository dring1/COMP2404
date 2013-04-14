#include "Controller.h"
#include "random.h"

Controller::Controller()
{

	WarriorList = new DList<Warrior>();

	
	timmy = new Timmy();
	harold = new Harold();
	king = new King();
	initialLoc();
	WarriorList->push(timmy);
	WarriorList->push(harold);
	WarriorList->push(king);
}

DList<Warrior>* Controller::getList()
{
	return WarriorList;
}

Timmy* Controller::getTim()
{
	return timmy;
}

Harold* Controller::getHar()
{
	return harold;
}

King* Controller::getKing()
{
	return king;
}

void Controller::game()
{
	while(alive())
	{
		generate();
		move();
		update();
	}
}


bool Controller::alive()
{
	if(timmy->getHealth()==0&&harold->getHealth()==0) return false;
	else {return true;}
}

void Controller::move()
{
	
		Node<Warrior> *temp = WarriorList->getFront();
		int k = WarriorList->getSize();
		for(int i = 0;i<k;i++){
			temp->getData()->move();
			if(temp->getNext()!=0)
				temp = temp->getNext();
		}

	
}

void Controller::generate()
{
	int random_number  = randomInt(1,100);
	if(random_number<51&&WarriorList->getSize()<25)
	{
		Pirate *p = new Pirate();
		p->setX(0);
		p->setY(randomInt(1,6));
		WarriorList->push(p);
		
	}
	if(random_number>34&&WarriorList->getSize()<25)
	{
		Soldier *s = new Soldier();
		s->setY(randomInt(2,4));
		s->setX(24);
		WarriorList->push(s);
	}
}

void Controller::update()
{

}

void Controller::collisions(Warrior *war)
{
	if((timmy->getX()==king->getX())&&(timmy->getY()==king->getY())){
		winner();
		
	}
	else if((harold->getX()==king->getX())&&(harold->getY()==king->getY())){
		winner();
		
	}
	else{
		Node<Warrior> *temp = WarriorList->getFront();
		while(temp!=0)
		{
			if(temp->getData()!=war)//making sure it doesnt collide with itself
			{
				if((temp->getData()->getX()==war->getX())&&
				temp->getData()->getY()==war->getY()){
					//check for 2 soldiers
					Soldier *test1 = dynamic_cast<Soldier*>(war);
					Soldier *test2 = dynamic_cast<Soldier*>(temp->getData());
					if(test1!=0&&test2!=0)
					{
						//soldier battle
						WarriorList->pop(war);
						WarriorList->pop(temp->getData());
					}
					else if(test1!=0&&test2==0)//one soldier and 1 warrior
					{
						temp->getData()->damage(war->getStrength());
					}
					else if(test1==0&&test2!=0)
					{
						war->damage(temp->getData()->getStrength());
					}
				}
			}

			temp = temp->getNext();
		}
	}	
}

void Controller::bounds()
{
	
}

void Controller::initialLoc()
{
	timmy->setX(0);
	timmy->setY(randomInt(0,5));;
	harold->setX(0);
	harold->setY(randomInt(0,5));
	king->setX(24);
	king->setY(2);
}

void Controller::winner(){
	if((timmy->getX()==king->getX())&&(timmy->getY()==king->getY())){
		champion = "Timmy";
	}
	else if((harold->getX()==king->getX())&&(harold->getY()==king->getY())){
		champion = "Harold";
	}

}