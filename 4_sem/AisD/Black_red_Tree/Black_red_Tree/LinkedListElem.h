#ifndef LINKEDLISTELEM_H
#pragma once

#include <iostream>
template<class T_link>
class Elem_list {
private:
	Elem_list* next, * prev;
	T_link data;
public:
	Elem_list(T_link data = 0, Elem_list* next = NULL, Elem_list* prev = NULL) : data(data), next(next), prev(prev) {}
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

	T_link getPrevdata() {
		if (this->prev == NULL) {
			return 0;
		}
		else
			return this->prev->data;
	}

	T_link getNextdata() {
		if (this->next == NULL) {
			return 0;
		}
		else
			return this->next->data;
	}

	T_link getElemdata() {
		return this->data;
	}

	void setnewData(T_link new_data) {
		this->data = new_data;
	}
};


#endif // !LINKEDLISTELEM_H