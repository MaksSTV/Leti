﻿// Black_red_Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

//#include "Stack.h"
//#include "Iterator.h"
#include "Tree.h"

int main()
{

	// (не) рабочая хуета
	Tree<int, std::string> bucha(8, "Pudge"); //"Pudge"
	bucha.insert(15, "Mirana");
	bucha.insert(10, "Mirana");
	bucha.insert(20, "Mirana");
	bucha.insert(25, "Mirana");
	bucha.insert(30, "Mirana");
	bucha.insert(18, "Mirana");
	bucha.insert(19, "Mirana");
	bucha.insert(16, "Mirana");
	bucha.insert(17, "Mirana");
	//std::string str("Ancent_Apparation");
	/*bucha.insert(8, str);
	bucha.insert(12, "Mirana");
	bucha.insert(11, "Troll_Warlord");
	bucha.insert(6, "Spirit_Braker");
	bucha.insert(3, "Zeus");
	bucha.insert(7, "Underlord");*/

	/*int* a = new int(bucha.getLeftPointer());
	std::cout << *a << std::endl;

	int* b = new int(bucha.getRightPointer());
	std::cout << *b << std::endl;*/

	//bucha.remove(12);
	bucha.remove(15);

	if (bucha.contains(3)) {
		std::cout << "Yes, Elem if found\n";
	}
	else {
		std::cout << "Error!!! Not found\n";
	}
	system("pause");
	return 0;
}
