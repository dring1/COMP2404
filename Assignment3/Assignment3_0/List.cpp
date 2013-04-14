#include "Node.h"
#include "Pirate.h"

List::List():size(0)//default contructor
{
	
}

List::List(Priate &p):size(0),front(*p)//constructor setting size to 0 
{ // para pirate ref is set to the front pointer
	
}

List::List(const List &copy)
{
	size = 0;
	for(Node *ptrNode = copy.front;size!=copy.size;ptrNode=ptrNode->getNext())
		push(ptrNode->getData());

	//reverse();
}

/*void List::reverse()
{
	Node* p = 0; 
	Node* i = front;
	Node* n;

	while(i)
	{
		n = i->getNext();
		p = i;
		i = n;
	}

	front = p;
}*/

List::push(Pirate * p)
{
	Node* n = new Node(p);
	n->setNext(front);
	front = n;

	/*if(size==0){
		front = n;
		n->setNext();
	}else{
		n->setNext()
	}*/
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

Node* List::getFront()
{
	return front;
}