#include "Node.h"
#include "Pirate.h"

//generic node class
Node::Node()
{
	
}
Node::Node(Pirate *p):data(p)//initialize node to pirate data
{
	
}

Pirate* Node::getData()//return the nodes data
{
	return data;
}

void Node::setData(Pirate * p)//set the data
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
	next = n;//set next to n
}



void Node::setIndex(int i)
{
	index = i;
}

int Node::getIndex()
{
	return index;
}