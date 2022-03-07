#ifndef TREE_CPP
#define TREE_CPP

//#pragma once


#include "Tree.h"

//#include <iostream>


template<class T_key, class T_value>
void Tree<T_key, T_value>::insert(T_key key, T_value val)
{
	if (root == nullptr) {
		Elem<T_key, T_value>* elem = new Elem<T_key, T_value>(&key, &val);
		this->root = elem;
		this->root->color = false;

		Elem<T_key, T_value>* right_nil = new Elem<T_key, T_value>(nullptr, nullptr, nullptr, nullptr, nullptr, false);
		Elem<T_key, T_value>* left_nil = new Elem<T_key, T_value>(nullptr, nullptr, nullptr, nullptr, nullptr, false);

		

		root->next_left = left_nil;
		left_nil->parent = root;

		root->next_right = right_nil;
		right_nil->parent = root;
	}
	else {
		Elem<T_key, T_value>* temp = new Elem<T_key, T_value>(&key, &val);//8
		Elem<T_key, T_value>* cur = root;//10

		while (true) {
			if (*temp->data > *cur->data) {
				if (cur->next_right->data == nullptr) {
						cur->next_right = temp;
						temp->parent = cur;
						break;
				}
				else {
						cur = cur->next_right;
				}
			}
			else {
				if (cur->next_left->data == nullptr) {
						cur->next_left = temp;
						temp->parent = cur;
						break;
				}
				else {
						cur = cur->next_left;
				}
			}
		}

		Elem<T_key, T_value>* right_nil = new Elem<T_key, T_value>(nullptr, nullptr, nullptr, nullptr, nullptr, false);
		Elem<T_key, T_value>* left_nil = new Elem<T_key, T_value>(nullptr, nullptr, nullptr, nullptr, nullptr, false);

		temp->next_left = left_nil;
		left_nil->parent = temp;

		temp->next_right = right_nil;
		right_nil->parent = temp;

	}
}

template<class T_key, class T_value>
void Tree<T_key, T_value>::leftRotate(Elem<T_key, T_value>* y)
{
	// now 'y' is son of 'x'
	// and 'z' is grandPa of 'x'
	Elem<T_key, T_value>* x = y->parent;
	Elem<T_key, T_value>* z = x->parent;
	if (x->parent == nullptr) {
		z = nullptr;
	}
	else {
		z = x->parent;
	}
	
	if (y->next_left->data != nullptr) {
		x->next_right = y->next_left;
	}

	if (z == nullptr) {
		y = root;
	}
	else if (z->next_left == x) {
		z->next_left = y;
		y->parent = z;
	}
	else {
		z->next_right = y;
		y->parent = z;
	}

	x->next_right = y->next_left; // y->next_left = x->next_right;
	y->next_left = x;		// x->next_right = y;
	x->parent = y;			// y->parent = x;
}
							


template<class T_key, class T_value>
inline void Tree<T_key, T_value>::rightRotate(Elem<T_key, T_value>* x)
{
	// now 'x' is son of 'y'
		// and 'z' is grandPa of 'y'
		Elem<T_key, T_value>* y = x->parent;
		Elem<T_key, T_value>* z;
		if (y->parent == nullptr) {
			z = nullptr;
		}
		else {
			z = y->parent;
		}

		if (x->next_right->data != nullptr) {
			y->next_left = x->next_right;
		}

		if (z == nullptr) {
			x = root;
		}
		else if (z->next_right == y) {
			z->next_right = x;
			x->parent = z;
		}
		else {
			z->next_left = x;
			x->parent = z;
		}

		y->next_left = x->next_right;
		x->next_right = y;
		y->parent = x;
}

template<class T_key, class T_value>
bool Tree<T_key, T_value>::contains(T_key data)
{
	try {
			findElem(data);
			return true;
	}
	catch (std::invalid_argument) {
		return false;
	}
}

template<class T_key, class T_value>
Elem<T_key, T_value>* Tree<T_key, T_value>::findElem(T_key data)
{
	Elem<T_key, T_value>* foundNode = nullptr;

	dft_iterator<T_key, T_value>* new_dft_iterator;
	
	new_dft_iterator = new dft_iterator<T_key, T_value>(root);

	while (new_dft_iterator->has_next()) {
		foundNode = new_dft_iterator->getCur();// здесь приват, € щас вытащю его
		if (new_dft_iterator->next() == data) {
			delete new_dft_iterator;
			return foundNode;
		}
	}
	delete new_dft_iterator;
	throw std::invalid_argument("Element not found!");
}

#endif // !TREE_CPP