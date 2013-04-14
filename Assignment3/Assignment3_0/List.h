#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include "Pirate.h"

class List
{
public://function prototypes
	List();//default constructor
	List(Pirate &); //constructor taking a pirate reference
	List(const List &)
	~List();
	Node* getFront();
	/*reverse();
	void push(Pirate*);
	void pop();
	Pirate* back() const;
	Pirate* front() const;
	Node* getNode(int);
	Node* getFront();
	Node* getBack();*/

private://private data members
	int size;
	Node* back;
	Node* front;
};
#endif