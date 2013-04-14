#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include "Pirate.h"

class List
{
public://function prototypes
	List();//default constructor
	List(Pirate &); //constructor taking a pirate reference
	List(const List &);
	~List();
	void push(Pirate*);
	Node* getFront() const;
	Node* getCurrent() const;
	void setSize(int) ;
	int getSize() const;
	void clear();
	void superPrint() const;
	bool checkBorc();
	bool checkPorc();

	List& operator=(const List&);
	List& operator+(Pirate &);
	List& operator+=(Pirate &);
	List& operator-(Pirate &);
	List& operator-=(Pirate &);
	bool operator==(const List &);
	bool operator!=(const List &);
	Pirate& operator[](int);

private://private data members
	int size;
	Node* back;
	Node* front;
	Node* current;
};
#endif