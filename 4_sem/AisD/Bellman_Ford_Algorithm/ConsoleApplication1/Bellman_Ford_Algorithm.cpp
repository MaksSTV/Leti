// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <limits.h>

#include "LinkedList.h"
#include "Edge.h"
#include "ParsePriceList.h"
#include "Algorithm.h"



int main()
{
    List<Edge> adjacencyMatrix; // get_size = edges count
    List<std::string> vertices; // get_size = vertices count not unique
    parsePriceList(&adjacencyMatrix, &vertices);
    int requiredPath = INT_MAX - 10000;
    requiredPath = algorithm(&adjacencyMatrix, &vertices, "Saint Petersburg", "Khabarovsk");
    std::cout << requiredPath << std::endl;


   
    system("pause");
    return 0;
}