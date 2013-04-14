#include <iostream>
#include "Node.h"
#include "Pirate.h"
using namespace std;

Node::Node()
{
	
}
Node::Node(Pirate *p)
{
	data = p;//hard copy the data transfer
}

Pirate* Node::getData()//getters and setters for node private data members
{
	return data;
}
void  Node::setData(Pirate *p)
{
	data=p;
}
Node* Node::getNext()//returns next node
{
	return next;
}
Node* Node::getPrev()//rturn previous node
{
	return prev;
}
void Node::setNext()//defaults to setting next/prev to null
{
	//cout<<"\nnode building \n"<<endl;
	next = 0;
}
void Node::setPrev()
{
	prev = 0;
}
void Node::setNext(Node *n)//overloaded functions to ponit to pass parameter
{
	next = n;
}
void Node::setPrev(Node *n)
{
	prev = n;
}
