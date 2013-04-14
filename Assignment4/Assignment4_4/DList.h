#ifndef DLIST_H
#define DLIST_H

//#include <cstdlib>

#include "Node.h"
#include <iostream>
using namespace std;


template<typename T>
class DList
{
public:
	DList();
	DList(Node<T> *);
	~DList();
	void push(T*);
	void pop();
	void pop(T*);
	T* peekFront();
	T* peekBack();
	bool empty();
	int getSize();

	Node<T>* getFront();
	Node<T>* getBack();


private:
	int size;
	Node<T>* front;
	Node<T>* back;


};

template<typename T>
DList<T>::DList():size(0)
{
	
}

template<typename T>
DList<T>::DList(Node<T> *n)
{
	push(n);
}

template<typename T>
DList<T>::~DList()
{
	
}

template<typename T>
void DList<T>::push(T *d)
{
	Node<T> *n = new Node<T>(d);
	if(size==0){
		front = n;
		back  = n;
		n->setNext(0);
	}
	else{
		n->setNext(front);
		n->getNext()->setPrev(n);
	}
	n->setPrev(0);
	front = n;
	size++;
}

template<typename T>
void DList<T>::pop()
{
	Node<T> *temp = front;
	if(size>1)
		front = front->getNext();
	delete temp;
	front->setPrev(0);
	size--;
}

template<typename T>
void DList<T>::pop(T *d)
{
	for(Node<T> *i = front;i->getNext()!=0;i = i->getNext()){
		//cout << "Dat infinite loop" <<endl;
		if(i->getData()==d){
			if(i==front){
				//Node *temp = front;
				front = front->getNext();
				front->setPrev(0);
				delete i;
				break;
			}
			else if(i==back){
				//Node *temp = back;
				back = back->getPrev();
				back->setNext(0);
				delete i;
				break;
			}
			else{
				i->getPrev()->setNext(i->getNext());
				i->getNext()->setPrev(i->getPrev());
				delete i;
			}
			size--;
		}
	}
		
}

template<typename T>
T* DList<T>::peekFront()
{
	return front;
}

template<typename T>
T* DList<T>::peekBack()
{
	return back;
}

template<typename T>
bool DList<T>::empty()
{
	bool e;
	(size == 0) ? e = true : e = false;
}

template<typename T>
int DList<T>::getSize()
{
	return size;
}

template<typename T>
Node<T>* DList<T>::getFront()
{
	return front;
}

template<typename T>
Node<T>* DList<T>::getBack()
{
	return back;
}

#endif