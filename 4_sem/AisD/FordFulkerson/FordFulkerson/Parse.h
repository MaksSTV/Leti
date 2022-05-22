#ifndef PARSE_H
#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "Vertex.h"
#include "LinkedList.h"

void parse(List<Vertex>& graph, List<std::string>& vertices) {

    std::fstream priceList;

    priceList.open("PriceList.txt", std::ios_base::in);
    if (priceList.bad()) {
        throw std::runtime_error("Cannot open this file");
    }
    else {
        std::string line;
        std::string subline;
        std::string::size_type posit = 0;
        while (std::getline(priceList, line))
        {
            Vertex vertex;
            
            subline = line;
            posit = line.find(' ');
            subline.resize(posit);
            vertices.push_back(subline);
            vertex.input = subline;
            line.erase(0, posit + 1);

            subline = line;
            posit = line.find(' ');
            subline.resize(posit);
            vertices.push_back(subline);
            vertex.output = subline;
            line.erase(0, posit + 1);

            vertex.capacity = std::stoi(line);
            graph.push_back(vertex);

        }
    }
    priceList.close();
}

#endif // !PARSE_H