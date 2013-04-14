#include <iostream>
#include "Node.h"
#include "Pirate.h"
using namespace std;

Node::Node()
{
	
}
Node::Node(Pirate *p)
{
	data = p;
}
/*Node::~Node()
{
	delete data;
	delete next;
	delete prev;

}
*/
/*Node::Node(const Node & copyNode)
{
	copyNode.setData(this->data);
	//copyNode.setNext(next);
	//copyNode.setPrev(prev);
}*/
Pirate* Node::getData()
{
	return data;
}
void  Node::setData(Pirate *p)
{
	data=p;
}
Node* Node::getNext()
{
	return next;
}
Node* Node::getPrev()
{
	return prev;
}
void Node::setNext()
{
	cout<<"\nnode building \n"<<endl;
	next = 0;
}
void Node::setPrev()
{
	prev = 0;
}
void Node::setNext(Node *n)
{
	next = n;
}
void Node::setPrev(Node *n)
{
	prev = n;
}
