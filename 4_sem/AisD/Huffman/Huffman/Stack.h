#ifndef STACK_H
#pragma once

#include<iostream>

template <class T>
class Stack
{
private:

	class Elem_stack
	{
	private:
		T data;
		Elem_stack* next;

	public:

		Elem_stack(T data, Elem_stack* next = nullptr) : data(data), next(next) {}
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

	Elem_stack* head;
public:
	Stack();

	~Stack();

	void pop();

	void push(T data);

	bool isEmpty();

	T peek();
};

template <class T> Stack<T>::Stack()
{
	head = nullptr;
}

template <class T>
Stack<T>::~Stack()
{
	while (!isEmpty()) {
		pop();
	}
}

template <class T> void Stack<T>::push(T data)
{
	Elem_stack* temp = new Elem_stack(data);
	Elem_stack* cur = head; // 1
	this->head = temp; // 2
	this->head->setNext(cur); // 3

}

template <class T> void Stack<T>::pop()
{
	if (isEmpty()) {
		throw std::out_of_range("No more elements");
	}
	else {
		Elem_stack* temp = head;
		head = head->getNext();
		delete temp;
	}
}

template <class T> bool Stack<T>::isEmpty()
{
	if (head == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

template <class T> T Stack<T>::peek()
{
	if (isEmpty()) {
		throw std::out_of_range("Empty");
	}
	else {
		return head->getElemdata();
	}

}

#endif // !STACK_H