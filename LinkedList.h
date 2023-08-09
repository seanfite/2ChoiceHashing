#include <iostream>
#include "UPCEntry.h"

using namespace std;

// Sean Fite
// Data Structure Assignment 6
// This header file is implementation of linked list

template<class Type>							// node class to define data and next pointer
class Node
{
	public:
		Type _data;
		Node *_next;
};

template<class Type>							// header 
class LinkedList
{
    private:
        Node<Type> *_head;	
    	Node<Type> *_tail;
    public:
        LinkedList();							// default constructor
        ~LinkedList();							// destructor
        int size() const;						// returns size of linked list
		int position(Type item);				// returns position of value item in linked list
		int _size;								// initializing size variable, wants to be public
        void insert(const Type &item);			// insert item into linked list at front
        void print();							// print output of linked list for testing		
};
// implementation
template<class Type>							
LinkedList<Type>::LinkedList()					// initialize values
{
	_head = NULL;
	_size = 0;
}

template<class Type>							// destructing and minimizing leaks
LinkedList<Type>::~LinkedList()
{
    _size = 0;
    _head = nullptr;
}

template<class Type>							// return size
int LinkedList<Type>::size() const
{
	return _size;
}

template<class Type>							// inserting item to front of linked list
void LinkedList<Type>::insert(const Type &item)
{
	Node<Type> *temp = new Node<Type>;			// create new instance, iterate pointer, increase size
	temp->_data = item;
	temp->_next = _head;
	_head = temp;
	_size++;
}

template <class Type>							// return position for hashtable functions if item is found
int LinkedList<Type>::position(Type item)
{
    Node<Type> *currNode = this->_head;
    int currIndex = 0;
    while (currNode != nullptr)
    {
		if(currNode->_data == item)
		{
			return currIndex;
		}
        currNode = currNode->_next;
        currIndex++;
    }
    return -1;
}

template<class Type>							// print output mostly for testing
void LinkedList<Type>::print()
{
	Node<Type> *current = _head;
	while (current != NULL)
	{
		cout << current->_data << " ";
		current = current->_next;
	}
	cout << endl;
}

