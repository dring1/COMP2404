#include "Brig.h"
#include "Pirate.h"
#include "Cell.h"
#include "Node.h"

//including all necessary h files

static int next_id_num = 1000;//initialize static id to start at 1000



ostream& operator<<(ostream &out,const Brig &brig){//will display the brig with the format provided
	out<<"Brig: #cells="<<brig.inUse()<<endl;
	brig.printOut();
	return out;
}

Brig::Brig(int s):default_space(s)//constructor
{
	
	arrayCells = new Cell[10];//creates an array of 10 cell
	for(int i = 0;i<10;i++){
		arrayCells[i].setSpace(s);// initialize every cell
		arrayCells[i].setID(i);// initialize the id
	}

}

Brig::Brig(const Brig &copy)//copy constructor
{
	default_space = copy.default_space;
	for(int i = 0;i<10;i++)
	{
		arrayCells[i] = copy.arrayCells[i];
	}
	
}

void Brig::setDefSpace(int s)//setter
{
	default_space = s;
}

int Brig::getDefSpace()
{
	return default_space;
}

void Brig::push(Pirate &p)//push function
{
	
	for(int i = 0;i<10;i++){//will loop through the array of cells until an appropriate cell has been found
		if(p.getSpace()<=(default_space - arrayCells[i].getList()->occupied()))//with given restrictions
		{	
			if(p.getType()=="Porc"&&arrayCells[i].getList()->checkBorc()){
			
			}
			else if(p.getType()=="Borc"&&arrayCells[i].getList()->checkPorc()){
				
			}
			else{
				next_id_num++;//inc ID
				p.setID(next_id_num);//set Pirate ID
				arrayCells[i]+=p;//add it to the Brig
				arrayCells[i].update();//update the cells size

				break;//break once added
			}
		}
	}

}

void Brig::pop(Pirate &p)// pop the pirate off of nop[]
{
	for(int i = 0;i<10;i++){//loop through the cells 
		if(arrayCells[i].getList()->getSize()>0){//check if the pirate is contained in the cells
			if(arrayCells[i].getList()->contains(p)){	
				arrayCells[i]-=p;//if so delete it	
				arrayCells[i].update();//update the cell
			}
		}
	}
}

int Brig::inUse() const//helper function to check hte occupents of a cell
{
	int x = 0;
	for(int i = 0;i<10;i++){
		if(arrayCells[i].used())
			x++;	
	}
	return x;
}

void Brig::printOut() const // helper to print ouf the cells array
{
	for(int i = 0;i<10;i++){
		if(arrayCells[i].used())
			cout<<arrayCells[i];
	}
}


Brig& Brig::operator+=(Pirate &p)//overloaded +=
{	

	push(p); // pushes pirate p 
	return *this;//return this brig
}

Brig& Brig::operator+=(const List &pirates)
{
	Node *temp = pirates.getFront();
	//for(int p = 0;p<pirates.getSize();p++){
	while(temp!=0){//loop through the given list of pirates and 
		push(*temp->getData());//push them onto the stack
		temp = temp->getNext();//loop
	}

	return *this;
}

Brig& Brig::operator-=(Pirate &p)// removing pirate from all cells
{
	pop(p);
	return *this;
}

Brig& Brig::operator-=(const List& pirates)
{//removing pirates from list from cells
	
	Node *temp = pirates.getFront();
	while(temp!=0){
		pop(*temp->getData());
		temp = temp->getNext();
	}
	return *this;
}

List& Brig::operator[](int cellNumber)//return the list from the cell with the given
{
	return *arrayCells[cellNumber].getList();
}