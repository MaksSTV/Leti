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

		brtBalanceInsert(temp);

	}
}

template<class T_key, class T_value>
void Tree<T_key, T_value>::leftRotate(Elem<T_key, T_value>* x)
{
	Elem<T_key, T_value>* right_child = x->next_right;
	x->next_right = right_child->next_left;
	if (right_child->next_left->data != nullptr) {
		right_child->next_left->parent = x;
	}
	right_child->parent = x->parent;
	if (x->parent == nullptr) {
		root = right_child;
	}
	else if (x == x->parent->next_left) {
		x->parent->next_left = right_child;
	}
	else {
		x->parent->next_right = right_child;
	}
	right_child->next_left = x;
	x->parent = right_child;
	
}

template<class T_key, class T_value>
inline void Tree<T_key, T_value>::rightRotate(Elem<T_key, T_value>* x)
{
	Elem<T_key, T_value>* left_child = x->next_left;  
	x->next_left = left_child->next_right;			  
	if (left_child->next_right->data != nullptr) {	 
		left_child->next_right->parent = x;			  
	}												
	left_child->parent = x->parent;					  
	if (x->parent == nullptr) {						 
		root = left_child;							  
	}												  
	else if (x == x->parent->next_right) {			 
		x->parent->next_right = left_child;			  
	}
	else {
		x->parent->next_left = left_child;
	}
	left_child->next_right = x;
	x->parent = left_child;
}

template<class T_key, class T_value>
void Tree<T_key, T_value>::remove(T_key key)
{
	Elem<T_key, T_value>* delete_elem = findElem(key);
	Elem<T_key, T_value>* x = nullptr;

	if ((root->next_left->color == false) && (root->next_right->color == false)) {
		delete root;
		root = nullptr;
	}

	bool originalColor = true; 
	if ((delete_elem->next_left->data == nullptr) && (delete_elem->next_right->data == nullptr)) {
		
		Elem<T_key, T_value>* nil = new Elem<T_key, T_value>(nullptr, nullptr, nullptr, nullptr, nullptr, false);
		
		delete delete_elem->next_left;
		delete delete_elem->next_right;
		
		nil->parent = delete_elem->parent;
		if (delete_elem->parent->next_left == delete_elem) {
			delete_elem->parent->next_left = nil;
		}
		else {
			delete_elem->parent->next_right = nil;
		}

		delete delete_elem;
	}
	else if ((delete_elem->next_left->data == nullptr) && (delete_elem->next_right->data != nullptr)) {
		originalColor = delete_elem->color;
		delete delete_elem->next_left;
		x = delete_elem->next_right;

		x->parent = delete_elem->parent;
		if (delete_elem->parent->next_left == delete_elem) {
			delete_elem->parent->next_left = x;
		}
		else {
			delete_elem->parent->next_right = x;
		}

		delete delete_elem;
		
	}
	else if ((delete_elem->next_left->data != nullptr) && (delete_elem->next_right->data == nullptr)) {
		originalColor = delete_elem->color;
		delete delete_elem->next_right;
		x = delete_elem->next_left;
		
		x->parent = delete_elem->parent;
		if (delete_elem->parent->next_right == delete_elem) {
			delete_elem->parent->next_right = x;
		}
		else {
			delete_elem->parent->next_left = x;
		}

		delete delete_elem;
		
	}
	else {
		
		Elem<T_key, T_value>* y = delete_elem->next_right;

		while (y->next_left->data != nullptr) { // 1
			y = y->next_left; // min right subtree
		}
		originalColor = y->color; // 2

		x = y->next_right; // 3

		if (y->parent == delete_elem) { // 4
			x->parent = delete_elem;
			delete_elem->next_right = x;
		}
		else {
			//y->next_right = y; // 5
			x->parent = y->parent;
			y->parent->next_left = x;
		}

		//y = delete_elem; // 6
		delete_elem->data = y->data;
		delete_elem->val = y->val;


		y->color = originalColor; // 7

		delete y->next_left;
		delete y;
	}

	if (originalColor == false) {
		brtBalanceRemove(x);
	}
}

template<class T_key, class T_value>
void Tree<T_key, T_value>::brtBalanceInsert(Elem<T_key, T_value>* x)
{

	Elem<T_key, T_value>* grandParent;
	while (x->parent->color == true) {
		if (x->parent == x->parent->parent->next_right) {
			grandParent = x->parent->parent->next_left;
			if (grandParent->color == true) {
				
				grandParent->color = false;
				x->parent->color = false;
				x->parent->parent->color = true;
				x = x->parent->parent;

			}
			else {
				if (x == x->parent->next_left) {
					x = x->parent;
					rightRotate(x);
				}
				x->parent->color = false;
				x->parent->parent->color = true;
				leftRotate(x->parent->parent);
			}
		}
		else {
			grandParent = x->parent->parent->next_right;
			if (grandParent->color == true) {
				grandParent->color = false;
				x->parent->color = false;
				x->parent->parent->color = true;
				x = x->parent->parent;
			}
			else {
				if (x == x->parent->next_right) {
					x = x->parent;
					leftRotate(x);
				}

				x->parent->color = false;
				x->parent->parent->color = true;
				rightRotate(x->parent->parent);
			}
		}
		if (x == root) {
			break;
		}
	}
	root->color = 0;
}

template<class T_key, class T_value>
void Tree<T_key, T_value>::brtBalanceRemove(Elem<T_key, T_value>* x)
{
	Elem<T_key, T_value>* x_bro; // w in lucture

	while ((x != root) && (x->color != false)) {
		if (x->parent->next_left == x) {
			x_bro = x->parent->next_right;
			if (x_bro->color == true) {
				x_bro->color = false;
				x->parent->color = true;
				leftRotate(x->parent);
				x_bro = x->parent->next_right;
			}
			if ((x_bro->next_right->color == false) && (x_bro->next_left->color == false)) {
				x_bro->color = true;
				x = x->parent;
			}
			else {
				if (x_bro->next_right->color == false) {
					x_bro->next_left->color = false;
					x_bro->color = true;
					rightRotate(x_bro);
					x_bro = x->parent->next_right;
				}
				x_bro->color = x->parent->color;
				x->parent->color = false;
				x_bro->next_right->color = false;
				leftRotate(x->parent);
				x = root;
			}
		}
		else{
			x_bro = x->parent->next_left;
			if (x_bro->color == true) {
				x_bro->color = false;
				x->parent->color = true;
				rightRotate(x->parent);
				x_bro = x->parent->next_left;
			}
			if ((x_bro->next_right->color == false) && (x_bro->next_left->color == false)) {
				x_bro->color = true;
				x = x->parent;
			}
			else {
				if (x_bro->next_left->color == false) {
					x_bro->next_right->color = false;
					x_bro->color = true;
					leftRotate(x_bro);
					x_bro = x->parent->next_left;
				}
				x_bro->color = x->parent->color;
				x->parent->color = false;
				x_bro->next_left->color = false;
				rightRotate(x->parent);
				x = root;
			}
		}
	}
	x->color = false; 
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
		foundNode = new_dft_iterator->getCur();// ����� ������, � ��� ������ ���
		if (new_dft_iterator->next() == data) {
			delete new_dft_iterator;
			return foundNode;
		}
	}
	delete new_dft_iterator;
	throw std::invalid_argument("Element not found!");
}

#endif // !TREE_CPP
