// Third_step_of_evolution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Queue.h"
#include "Stack.h"
#include "Iterator.h"
#include "Heap.h"

int main()
{
	
	Heap flesh_heap/*(1)*/;
	Iterator* dft_1, *dft_2, *dft_3;
	Iterator* bft_1, *bft_2;

	/*flesh_heap.insert(2);
	flesh_heap.insert(30);
	flesh_heap.insert(4); 
	flesh_heap.insert(5); 
	flesh_heap.insert(100); 
	flesh_heap.insert(40); 
	flesh_heap.insert(6);
	flesh_heap.insert(7); */


	/*if (flesh_heap.contains(4)) {
		std::cout << "Yes, Elem if found\n";
	}
	else
		std::cout << "Error!!! Not found\n";
	if (flesh_heap.contains(4000)) {
		std::cout << "Yes, Elem if found\n";
	}
	else
		std::cout << "Error!!! Not found\n";*/

	dft_1 = flesh_heap.create_dft_iterator();
	bft_1 = flesh_heap.create_bft_iterator();

	std::cout << "Go around heap:" << std::endl;
	int temp = 0;
	if (dft_1->has_next()) {
		while (dft_1->has_next()) {
			std::cout << dft_1->next() << "\n";
		}
	}

	std::cout << std::endl;

	std::cout << "Go around heap:" << std::endl;

	if (bft_1->has_next()) {
		while (bft_1->has_next()) {
			std::cout << bft_1->next() << "\n";
		}
	}

	std::cout << std::endl;

	flesh_heap.remove(6);
	flesh_heap.remove(1);
	flesh_heap.remove(5);
	flesh_heap.remove(40);
	flesh_heap.remove(7);
	
	
	
	dft_2 = flesh_heap.create_dft_iterator();
	bft_2 = flesh_heap.create_bft_iterator();

	std::cout << "Go around heap:" << std::endl;

	if (dft_2->has_next()) {
		while (dft_2->has_next()) {
			std::cout << dft_2->next() << "\n";
		}
	}

	std::cout << std::endl;

	std::cout << "Go around heap:" << std::endl;

	if (bft_2->has_next()) {
		while (bft_2->has_next()) {
			std::cout << bft_2->next() << "\n";
		}
	}

	std::cout << std::endl;
		
	delete dft_1;
	delete bft_1;
	delete dft_2;
	delete bft_2;
	system("pause");
	return 0;
}