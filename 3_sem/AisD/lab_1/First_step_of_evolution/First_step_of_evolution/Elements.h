#ifndef ELEM_H
#pragma once

#include <iostream>
class Elem_list {
private:
	Elem_list* next, * prev;
	int data;
public:
	Elem_list(int data = 0, Elem_list* next = NULL, Elem_list* prev = NULL) : data(data), next(next), prev(prev) {}
	~Elem_list() = default;

	void setNext(Elem_list* newnext) {
		this->next = newnext;
	}

	void setPrev(Elem_list* newprev) {
		this->prev = newprev;
	}

	Elem_list* getNext() {
		return this->next;
	}

	Elem_list* getPrev() {
		return this->prev;
	}

	Elem_list* makeNULL() {
		return this->next = NULL;
	}

	int getPrevdata() {
		if (this->prev == NULL) {
			return 0;
		}
		else
			return this->prev->data;
	}

	int getNextdata() {
		if (this->next == NULL) {
			return 0;
		}
		else
			return this->next->data;
	}

	int getElemdata() {
		return this->data;
	}

	void setnewData(int new_data) {
		this->data = new_data;
	}
};
#endif // !ELEM_H

