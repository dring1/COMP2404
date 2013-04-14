#include "Controller.h"
#include "random.h"
//include reuquired header files


//default constructor
Controller::Controller()
{

	WarriorList = new DList<Warrior>();

	//initia
	timmy = new Timmy();
	harold = new Harold();
	king = new King();
	initialLoc();
	WarriorList->push(timmy);
	WarriorList->push(harold);
	WarriorList->push(king);
	captured = false;
}

//returens the list containing all the warriors
DList<Warrior>* Controller::getList()
{
	return WarriorList;
}
//get timmy
Timmy* Controller::getTim()
{
	return timmy;
}
//get harold
Harold* Controller::getHar()
{
	return harold;
}
//get king
King* Controller::getKing()
{
	return king;
}
//plays one iteration of the game
void Controller::game()
{
		generate();
		move();
		update();
}

//check whether one hero is alive
bool Controller::alive()
{
	if(timmy->getHealth()==0&&harold->getHealth()==0){
		return false;
	}
	else {return true;}
}
//move function
void Controller::move()
{
		//loop through every and call the move function
		Node<Warrior> *temp = WarriorList->getFront();
		int k = WarriorList->getSize();
		for(int i = 0;i<k;i++){
			//polymorphically call the move function
			temp->getData()->move();
			if(temp->getNext()!=0)
				temp = temp->getNext();
		}

	
}

void Controller::generate()
{
	//generate a pirate
	int random_number  = randomInt(1,100);
	if(random_number<51&&WarriorList->getSize()<25)
	{
		Pirate *p = new Pirate();
		p->setX(0);
		p->setY(randomInt(1,6));
		WarriorList->push(p);
		
	}
	//generate a soldier so long as list size is <26
	if(random_number>34&&WarriorList->getSize()<25)
	{
		Soldier *s = new Soldier();
		s->setY(randomInt(2,4));
		s->setX(24);
		WarriorList->push(s);
	}
}


//function called to check collisions
void Controller::update()
{
	Node<Warrior> *temp = WarriorList->getFront();
	//check for collisions
	while(temp!=0)
	{
		collisions(temp->getData());
		temp = temp->getNext();
	}
	//check if the Warrior is still alive, if not pop off the list
	temp = WarriorList->getFront();
	while(temp!=0)
	{
		if(temp->getData()->getHealth()==0)
			WarriorList->pop(temp->getData());

		temp = temp->getNext();
	}
	//if timmy collides with king set bool true
	if((timmy->getX()==king->getX())&&(timmy->getY()==king->getY())){
		//cout<<"WINNER"<<endl;
		captured = true;
		winner();
		
	}
	else if((harold->getX()==king->getX())&&(harold->getY()==king->getY())){
		//if harold collides with king 
		//cout<<"WINNER"<<endl;
		captured = true;
		winner();
		
	}
}

void Controller::collisions(Warrior *war)
{
	//loop through each warrior and check with every warrior
	//except itself if it collides
	Node<Warrior> *temp = WarriorList->getFront();
	while(temp!=0)
	{
		if(temp->getData()!=war)//making sure it doesnt collide with itself
		{
			if((temp->getData()->getX()==war->getX())&&
			temp->getData()->getY()==war->getY()){
				//polymorphically call the warriors collide function with
				//the temp node as para
				war->collide(temp->getData());
			}
		}
		temp = temp->getNext();
	}
}

//check if the warriors have left the map
void Controller::bounds()
{
	Node<Warrior> *temp = WarriorList->getFront();
	while(temp!=0)
	{
		//polymorphically call every warriors bounds function
		temp->getData()->bounds();
		temp = temp->getNext();
	}
}

void Controller::initialLoc()
{
	//set initial locations of heroes and king
	timmy->setX(0);
	timmy->setY(randomInt(0,5));;
	harold->setX(0);
	harold->setY(randomInt(0,5));
	king->setX(24);
	king->setY(2);
}

void Controller::winner(){
	//if there is a winner check whcich champ
	if((timmy->getX()==king->getX())&&(timmy->getY()==king->getY())){
		champion = "Timmy";
	}
	else if((harold->getX()==king->getX())&&(harold->getY()==king->getY())){
		champion = "Harold";
	}

}

//getters have death locatios
int Controller::getTDX(){ return tDeath_x; }
int Controller::getTDY(){ return tDeath_y; }
int Controller::getHDX(){ return hDeath_x; }
int Controller::getHDY(){ return hDeath_y; }
bool Controller::getCaptured(){return captured;}//get if king has been captured
string Controller::getChampion(){return champion;}