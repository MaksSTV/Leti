// Black_red_Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

//#include "Stack.h"
//#include "Iterator.h"
#include "Tree.h"

int main()
{

	// (не) рабочая хуета
	Tree<int, std::string> bucha(10, "Pudge"); //"Pudge"
	std::string str("Ancent_Apparation");
	bucha.insert(8, str);
	bucha.insert(12, "Mirana");
	bucha.insert(11, "Troll_Warlord");
	bucha.insert(6, "Spirit_Braker");
	bucha.insert(3, "Zeus");

	int* a = new int(bucha.getLeftPointer());
	std::cout << *a << std::endl;

	int* b = new int(bucha.getRightPointer());
	std::cout << *b << std::endl;

	if (bucha.contains(11)) {
		std::cout << "Yes, Elem if found\n";
	}
	else {
		std::cout << "Error!!! Not found\n";
	}

	system("pause");
	return 0;
}
