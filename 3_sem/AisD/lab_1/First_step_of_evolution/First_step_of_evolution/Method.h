#ifndef METHODS_H
#pragma once

#include <iostream>
#include "Elements.h"

class List {
private:
	Elem_list* head, * last, * cur;

public:
	List() { // create blank list
		this->head = NULL;
		this->last = this->head;
		this->cur = this->head;
	}

	List(int data) { // create list with one element
		Elem_list* elem = new Elem_list(data);
		this->head = elem;
		this->last = elem;
	}

	void push_front(int item) { // insert before first elem
		if (head == NULL) {
			this->cur = this->head;
			Elem_list* temp = new Elem_list(item);
			head = temp;
			last = head;
			last->makeNULL();
			head->makeNULL();
		}
		else {
			this->cur = this->head;
			Elem_list* temp = new Elem_list(item);
			temp->setNext(head);
			this->head = temp;
			this->cur->setPrev(head);
		}
	}

	void push_back(int item) { // insert after last elem
		if (head == NULL) {
			push_front(item);
		}
		else {
			this->cur = this->last;
			Elem_list* temp = new Elem_list(item);
			this->last->setNext(temp);
			this->last = temp;
			this->last->setPrev(cur);
		}
	}

	void pop_front() { // delete first elem
		if (head == NULL) {
			throw std::runtime_error("Failed to execute the function pop_front()\n");
		}
		else {
			cur = head;
			head = head->getNext();
			delete cur;
		}
	}

	void pop_back() { // delete last elem
		if (last == head) {
			throw std::runtime_error("Failed to execute the function pop_front()\n");
		}
		else {
			cur = last;
			last = last->getPrev();
			delete cur;
			last->makeNULL();
		}
	}

	void insert(int item, size_t index) {
		// insert elem by index
		cur = head;
		int count = 0;
		bool flag = 0;
		if (index == count) { push_front(item); }
		else {
			while (cur != NULL) {
				if (index == count + 1) {
					flag = 1;
					Elem_list* cur_0 = cur;
					Elem_list* temp = new Elem_list(item);
					cur = cur->getNext();

					cur_0->setNext(temp);
					temp->setNext(cur);
					temp->setPrev(cur_0);
					cur->setPrev(temp);
				}
				count++;
				cur = cur->getNext();
			}
		}
		if (flag == 0) {
			throw std::invalid_argument("Failed to execute the function insert()\n");
		}
	}

	int at(size_t index) {
		// get elem by index
		cur = head;
		int count = 0;
		while (cur != NULL) {
			if (index == count) {
				return cur->getElemdata();
			}
			count++;
			cur = cur->getNext();
		}
		if (cur == NULL) {
			throw std::invalid_argument("Not found in the function at()\n");
		}
	}

	void remove(size_t index) {
		if (index == 0) { // delete head element
			pop_front();
		}
		else if (index == get_size() - 1) { // delete last element
			pop_back();
		}
		else { // delete by index
			int count = 0;
			cur = head;
			while (cur != NULL) {
				if (count + 1 == index) {
					Elem_list* prev_0 = cur;
					cur = cur->getNext();
					Elem_list* temp = cur;
					cur = cur->getNext();
					prev_0->setNext(cur);
					cur->setPrev(prev_0);
					delete temp;
				}
				count++;
				cur = cur->getNext();
			}
		}
		if (index >= get_size() && index < 0) {
			throw std::invalid_argument("Failed to execute the function remove()\n");
		}
	}

	size_t get_size() { // get size list
		cur = head;
		int count = 0;
		while (cur != NULL) {
			count++;
			cur = cur->getNext();
		}
		return count;
	}

	void clear() { // delete full list
		cur = head;
		while (cur != NULL) {
			head = cur->getNext();
			delete cur;
			cur = head;
		}
	}

	void set(size_t index, int new_data) {//change element by index
		cur = head;
		int count = 0;
		bool flag = 0;
		while (cur != NULL) {
			if (index == count) {
				cur->setnewData(new_data);
				flag = 1;
				break;
			}
			else {
				count++;
				cur = cur->getNext();
			}
		}
		if (flag == 0) {
			throw std::invalid_argument("Failed to execute the function set()\n");
		}
	}

	bool isEmpty() {// check if list is empty
		if (head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	friend std::ostream& operator<< (std::ostream& out, const List& printList);

	void reverse() { // reverve list
		if (get_size() <= 1) return;

		int temp;

		for (size_t i = 0; i < get_size() / 2; i++) {
			temp = at(i);
			set(i, at(get_size() - 1 - i));
			set(get_size() - 1 - i, temp);
		}
	};

	~List() {
		Elem_list* elem = head;
		Elem_list* tmp;
		while (elem != NULL) {
			tmp = elem;
			elem = elem->getNext();
			delete tmp;
		}
	}

};

std::ostream& operator<< (std::ostream& out, List& printList) {
	// Overload operator output
	out << "List: \n";
	for (int index = 0; index < printList.get_size(); index++) {
		out << printList.at(index) << std::endl;
	}
	return out;
}

#endif // !METHODS_H

