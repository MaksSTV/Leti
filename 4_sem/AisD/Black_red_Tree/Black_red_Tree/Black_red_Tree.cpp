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
};

int main()
{
	Tree bucha(10);			// null-10-8-12

	bucha.insert(8);
	bucha.insert(12);
	bucha.insert(11);
	bucha.insert(6);
	bucha.insert(3);

	system("pause");
	return 0;
}
