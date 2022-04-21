#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP




#include "LinkedList.h"
#include <iostream>

template<class T_link>
void List<T_link>::push_front(T_link item) { // insert before first elem
	if (head == nullptr) {
		this->cur = this->head;
		Elem_list<T_link>* temp = new Elem_list<T_link>(item);
		head = temp;
		last = head;
		last->makeNULL();
		head->makeNULL();
	}
	else {
		this->cur = this->head;
		Elem_list<T_link>* temp = new Elem_list<T_link>(item);
		temp->setNext(head);
		this->head = temp;
		this->cur->setPrev(head);
	}
}

template<class T_link>
void List<T_link>::push_back(T_link item) { // insert after last elem
	if (head == NULL) {
		push_front(item);
	}
	else {
		this->cur = this->last;
		Elem_list<T_link>* temp = new Elem_list<T_link>(item);
		this->last->setNext(temp);
		this->last = temp;
		this->last->setPrev(cur);
	}
}

template<class T_link>
void List<T_link>::pop_front() { // delete first elem
	if (head == NULL) {
		throw std::runtime_error("Failed to execute the function pop_front()\n");
	}
	else {
		cur = head;
		head = head->getNext();
		delete cur;
	}
}

template<class T_link>
void List<T_link>::pop_back() { // delete last elem
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

template<class T_link>
void List<T_link>::insert(T_link item, size_t index) {
	// insert elem by index
	cur = head;
	int count = 0;
	bool flag = 0;
	if (index == count) {
		push_front(item); flag = 1;
	}
	if (index == get_size()) {
		push_back(item); flag = 1;
	}
	else {
		cur = head;
		while (cur != NULL) {
			if (index == count + 1) {
				flag = 1;
				Elem_list<T_link>* cur_0 = cur;
				Elem_list<T_link>* temp = new Elem_list(item);
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

template<class T_link>
int List<T_link>::at(size_t index) {
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

template<class T_link>
void List<T_link>::remove(size_t index) {
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
				Elem_list<T_link>* prev_0 = cur;
				cur = cur->getNext();
				Elem_list<T_link>* temp = cur;
				cur = cur->getNext();
				prev_0->setNext(cur);
				cur->setPrev(prev_0);
				delete temp;
			}
			count++;
			cur = cur->getNext();
		}
	}
	if (index > get_size()) {
		throw std::invalid_argument("Failed to execute the function remove()\n");
	}
}

template<class T_link>
size_t List<T_link>::get_size() { // get size list
	cur = head;
	int count = 0;
	while (cur != NULL) {
		count++;
		cur = cur->getNext();
	}
	return count;
}

template<class T_link>
void List<T_link>::clear() { // delete full list
	cur = head;
	while (cur != NULL) {
		head = cur->getNext();
		delete cur;
		cur = head;
	}
}

template<class T_link>
void List<T_link>::set(size_t index, T_link new_data) {//change element by index
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

template<class T_link>
bool List<T_link>::isEmpty() {// check if list is empty
	if (head == NULL) {
		return true;
	}
	else {
		return false;
	}
}

template<class T_link>
void List<T_link>::reverse() { // reverve list
	if (get_size() <= 1) return;

	int temp;

	for (size_t i = 0; i < get_size() / 2; i++) {
		temp = at(i);
		set(i, at(get_size() - 1 - i));
		set(get_size() - 1 - i, temp);
	}
};

template<class T_link>
std::ostream& operator<< (std::ostream& out, List<T_link>& printList) {
	// Overload operator output
	out << "List: \n";
	for (int index = 0; index < printList.get_size(); index++) {
		out << printList.at(index) << std::endl;
	}
	return out;
}


#endif // !LINKEDLIST_CPP