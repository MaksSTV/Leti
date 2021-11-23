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
			private:
				Elem *next_left, *next_right, *parent;
				int data;
			public:
				Elem(int data = 0, Elem* next_left = NULL, Elem* next_right = NULL, Elem* parent = NULL) : data(data), next_left(next_left), next_right(next_right), parent(parent) {}
				~Elem() = default;
		};

		Elem* root, *last_leaf;
		// int layer; ?? надо ли?

	public:
		Heap() { // create blank list
			this->root = NULL;
		}

		Heap(int data) { // create list with one element
			Elem* elem = new Elem(data);
			this->root = elem;
		}
	
		void push(int item) {
			if (root == NULL) {
				Elem* elem = new Elem(item);
				this->root = elem;
			}
			else {
				Elem* temp = new Elem(item);
				Elem* cur = root; // 1
				// организовать добавление слева направо
			}
		}
};


int main()
{
	

	system("pause");
	return 0;
}
