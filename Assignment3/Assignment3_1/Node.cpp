#include "Node.h"
#include "Pirate.h"


Node::Node()
{
	
}
Node::Node(Pirate *p):data(p)
{
	
}

Pirate* Node::getData()
{
	return data;
}

void Node::setData(Pirate * p)
{
	data = p;
}



Node* Node::getNext()
{
	return next;
}

void Node::setNext()
{
	next = 0;
}


void Node::setNext(Node * n)
{
	next = n;
}

void Node::setIndex(int i)
{
	index = i;
}

int Node::getIndex()
{
	return index;
}