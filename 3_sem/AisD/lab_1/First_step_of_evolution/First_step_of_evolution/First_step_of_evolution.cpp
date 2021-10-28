// The_first_step_of_evolution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

	list.reverse();

	std::cout << list << std::endl;

	std::cout << "Delete full list.\n";
	list.clear();
	system("pause");
	return 0;
}
