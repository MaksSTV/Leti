// FordFulkerson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW

#include <iostream>

#include "Parse.h"
#include "Algorithm.h"

// S - start, T - end always. 

int main()
{
    List<Vertex> graph;
    List<std::string> vertex;

    parse(graph, vertex); // O(N^2)

    findMaxFlow(graph, vertex); // O(N^6)

    _CrtDumpMemoryLeaks();

    system("pause");
    return 0;
}