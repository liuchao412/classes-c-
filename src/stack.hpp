#ifndef _SRC_STACK_HPP_
#define _SRC_STACK_HPP_

// System includes
#include <cstdlib>  // For NULL definition
// User includes


/**
 * @file stack.hpp
 * @author Rok Kos <kosrok97@gmail.com>
 * @brief Class that represent stack for generic data type.
 */

template <class T>
class Stack {
private:
	// Declaring Node for linked list
	struct Node {
		T value;
		Node* next;
		// struct constructor
		Node (T _value) {
			value = _value;
			next = nullptr;
		}
		// struct destructor
		~Node(){
			//delete next;
		}
	};

	int N;
	Node* first;

public:
	// Constructor
	Stack();

	// Destructor
	~Stack();

	void push(T item);
	T top();
	T pop();
	bool isEmpty();
	int size();
};

template <class T>
Stack<T>::Stack() {
	this->N = 0;
	this->first = new Node(NULL);
}

template <class T>
Stack<T>::~Stack() {
	delete first;
}

template <class T>
void Stack<T>::push(T item) {
	N++;
	Node* newFirst = new Node(item);
	newFirst->next = this->first;
	this->first = newFirst;
}

template <class T>
T Stack<T>::top() {
	return first->value;
}

template <class T>
T Stack<T>::pop() {
	N--;
	// Save for later to return
	T returnValue = this->top();
	// Save reference so that we can delete this node
	Node* oldFirst = this->first;
	this->first = this->first->next;
	delete oldFirst;
	return returnValue;
}

template <class T>
bool Stack<T>::isEmpty() {
	if (first->next == NULL) {  // Its the same as cheking if N == 0
		return true;
	}
	return false;
}

template <class T>
int Stack<T>::size() {
	return this->N;
}

#endif  // _SRC_STACK_HPP_