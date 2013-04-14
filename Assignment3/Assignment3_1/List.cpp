#include "List.h"
#include "Node.h"
#include "Pirate.h"

List::List():size(0)//default contructor
{
	
}

List::List(Pirate &p):size(0)//constructor setting size to 0 
{ // para pirate ref is set to the front pointer
	//new node loaded with p
	Node *n = new Node(&p);
	front = n;
}

List::List(const List &copy)
{
	size = 0;
	for(Node *ptrNode = copy.front;size!=copy.size;ptrNode=ptrNode->getNext())
		push(ptrNode->getData());
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
	n->setNext(front);
	front = n;
}

Node* List::getFront()
{
	return front;
}
//const Array &Array::operator=( const Array &right )

List &List::operator=(const List& list)
{
	//List *n = new List();
	//for loop set everything thing in this list = to wahts on the right
	//for(Node *ptrN;
	//clear list then assign
	return *this;
}

List &List::operator+(Pirate & data)
{
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
	
	return *this;
}

List &List::operator-=(Pirate & data)
{
	
	return *this;
}

bool List::operator==(const List &)
{
	return true;
}

bool List::operator!=(const List &)
{
	return true;
}

Pirate &List::operator[](int)
{
	return *front->getData();
}