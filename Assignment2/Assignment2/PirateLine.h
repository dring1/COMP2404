#ifndef PIRATELINE_H
#define PIRATELINE_H

#include "Pirate.h"
#include "Node.h"

class PirateLine
{
public:
	PirateLine();
	PirateLine(const PirateLine &);
	~PirateLine();
	void pushFront(Pirate*);
	void pushBack(Pirate*);
	void popFront();
	void popBack();
	void buildPirate(int);
	Pirate* back() const;
	Pirate* front() const;
	bool empty() const;
	int getSize();
	void setSize(int);
	Node* getFront();
	Node* getBack();

private:
	int size;
	Node* frontPtr;
	Node* backPtr;
};
#endif