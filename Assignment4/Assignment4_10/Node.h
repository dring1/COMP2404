#ifndef NODE_H
#define NODE_H


template<typename T>
class Node
{
public:
	 Node();
	 Node(T *);
	 ~Node();
	 T* getData();
	 void setData(T*);
	 Node* getNext();
	 Node* getPrev();
	 void setNext(Node<T>*);
	 void setPrev(Node<T>*);
private:
	T* data;
	Node *next;
	Node *prev;
};



template<typename T>
Node<T>::Node()
{
	
}

template<typename T>
Node<T>::Node(T * d)
{
	data = 	d;
}

template<typename T>
Node<T>::~Node()
{
	
}

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