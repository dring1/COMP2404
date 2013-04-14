#ifndef PIRATELINE_H
#define PIRATELINE_H

#include "Pirate.h"
#include "Node.h"

class PirateLine//class definition
{
public://function prototypes
	PirateLine();
	PirateLine(const PirateLine &);
	~PirateLine();
	void pushFront(Pirate*);
	void pushBack(Pirate*);
	void popFront();
	void popBack();
	void buildPirate(int);
	void clear();
	Pirate* back() const;
	Pirate* front() const;
	bool empty() const;
	int getSize();
	void setSize(int);
	Node* getFront();
	Node* getBack();
	

private://private data members
	int size;
	Node* frontPtr;
	Node* backPtr;
};
#endif