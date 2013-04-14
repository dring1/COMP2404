#ifndef DEQUE_H
#define DEQUE_H

#include "Pirate.h"
#include "Node.h"

class Deque
{
public:
	Deque();
	/*Deque(const Deque &);
	~Deque();
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
*/
private:
	int size;
	Node* frontPtr;
	Node* backPtr;
};
#endif