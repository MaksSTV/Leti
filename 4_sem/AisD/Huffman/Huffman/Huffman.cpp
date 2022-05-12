// Huffman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include "Tree.h"
#include "HuffmanTree.h"
#include "HuffmanCode.h"

// I
// creating a list in which each node has a pair of symbol + frequency of occurrence
// if there is such a symbol, then ++, if not, then push back()
// sort this list (for example, with a bubble)
// 
//
// II
// TODO...


int main()
{
	//Take care of the person in yourself.
	//A person must dream in order to see the meaning of life.
	std::string string = "A person must dream in order to see the meaning of life";
	std::cout << "\nSource string:\n" << string << std::endl << std::endl;

	HuffCode huffString = HuffCode(string);

	std::cout << huffString.codingSourceString() << std::endl << std::endl;
	
	huffString.getTableFrequenciesAndCodes();
	std::cout << std::endl;

	std::cout << huffString.decodingEncodedString() << std::endl << std::endl;

	std::cout << huffString.volumeSourseString() << std::endl;
	std::cout << huffString.volumeEncodeString() << std::endl;
	std::cout << huffString.compressionRatio() << std::endl;

	system("pause");
	return 0;
}
