// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "LinkedList.h"

struct Edge {
    std::string from;
    std::string to;
    float cost = 0;
};

void parsePriceList(List<Edge>* adjacencyMatrix, List<std::string>* vertices) {
    std::fstream priceList;

    priceList.open("PriceList.txt", std::ios_base::in);
    if (priceList.bad()) {
        std::cout << "Error when opening a file for input!\n";
    }
    else {
        std::string line;
        std::string subline;
        std::string::size_type posit = 0;
        while (std::getline(priceList, line))
        {   
            Edge edge_1;
            Edge edge_2;
            
            subline = line;
            posit = line.find(';');
            subline.resize(posit);
            vertices->push_back(subline);
            edge_1.from = subline;
            edge_2.to = subline;
            line.erase(0, posit+1);

            subline = line;
            posit = line.find(';');
            subline.resize(posit);
            vertices->push_back(subline);
            edge_1.to = subline;
            edge_2.from = subline;
            line.erase(0, posit + 1);
                
            subline = line;
            posit = line.find(';');
            subline.resize(posit);
            if (subline != "N/A") {
                edge_1.cost = std::stof(subline);
                adjacencyMatrix->push_front(edge_1);
            }
                
            line.erase(0, posit + 1);
            if (line != "N/A") {
                edge_2.cost = std::stof(line);
                adjacencyMatrix->push_front(edge_2);
            }
        }
    }
    priceList.close();
}



int main()
{
    List<Edge> adjacencyMatrix; // get_size = edges count
    List<std::string> vertices; // get_size = vertices count

    

    parsePriceList(&adjacencyMatrix, &vertices);

    std::cout << adjacencyMatrix.get_size() << std::endl;
    std::cout << vertices.get_size() << std::endl;
    
    system("pause");
    return 0;
}