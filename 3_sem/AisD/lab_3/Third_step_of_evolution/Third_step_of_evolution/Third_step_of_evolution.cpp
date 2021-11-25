// Third_step_of_evolution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Queue.h"
#include "Stack.h"

/*
*					Wish_List
*	- Сделать добавление элемента, пока просто по очереди.
*	- Вывод всей кучи рекурсией, 0_о.
*	- Удаление листьев.
*	- Поиск по индексу.
*	- Удаление по индексу.
*	- Итератор, че это ?
* 
*/


class Heap {
	private:

		class Elem {
			public:
				Elem *next_left, *next_right, *parent;
				int data;

				Elem(int data = 0, Elem* next_left = NULL, Elem* next_right = NULL, Elem* parent = NULL) : data(data), next_left(next_left), next_right(next_right), parent(parent) {}
				~Elem() = default;


		};

		Elem* root;

		int height; // height binary heap (flesh heap)
		// int last_layer; // last_layer = 2^(height-1) | local parametr
		int Last_fullness; // how many nodes do we have on last_layer

	public:
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
				// организовать добавление слева направо

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

				// cur =  найти крайнего родителя и вставить влево или вправо

				if (cur->next_left == NULL) {
					cur->next_left = temp;
					temp->parent = cur;
				}
				else {
					cur->next_right = temp;
					temp->parent = cur;
				}

				//Heapfy(temp)
			}
		}

		bool contains(int key){
			
			
		}

		void remove(int key){}

		//Iterator create_dft_iterator();

		//Iterator create_bft_iterator();

};


int main()
{
	

	system("pause");
	return 0;
}
