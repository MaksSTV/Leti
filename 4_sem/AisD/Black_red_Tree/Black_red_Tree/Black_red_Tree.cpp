// Black_red_Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Tree {
	private:
		class Elem {
		public:
			Elem* next_left, * next_right, * parent;
			int* data;
			
			Elem(int *data = nullptr, Elem* next_left = nullptr, Elem* next_right = nullptr, Elem* parent = nullptr) :
			next_left(next_left), next_right(next_right), parent(parent) {
				int* digit = new int(*data);
				this->data = digit;	
			}
			~Elem() = default;
		};

		Elem* root;

	
	 
	public:
		Tree() { // create blank list
			this->root = NULL;
		}

		Tree(int data) { // create list with one element
			Elem* elem = new Elem(&data);
			this->root = elem;
		}

	

		void insert(int key) {
		if (root == NULL) {
			Elem* elem = new Elem(&key);
			this->root = elem;
			
		}
		else {
			Elem* temp = new Elem(&key);//8
			Elem* cur = root;//10
			
			while (true) {
				if (*temp->data > *cur->data) {
					if (cur->next_right == NULL) {
						cur->next_right = temp;
						temp->parent = cur;
						break;
					}
					else {
						cur = cur->next_right;
					}
				}
				else {
					if (cur->next_left == NULL) {
						cur->next_left = temp;
						temp->parent = cur;
						break;
					}
					else {
						cur = cur->next_left;
					}
				}
			}
		}
	}

		void leftRotate(Elem* y){
		// now 'y' is son of 'x'
		// and 'z' is grandPa of 'x'
		Elem* x = y->parent;
		Elem* z = x->parent;

		if (y->next_left->data != nullptr) {
			x->next_right = y->next_left;
		}

		if (z == nullptr) {
			y = root;
		}
		else if (z->next_left == x) {
			z->next_left = y;
		}
		else {
			z->next_right = y;
		}

		x->parent = y;
	}

		void rightRotate(Elem* x){
		// now 'x' is son of 'y'
		// and 'z' is grandPa of 'y'
		Elem* y = x->parent;
		Elem* z = y->parent;

		if (x->next_right->data != nullptr) {
			y->next_left = x->next_right;
		}

		if (z == nullptr) {
			x = root;
		}
		else if (z->next_right == y) {
			z->next_right = x;
		}
		else {
			z->next_left = x;
		}

		y->parent = x;
	}

		void leftRightRotate(Elem* y){
		leftRotate(y);
		rightRotate(y);
	}

		void rightLeftRotate(Elem* y){
		rightRotate(y);
		leftRotate(y);
	}
};

int main()
{
	Tree bucha(10);			

	bucha.insert(8);
	bucha.insert(12);
	bucha.insert(11);
	bucha.insert(6);
	bucha.insert(3);

	system("pause");
	return 0;
}
