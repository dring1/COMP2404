#include <iostream>
#include "Pirate.h"
#include "Node.h"
#include "Deque.h"
using namespace std;


Deque::Deque()//constructor
{
	cout<<"\nConstructor Called"<<endl;
	//size = 0;//size starts at 0
	//buildPirate(10);//call function to build 10 nodes with 10 pirates, 1 in each
}

/*Deque::Deque(const Deque & copyD)//copy constructor
{
	cout<<"\nCopy Constructor Called"<<endl;
	//setSize(copyD.getSize);
	size = 0;//reset the counter in the new deque
	//point to the last node
	//so long as .....
	//copyPtr points to the previous node
	//must go from back and push to front in order to keep proper order
	for(Node *ptrNode = copyD.backPtr;size!=copyD.size; ptrNode=ptrNode->getPrev())
		pushFront(ptrNode->getData());

}
Deque::~Deque()//deconstructor
{	
	cout<<"\nDestructor Called"<<endl;
	while(!empty())//simple deconstructor while the deque is not empty pop the head, calls delete on Node, which deletes data 
		popFront();
}
void Deque::pushFront(Pirate* p)
{
	Node *n = new Node(p);
	if(size==0){//if it is the first node
		n = frontPtr;//it is considered both the front and the back
		n = backPtr;
		n->setNext();//next pointed to null
	}
	if(size>0){//if it is not hte first node
		n->setNext(frontPtr);//set the new nodes next pointer to the front
	
		n->getNext()->setPrev(n);//the front now points prev to the new node
	}
	n->setPrev();//new node prev points to null
	frontPtr = n;//new node is now the head
	size++;//inc the total size of the deque
}
void Deque::pushBack(Pirate* p)
{
	Node *n = new Node(p);
	if(size==0)//if new node is the first node
	{
		n = frontPtr;//set it to the front and the back
		n = backPtr;
		n->setNext();//next points to null
	}
	if(size>0){//if not the first node
		n->setPrev(backPtr);//new node prev points to the back
		n->getPrev()->setNext(n);//prev now points next to new node
	}
	n->setNext();//new node points next to null
	backPtr = n;//new node is now the back
	size++;//in deque size
}
void Deque::popFront()
{
	Node *temp = frontPtr;//store front in temp node
	frontPtr = frontPtr->getNext();//set front to front next
	delete temp;//delete the old front
	frontPtr->setPrev();//front points prev to null
	size--;//dec deque size
}
void Deque::popBack()
{
	Node *temp = backPtr;//store back in temp node
	backPtr = backPtr->getPrev();//back is now the previous node to it
	delete temp;//delete old back
	backPtr->setNext();//new back points to null
	size--;
}
void Deque::buildPirate(int n)//get the # of pirates in as paramter
{		
	Pirate *pir; 		
	for(int i = 0;i<n;i++){//loop
		pir = new Pirate();//create a pointer to a pirate in dynamic memory
		if(i%2==0) pushFront(pir);//if the counter is divisible by 2 then push front
		else
			pushBack(pir);			//otherwise  push back
	}
}
Pirate* Deque::back() const//returns pointer to last pirate in deque
{
	return backPtr->getData();
}
Pirate* Deque::front() const//returns pointer to first pirate in deque
{
	return frontPtr->getData();
}
bool Deque::empty() const//if empty return false
{
	if(size==0) return false;
	return true;	
}
int Deque::getSize()//return the total size of deque
{
	return size;
}
void Deque::setSize(int ss)//set size of the de
{
	size = ss;
}

Node* Deque::getFront()// return pointer to head
{
	return frontPtr;
}
Node* Deque::getBack()//return pointer to tail
{
	return backPtr;
}*/