#ifndef TREE_H
#define TREE_H 
//#pragma once

#include <iostream>


#include "Stack.h"
#include "Iterator.h"
#include "DFT_iterator.h"
#include "Elem.h"



template <class T_key, class T_value>
class Tree {
private:
	

	Elem<T_key, T_value>* root;

	//int* digit = new int(*data);
	//this->data = digit;

public:
	
	Iterator<T_key>* create_dft_iterator() {
		return new dft_iterator<T_key, T_value>(root);
	}


	Tree() { // create blank list
		this->root = nullptr;
	}

	Tree(T_key data, T_value val) { // create list with one element
		Elem<T_key, T_value>* elem = new Elem<T_key, T_value>(&data, &val);
		this->root = elem;
		this->root->color = false; // root only black

		Elem<T_key, T_value>* right_nil = new Elem<T_key, T_value>(nullptr, nullptr, nullptr, nullptr, nullptr, false);
		Elem<T_key, T_value>* left_nil = new Elem<T_key, T_value>(nullptr, nullptr, nullptr, nullptr, nullptr, false);

		root->next_left = left_nil;
		left_nil->parent = root;

		root->next_right = right_nil;
		right_nil->parent = root;
	}

	

	void insert(T_key key, T_value val);

	void leftRotate(Elem<T_key, T_value>* y);

	void rightRotate(Elem<T_key, T_value>* x);

	void leftRightRotate(Elem<T_key, T_value>* y) {
		leftRotate(y);
		rightRotate(y);
	}

	void rightLeftRotate(Elem<T_key, T_value>* y) {
		rightRotate(y);
		leftRotate(y);
	}

	void remove(T_key key);

	void brtBalanceInsert(Elem<T_key, T_value>* x);

	void brtBalanceRemove(Elem<T_key, T_value>* x);

	bool contains(T_key data);

	Elem<T_key, T_value>* findElem(T_key data);

};

#include "Tree.cpp"

#endif // !TREE_H


