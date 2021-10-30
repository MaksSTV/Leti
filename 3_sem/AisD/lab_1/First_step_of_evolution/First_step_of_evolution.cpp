// The_first_step_of_evolution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//12389

#include <iostream>
#include "Method.h"


int main() {
	List list(12);
	list.push_front(13);
	list.push_back(14);
	if (!list.isEmpty()) std::cout << "List is not empty.\n";
	else { std::cout << "List is empty.\n"; }

	for (int index = 0; index < 5; index++) {
		list.push_back(index + 10);
	}

	std::cout << "Size list: " << list.get_size() << std::endl;

	list.pop_front();
	list.pop_back();
	list.remove(3);

	list.insert(21, 3);
	list.insert(22, 5);

	std::cout << "Element by index 3:" << list.at(3) << std::endl;
	list.set(3, 35);
	list.insert(99, 5);
	list.reverse();
	
	list.insert(99, 0);
	std::cout << list << std::endl;

	std::cout << "Delete full list.\n";
	list.clear();
	std::cout << list.get_size();

	List list_1(12);
	list_1.push_front(14);
	list_1.push_back(13);
	list_1.push_back(11);
	list_1.set(0, 99);

	List list_2;
	list_2.push_front(14);
	list_2.push_back(13);
	list_2.set(1, 0);
	std::cout << list_1<<std::endl;
	std::cout << list_2;
	system("pause");
	return 0;
}
