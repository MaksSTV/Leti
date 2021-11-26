#ifndef STACK_H
#pragma once

#include<iostream>

template <class T>
class Stack {
private:
	

	class Elem_stack {
	
	public:

		Elem_stack* next;
		T data;

		Elem_stack(T data = 0, Elem_stack* next = NULL) : data(data), next(next) {}
		~Elem_stack() = default;

		void setNext(Elem_stack* newnext) {
			this->next = newnext;
		}

		Elem_stack* getNext() {
			return this->next;
		}

		T getElemdata() {
			return this->data;
		}
	};

	Elem_stack* head, * last;

public:

	Stack();
	Stack(T data);

	void push(T item);
	void pop();
	T peek();
	bool isEmpty();
	size_t size();
	void print();
	/*
	Stack() { // create blank list
		this->head = NULL;
		this->last = this->head;
	}

	Stack(int data) { // create list with one element
		Elem_stack* elem = new Elem_stack(data);
		this->head = elem;
		this->last = elem;
	}

	void push(int item) {
		if (head == NULL) {
			Elem_stack* elem = new Elem_stack(item);
			this->head = elem;
			this->last = elem;
		}
		else {
			Elem_stack* temp = new Elem_stack(item);
			Elem_stack* cur = head; // 1
			this->head = temp; // 2
			this->head->setNext(cur); // 3
		}
	}

	void pop() {
		Elem_stack* cur = head;
		head = head->getNext();
		//std::cout << cur->getElemdata() << "\n";
		delete cur;
	}

	int peek() {
		return head->getElemdata();
	}

	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	size_t size() {
		Elem_stack* cur = head;
		int count = 0;
		while (cur != NULL) {
			count++;
			cur = cur->getNext();
		}
		return count;
	}

	void print() { // FIX ME!! Need remake, after doing methods peek and size
		Elem_stack* cur = head;
		while (cur != NULL) {
			std::cout << cur->getElemdata() << "\n";
			cur = cur->getNext();
		}
		std::cout << std::endl;
	}
	*/
};



template<class T>
inline Stack<T>::Stack()
{
	this->head = NULL;
	this->last = this->head;
}

template<class T>
inline Stack<T>::Stack(T data)
{
	Elem_stack* elem = new Elem_stack(data);
	this->head = elem;
	this->last = elem;
}

template<class T>
inline void Stack<T>::push(T item)
{
	if (head == NULL) {
		Elem_stack* elem = new Elem_stack(item);
		this->head = elem;
		this->last = elem;
	}
	else {
		Elem_stack* temp = new Elem_stack(item);
		Elem_stack* cur = head; // 1
		this->head = temp; // 2
		this->head->setNext(cur); // 3
	}
}

template<class T>
inline void Stack<T>::pop()
{
	Elem_stack* cur = head;
	head = head->getNext();

	delete cur;
}

template<class T>
inline T Stack<T>::peek()
{
	return head->getElemdata();
}

template<class T>
inline bool Stack<T>::isEmpty()
{
	if (head == NULL) {
		return true;
	}
	else {
		return false;
	}
}

template<class T>
inline size_t Stack<T>::size()
{
	Elem_stack* cur = head;
	int count = 0;
	while (cur != NULL) {
		count++;
		cur = cur->getNext();
	}
	return count;
}

template<class T>
inline void Stack<T>::print()
{
	Elem_stack* cur = head;
	while (cur != NULL) {
		std::cout << cur->getElemdata() << "\n";
		cur = cur->getNext();
	}
	std::cout << std::endl;
}
#endif // !STACK_H