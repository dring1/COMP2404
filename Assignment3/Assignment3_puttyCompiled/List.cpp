#include "List.h"
#include "Node.h"
#include "Pirate.h"
#include <stdlib.h>

List::List():size(0)//default contructor
{
	LID = 0;
}

List::List(Pirate &p):size(0)//constructor setting size to 0 
{ // para pirate ref is set to the front pointer
	//new node loaded with p
	Node *n = new Node(&p);
	front = n;
	current = n;
	size++;
	LID = 0;
}

List::List(const List &copy)//copy constructor
{
	size = 0;
	LID = copy.LID;
	if(copy.size>0){
		front = copy.front;
		current = front;	
	}	
	for(Node *ptrNode = copy.front;size!=copy.size;ptrNode=ptrNode->getNext()){
		push(ptrNode->getData());
	}
	
}

List::~List()//destructor
{
	Node *currNode, *nextNode;
	currNode = front;
	while(currNode != 0){//while not empty delete current node
		nextNode = currNode->getNext();
		delete currNode;
		currNode = nextNode;
	}
	
}

void List::push(Pirate * p)//add a new node to the list with contents p
{
	Node* n = new Node(p);
	if(size>0){
		current->setNext(n);
	}
	else if(size == 0){
		front = n;
	}
 	n->getData()->setCell(LID);
 	LID++;
	current = n;
	size++;
}

void List::pop(Pirate *p)//remove pirate p from list
{
	Node *n = new Node(p);//check if pirate is contained
	Node *temp = front;
	Node *temp2 = front;
	int k = 0;
	for(int s=0;s<size;s++){//find at what index it is 
		k++;
		if(temp->getData()==n->getData())
			break;
		temp = temp->getNext();
	}
	temp = front;
	for(int i = 0;i<k;i++){//remove pirate and adjust nodes accordingly
		if(n->getData()->getID() == temp->getData()->getID())
		{
			
			//delete temp;
			
			front = temp->getNext();
			delete temp;


			break;
			size--;
		}
		else if(temp->getNext()!= 0)//so long as the next node is not empty
		{
			if(temp->getNext()->getData()->getID()==n->getData()->getID())
			{
				if(temp->getNext()->getNext()!=0)
				{
					temp2 = temp->getNext();
					temp->setNext(temp->getNext()->getNext());
					delete temp2;
					size--;
					break;
				}
				else
				{
					temp2 = temp->getNext();
					temp->setNext();
					delete temp2;
					size--;
					break;
				}
			}

		}
		temp = temp->getNext();
	}
}

Node* List::getFront() const//return front node
{
	return front;
}


Node* List::getCurrent() const//reutrn current node
{
	return current;
}

void List::setSize(int x)//setsize of list
{

	size = x;	
}

int List::getSize() const//return size
{
	return size;
}

void List::clear()//clear list
{
	Node *temp = front;
	while(temp!=0)
	{
		
		delete temp;
		temp = temp->getNext();
		cout<<"testinging"<<endl; 
		size--;
	}
}

void List::superPrint() const//print list in proper given format
{
	Node *temp = front;
	while(temp!=0){
		cout<<*temp->getData()<<endl;
		//if(temp->getNext()!=0)
			temp = temp->getNext();
	}
}

bool List::checkBorc()//if true then there are borcs
{
	
	Node *temp=front;
	while(temp!=0){
		if(temp->getData()->getType()=="Borc")
		{
			return true;
		}
		temp = temp->getNext();
	}
	return false;
}

bool List::checkPorc()//true if the list contains porcs
{
	Node *temp = front;
	while(temp!=0){
		if(temp->getData()->getType()=="Porc")
		{
			return true;
		}
		temp = temp->getNext();
	}
	return false;
}

int List::occupied()//how many prisoners in the list
{
	int spaceUsed = 0;
	Node *temp = front;
	while(temp!=0){
		spaceUsed+=temp->getData()->getSpace();
		temp = temp->getNext();
	}
	return spaceUsed;
}

bool List::contains(Pirate &p)//checking for contents
{
	Node *temp = front;
	while(temp!=0){
		if(temp->getData()==&p)
			return true;
		else
			temp = temp->getNext();
	}
	return false;
}


int List::getLID()
{
	return LID;
}

void List::setLID(int l)
{
	LID = l;
}

//const Array &Array::operator=( const Array &right )

List &List::operator=(const List& list)//overloaded = operatior
{
	clear();//clears list then copies contents of parameter into new list
	Node *temp = list.front;
	for(int i = list.size;i>0;i--){
		push(temp->getData());
	}
	size = list.size;

	return *this;
}

List &List::operator+(Pirate & data)//overloaded +
{
	push(&data);//push data
	return *this;
}

List &List::operator+=(Pirate & data)//overloaded +=
{
	List *templ = this;
	templ->push(&data);

	return *templ;
}

List &List::operator-(Pirate & data)
{
		Node *temp = front;
while(temp->getNext()!=0){
		if(front->getData()==&data ){//base case for checking if first node is the node to be removed
			temp = front;
			//front->setNext(0);
			
			front = front->getNext();
			//delete temp;
			size--;
		}
		else if(temp->getNext()->getData()==&data){//if the next node is the node to be deleted then 
			
			if (temp->getNext()==current)
			{
				temp->setNext(0);
				delete current;
				current = temp;
			}
			else{
				temp->setNext(temp->getNext()->getNext());//join this next node with next->next hoping over next
			}
			size--;
		}
		if(temp->getNext()!=0)
			temp = temp->getNext();
	}
	

	return *this;
}

List &List::operator-=(Pirate & data)
{
	//List *templ = this;
	//templ->pop(&data);
	List *templ;
	Node *temp = front;
while(temp->getNext()!=0){
		if(front->getData()==&data ){//base case for checking if first node is the node to be removed
			temp = front;
			//front->setNext(0);
			
			front = front->getNext();
			//delete temp;
			size--;
		}
		else if(temp->getNext()->getData()==&data){//if the next node is the node to be deleted then 
			
			if (temp->getNext()==current)
			{
				temp->setNext(0);
				delete current;
				current = temp;
			}
			else{
				temp->setNext(temp->getNext()->getNext());//join this next node with next->next hoping over next
			}
			size--;
		}
		if(temp->getNext()!=0)
			temp = temp->getNext();
	}
	templ = this;




	return *templ;
}

bool List::operator==(const List &list2)//check if list on right side is equal
{//to list on left hand side
	if(size!=list2.size)
		return false;
	else{
		Node *temp = front;
		Node *temp2 = list2.front;
		while(temp->getNext()!=0||temp2->getNext()!=0){
			if(temp->getData() != temp2->getData())
				return false;

			temp = temp->getNext();
			temp2 = temp2->getNext();
		}
		
	}
	
	return true;
}

bool List::operator!=(const List &list2)
{//passed in list equal to list
	if(this==&list2){
		return false;
	}
	return true;
}

Pirate& List::operator[](int index)
{//return pirate at given index
	//check bounds if pirate is in a proper range
	Node *temp = front;
	if(index>(size-1)||index<0){
		cerr<< "INDEX OUT OF BOUNDS" << endl;
		exit(1);
	}
	for(int i=0;i<=index;i++){
		if(i==index){
			return *temp->getData();
		}
	}
}