#ifndef STACK_H
#pragma once

#include<iostream>

class Stack {
private:

	class Elem_stack {
	private:
		Elem_stack* next;
		int data;
	public:
		Elem_stack(int data = 0, Elem_stack* next = NULL) : data(data), next(next) {}
		~Elem_stack() = default;

		void setNext(Elem_stack* newnext) {
			this->next = newnext;
		}

		Elem_stack* getNext() {
			return this->next;
		}

		int getElemdata() {
			return this->data;
		}
	};

	Elem_stack* head, * last;

public:

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

};

#endif // !STACK_H