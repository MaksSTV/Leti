#pragma once
#ifndef LINKEDLIST_H
#pragma once

#include <iostream>
#include "LinkedListElem.h"

template<class T_link>
class List {
private:
	Elem_list<T_link>* head, * last, * cur;

public:
	List() { // create blank list
		this->head = NULL;
		this->last = this->head;
		this->cur = this->head;
	}

	List(T_link data) { // create list with one element
		Elem_list<T_link>* elem = new Elem_list(data);
		this->head = elem;
		this->last = elem;
		this->cur = elem;
	}

	void push_front(T_link item);

	void push_back(T_link item);

	void pop_front();

	void pop_back();

	void insert(T_link item, size_t index);

	T_link at(size_t index);

	void remove(size_t index);
	
	size_t get_size();
	
	void clear();

	void set(size_t index, T_link new_data);

	bool isEmpty();

	friend std::ostream& operator<< (std::ostream& out, const List& printList);

	void reverse();

	~List() = default;
	
	/*~List() {
		Elem_list<T_link>* elem = head;
		Elem_list<T_link>* tmp;
		while (elem != NULL) {
			tmp = elem;
			elem = elem->getNext();
			delete tmp;
		}
	}*/

};

#include "LinkedList.cpp"

#endif // !LINKEDLIST_H

