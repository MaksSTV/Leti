#ifndef PARSEPRICELIST_H
#pragma once
#include <iostream>

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

            subline = line;//Saint Petersburg;Moscow;10;20
            posit = line.find(';');
            subline.resize(posit);
            vertices->push_back(subline);
            edge_1.from = subline;
            edge_2.to = subline;
            line.erase(0, posit + 1);//Moscow;10;20

            subline = line;
            posit = line.find(';');
            subline.resize(posit);
            vertices->push_back(subline);
            edge_1.to = subline;
            edge_2.from = subline;
            line.erase(0, posit + 1);//10;20

            subline = line;
            posit = line.find(';');
            subline.resize(posit);//10;20
            if (subline != "N/A") {
                edge_1.cost = std::stoi(subline);
                adjacencyMatrix->push_front(edge_1);
            }

            line.erase(0, posit + 1);//20
            if (line != "N/A") {
                edge_2.cost = std::stoi(line);
                adjacencyMatrix->push_front(edge_2);
            }
        }
    }
    priceList.close();
}

#endif // !PARSEPRICELIST_H