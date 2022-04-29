// Black_red_Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW

#include <iostream>
#include <string>


#include "Tree.h"

int main()
{

	
	Tree<int, std::string> bucha(33, "Pudge"); //"Pudge"
	bucha.insert(13, "Ancent_Apparation");
	bucha.insert(21, "Mirana");
	bucha.insert(20, "Troll_Warlord");
	bucha.insert(25, "Mirana");
	bucha.insert(30, "Spirit_Braker");
	bucha.insert(18, "Zeus");
	bucha.insert(19, "Underlord");
	bucha.insert(16, "Marci");
	bucha.insert(17, "Meepo");

	auto keys = bucha.getKeys();

	auto val = bucha.getValues();

	bucha.print();
	
	
	if (bucha.contains(20)) {
		std::cout << "Yes, Elem if found\n";
	}
	else {
		std::cout << "Error!!! Not found\n";
	}
	bucha.remove(20);

	if (bucha.contains(20)) {
		std::cout << "Yes, Elem if found\n";
	}
	else {
		std::cout << "Error!!! Not found\n";
	}

	bucha.clear();
	bucha.insert(15, "14");

	std::cout << "123\n";

	Tree<int, std::string> bukva(33, "Pudge");
	if (bukva.contains(33)) {
		std::cout << "Yes, Elem if found\n";
	}
	else {
		std::cout << "Error!!! Not found\n";
	}
	bukva.remove(33);

	Tree<int, int> tree(7, 10);
	tree.insert(8, 8);
	tree.insert(11, 12);
	tree.insert(10, 11);
	tree.insert(9, 6);
	tree.insert(12, 3);
	tree.remove(8);

	auto bla = tree.getKeys();

	

	std::cout << bla << std::endl;
	

	_CrtDumpMemoryLeaks();

	system("pause");

	
	return 0;
}
