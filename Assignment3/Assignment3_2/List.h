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
	Node* getFront();
	Node* getCurrent();
	int getSize();
	void clear();
	void superPrint() const;


	//const Array &operator=( const Array & );

	List& operator=(const List&);
	List& operator+(Pirate &);
	List& operator+=(Pirate &);
	List& operator-(Pirate &);
	List& operator-=(Pirate &);
	bool operator==(const List &);
	bool operator!=(const List &);
	Pirate& operator[](int);

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
	Node* current;
};
#endif