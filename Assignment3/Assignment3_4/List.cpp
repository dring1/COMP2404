#include "List.h"
#include "Node.h"
#include "Pirate.h"
#include <stdlib.h>

List::List():size(0)//default contructor
{

}

List::List(Pirate &p):size(0)//constructor setting size to 0 
{ // para pirate ref is set to the front pointer
	//new node loaded with p
	Node *n = new Node(&p);
	front = n;
	current = n;
	size++;
}

List::List(const List &copy)
{
	size = 0;
	if(copy.size>0){
		front = copy.front;
		current = front;	
	}	
	for(Node *ptrNode = copy.front;size!=copy.size;ptrNode=ptrNode->getNext()){
		push(ptrNode->getData());
	}
	
}

List::~List()
{
	Node *currNode, *nextNode;
	currNode = front;
	while(currNode != 0){
		nextNode = currNode->getNext();
		delete currNode;
		currNode = nextNode;
	}
	
}

void List::push(Pirate * p)
{
	Node* n = new Node(p);
	//n->setNext(current);
	cout<<size<<endl;
	if(size>0){
		current->setNext(n);
	}
	else if(size == 0){
		cout<<"Mewo"<<endl;
		front = n;
	}

	current = n;
	size++;
}

Node* List::getFront() const
{
	return front;
}


Node* List::getCurrent() const
{
	return current;
}

void List::setSize(int x)
{

	size = x;	
}

int List::getSize() const
{
	return size;
}

void List::clear()
{
	while(size>0)
	{
		Node *temp = front;
		delete front;
		front = temp->getNext();
		size--;
	}
}

void List::superPrint() const
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
	
	Node *temp;
	while(temp!=0){
		if(temp->getData()->getType()=="Borc")
		{
			return true;
		}
		temp = temp->getNext();
	}
	return false;
}

bool List::checkPorc()
{
	Node *temp;
	while(temp!=0){
		if(temp->getData()->getType()=="Porc")
		{
			return true;
		}
		temp = temp->getNext();
	}
	return false;
}

int List::occupied()
{
	int spaceUsed = 0;
	Node *temp = front;
	while(temp!=0){
		spaceUsed+=temp->getData()->getSpace();
		temp = temp->getNext();
	}
	return spaceUsed;
}

bool List::contains(Pirate &p)
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

//const Array &Array::operator=( const Array &right )

List &List::operator=(const List& list)
{
	clear();
	Node *temp = list.front;
	for(int i = list.size;i>0;i--){
		push(temp->getData());
	}
	size = list.size;

	return *this;
}

List &List::operator+(Pirate & data)
{
	cout<<"Pew"<<endl;
	push(&data);
	return *this;
}

List &List::operator+=(Pirate & data)
{
	push(&data);
	return *this;
}

List &List::operator-(Pirate & data)
{
	Node *temp = front;
	//Node *index = front;

	while(temp->getNext()!=0){
		if(front->getData()==&data ){//base case for checking if first node is the node to be removed
			
			temp = front;
			front->setNext(0);
			delete front;
			front = temp->getNext();
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
	Node *temp = front;
	//Node *index = front;
	while(temp->getNext()!=0){
		if(front->getData()==&data ){//base case for checking if first node is the node to be removed
			temp = front;
			front->setNext(0);
			//delete front;
			front = temp->getNext();
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

bool List::operator==(const List &list2)
{
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
{
	if(this==&list2){
		return false;
	}
	return true;
}

Pirate& List::operator[](int index)
{
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