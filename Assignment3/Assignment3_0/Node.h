#ifndef NODE_H
#define NODE_H

#include "Pirate.h"

class Node
{
private: // function prototypes
	Node();
	Node(Pirate*);
	Pirate* getData();
	void	setData(Pirate *);

	Node*   getNext();
	//Node*	getPrev();

	void	setNext();
	//void	setPrev();

	void	setNext(Node *);
	//void	setPrev(Node *);
	void	setIndex(int);

	int		getIndex();

private:// private data members
	Pirate *data;
	int index;
	Node *next;
	//Node *prev;
};
#endif