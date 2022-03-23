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
	//bucha.remove(15);

	if (bucha.contains(20)) {
		std::cout << "Yes, Elem if found\n";
	}
	else {
		std::cout << "Error!!! Not found\n";
	}

	bucha.clear();

	std::cout << "123\n";

	Tree<int, std::string> bukva(33, "Pudge");
	if (bukva.contains(33)) {
		std::cout << "Yes, Elem if found\n";
	}
	else {
		std::cout << "Error!!! Not found\n";
	}
	bukva.remove(33);
	_CrtDumpMemoryLeaks();

	system("pause");

	
	return 0;
}
