#ifndef NODE_H
#define NODE_H
#include "Pirate.h"
class Node
{
public:
	Node();
	Node(Pirate*);
	//Node(const Node&);
	Pirate* getData();
	void	setData(Pirate *);
	Node*   getNext();
	Node*	getPrev();
	void	setNext();
	void	setPrev();
	void	setNext(Node *);
	void	setPrev(Node *);
	//void	setIndex(int);
	//int	getIndex();
private:
	Pirate *data;
	Node *next;
	Node *prev;
};
#endif	