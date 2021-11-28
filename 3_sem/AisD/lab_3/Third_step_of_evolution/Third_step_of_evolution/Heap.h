#ifndef HEAP_H

#pragma once

#include <iostream>

#include "Queue.h"
#include "Stack.h"
#include "Iterator.h"

class Heap {
private:

	class Elem {
	public:
		Elem* next_left, * next_right, * parent;
		int data;

		Elem(int data = 0, Elem* next_left = NULL, Elem* next_right = NULL, Elem* parent = NULL) : data(data), next_left(next_left), next_right(next_right), parent(parent) {}
		~Elem() = default;


	};

	Elem* root;

	int height; // height binary heap (flesh heap)
	// int last_layer; // last_layer = 2^(height-1) | local parametr
	int Last_fullness; // how many nodes do we have on last_layer

public:

	Iterator* create_dft_iterator() {
		return new dft_iterator(root);
	}

	Iterator* create_bft_iterator() {
		bft_iterator* new_bft_iterator = new bft_iterator(root);
		new_bft_iterator->queue->enqueue(root);
		return new_bft_iterator;
	}
	

	class dft_iterator : public Iterator
	{
	public:

		friend class Heap;

		dft_iterator(Elem*);

		~dft_iterator();

		bool has_next() override;

		int next() override;

	private:

		Stack<Elem*>* stack;

		Elem* cur;
	};

	class bft_iterator : public Iterator
	{
	public:
		friend class Heap;

		bft_iterator(Elem*);

		~bft_iterator();

		bool has_next() override;

		int next() override;


	private:

		Queue<Elem*>* queue;

		Elem* cur;
	};

	Heap() { // create blank list
		this->root = NULL;
		this->height = 0;
		this->Last_fullness = 0;
	}

	Heap(int data) { // create list with one element
		Elem* elem = new Elem(data);
		this->root = elem;
		this->height = 1;
		this->Last_fullness = 1;
	}

	Elem* LastParent(int layer) {

		Elem* parent_last = root;

		int temp_layer = layer;
		int temp_Last_fullness = this->Last_fullness;

		if (this->Last_fullness > layer) {
			temp_layer = temp_layer * 2;
		}

		while (temp_layer != 2) {
			if (temp_Last_fullness <= (temp_layer / 2)) {
				parent_last = parent_last->next_left;
				temp_layer = temp_layer / 2;
			}
			else {
				parent_last = parent_last->next_right;
				temp_Last_fullness = temp_Last_fullness - temp_layer / 2;
				temp_layer = temp_layer / 2;
			}
		}

		return parent_last;
	}

	void siftDown(Elem* temp) {

		if (temp->next_left == NULL && temp->next_right == NULL) {
			return;
		}

		Elem* max = temp;

		if (temp->next_right == NULL) {
			if (temp->data < temp->next_left->data) {
				max = temp->next_left;
			}
			else {
				return;
			}
		}

		if (temp->next_left != NULL && temp->next_right != NULL) {
			if (temp->data < temp->next_right->data || temp->data < temp->next_left->data) {
				if (temp->next_left->data > temp->next_right->data) {
					max = temp->next_left;
				}
				else {
					max = temp->next_right;
				}
			}
			else {
				return;
			}
		}

		int swap = temp->data;
		temp->data = max->data;
		max->data = swap;
		siftDown(max);

	}

	void siftUp(Elem* temp) {
		if (temp->parent == NULL) {
			return;
		}
		else {
			if (temp->data > temp->parent->data) {
				int swap = temp->data;
				temp->data = temp->parent->data;
				temp->parent->data = swap;
				siftUp(temp->parent);
			}
			else {
				return;
			}
		}
	}

	void Heapify(Elem* temp) {
		if (temp->parent == NULL) {
			siftDown(temp);
		}
		else
			if ((temp->data) > (temp->parent->data)) {
				siftUp(temp);
			}
			else {
				siftDown(temp);
			}
	}

	void insert(int key) {
		if (root == NULL) {
			Elem* elem = new Elem(key);
			this->root = elem;
			this->Last_fullness = 1;
			this->height = 1;
		}
		else {
			Elem* temp = new Elem(key);
			Elem* cur = root;

			int last_layer = 1;
			this->Last_fullness++;

			for (int index = 0; index < height - 1; index++) {
				last_layer = last_layer * 2; // last_layer = 2 ^ (height - 1)
			}

			if (last_layer < this->Last_fullness) {
				this->Last_fullness = 1;
				this->height++;
				last_layer = last_layer * 2;
			}

			cur = LastParent(last_layer);

			if (cur->next_left == NULL) {
				cur->next_left = temp;
				temp->parent = cur;
			}
			else {
				cur->next_right = temp;
				temp->parent = cur;
			}

			Heapify(temp);
		}
	}

	bool contains(int data) {
		try {
			findElem(data);
			return true;
		}
		catch (std::invalid_argument) {
			return false;
		}
	}

	Elem* findElem(int data) {
		Elem* foundNode = NULL;

		dft_iterator* new_dft_iterator;
		new_dft_iterator = new dft_iterator(root);

		while (new_dft_iterator->has_next()) {
			foundNode = new_dft_iterator->cur;

			if (new_dft_iterator->next() == data) {
				delete new_dft_iterator;
				return foundNode;
			}
		}
		delete new_dft_iterator;
		throw std::invalid_argument("Element not found!");
	}

	void remove(int key) {

		Elem* delete_elem = findElem(key);


		if (root->next_left == NULL && root->next_right == NULL) {
			delete root;
			root = NULL;
			height = 0; Last_fullness = 0;
		}

		int last_layer = 1;

		for (int index = 0; index < height - 1; index++) {
			last_layer = last_layer * 2; // last_layer = 2 ^ (height - 1)
		}

		Elem* last_elem = LastParent(last_layer);

		if (last_elem->next_right != NULL) {
			last_elem = last_elem->next_right; // remember last elem
			last_elem->parent->next_right = NULL; // detele last elem
			Last_fullness--;
		}
		else {
			last_elem = last_elem->next_left; // remember last elem
			last_elem->parent->next_left = NULL; // detele last elem
			Last_fullness--;
		}

		if (Last_fullness == 0) {
			Last_fullness = 1;
			height--;
			for (int index = 0; index < height - 1; index++) {
				Last_fullness = Last_fullness * 2;
			}

		}
		if (delete_elem == last_elem) { delete last_elem; }
		else {
			int swap = last_elem->data;
			last_elem->data = delete_elem->data;
			delete_elem->data = swap;
			delete last_elem;

			Heapify(delete_elem);
		}

	}

};

Heap::dft_iterator::dft_iterator(Elem* root) {
	cur = root;
	stack = new Stack<Elem*>();
}

Heap::bft_iterator::bft_iterator(Elem* root) {
	cur = root;
	queue = new Queue<Elem*>();
}

Heap::dft_iterator::~dft_iterator() {
	delete stack;
}

Heap::bft_iterator::~bft_iterator() {
	delete queue;
}

bool Heap::dft_iterator::has_next() {
	return cur != NULL;
}

int Heap::dft_iterator::next() {
	if (!has_next()) {
		throw std::out_of_range("No more elements");
	}

	int temp = cur->data;

	if (cur->next_right != NULL) {
		stack->push(cur->next_right);
	}

	if (cur->next_left != NULL) {
		cur = cur->next_left;
	}
	else {
		try {
			cur = stack->peek();
			stack->pop();
		}
		catch (std::out_of_range) {
			cur = NULL;
		}
	}

	return temp;
}

bool Heap::bft_iterator::has_next() {
	return cur != NULL;
}

int Heap::bft_iterator::next() {
	if (!has_next()) {
		throw std::out_of_range("No more elements");
	}

	int temp = cur->data;

	if (cur->next_left != NULL) {
		queue->enqueue(cur->next_left);
	}

	if (cur->next_right != NULL) {
		queue->enqueue(cur->next_right);
	}

	queue->dequeue();

	try {
		cur = queue->front();
	}
	catch (std::out_of_range) {
		cur = NULL;
	}

	return temp;
}

#endif // !HEAP_H


