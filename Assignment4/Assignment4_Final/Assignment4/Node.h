#ifndef NODE_H
#define NODE_H

//template class definition
template<typename T>
class Node//class def 
{
public://function prototypes
	 Node();
	 Node(T *);
	 ~Node();
	 T* getData();
	 void setData(T*);
	 Node* getNext();
	 Node* getPrev();
	 void setNext(Node<T>*);
	 void setPrev(Node<T>*);
private://private data members
	T* data;
	Node *next;
	Node *prev;
};


//template constructor
template<typename T>
Node<T>::Node()
{
	
}
//template constructor with param
template<typename T>
Node<T>::Node(T * d)
{
	data = 	d;
}
//destructor
template<typename T>
Node<T>::~Node()
{
	delete data;	
}
//template getters & setters
template<typename T>
T* Node<T>::getData()
{
	return data;
}

template<typename T>
void Node<T>::setData(T* d)
{
	data =d;
}

template<typename T>
Node<T>* Node<T>::getNext()
{
	return next;
}

template<typename T>
Node<T>* Node<T>::getPrev()
{
	return prev;
}

template<typename T>
void Node<T>::setNext(Node* n)
{
	next = n;
}

template<typename T>
void Node<T>::setPrev(Node* n)
{
	prev = n;
}

#endif