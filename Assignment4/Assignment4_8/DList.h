#ifndef DLIST_H
#define DLIST_H

//#include <cstdlib>

#include "Node.h"
#include <iostream>
using namespace std;

//creating template class
template<typename T>
class DList
{
public://function prototypes
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


private://private data members
	int size;
	Node<T>* front;
	Node<T>* back;


};
//template default constructor
template<typename T>
DList<T>::DList():size(0)
{
	
}
//template constructor
template<typename T>
DList<T>::DList(Node<T> *n)
{
	push(n);
}
//template destructor
template<typename T>
DList<T>::~DList()
{
	
}
//template push
template<typename T>
void DList<T>::push(T *d)
{
	Node<T> *n = new Node<T>(d);//create node with data
	if(size==0){
		front = n;
		back  = n;
		n->setNext(0);
	}
	else{//place into linked list
		n->setNext(front);
		n->getNext()->setPrev(n);
	}
	n->setPrev(0);
	front = n;
	size++;//inc size
}
//template pop
template<typename T>
void DList<T>::pop()
{
	Node<T> *temp = front;//pop front 
	if(size>1)
		front = front->getNext();
	delete temp;
	front->setPrev(0);
	size--;
}
//template pop at index
template<typename T>
void DList<T>::pop(T *d)
{
	for(Node<T> *i = front;i->getNext()!=0;i = i->getNext()){
		//loop through list
		//until match is found
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
			else{//set prev and next appropriately
				i->getPrev()->setNext(i->getNext());
				i->getNext()->setPrev(i->getPrev());
				delete i;
			}
			size--;//decrement size if match found
		}
	}
		
}
//template peek at front
template<typename T>
T* DList<T>::peekFront()
{
	return front;
}
//template peek at back
template<typename T>
T* DList<T>::peekBack()
{
	return back;
}
//template empty
template<typename T>
bool DList<T>::empty()
{
	bool e;
	(size == 0) ? e = true : e = false;
}
//template size
template<typename T>
int DList<T>::getSize()
{
	return size;//get size
}
//template get front node
template<typename T>
Node<T>* DList<T>::getFront()
{
	return front;
}
//template get back node
template<typename T>
Node<T>* DList<T>::getBack()
{
	return back;
}
//end class definition
#endif