#ifndef EDGE_H
#pragma once
#include <iostream>

struct Edge {
    std::string from;
    std::string to;
    int cost = 0;
    int numberFromTown = -1;
    int numberToTown = -1;
};

#endif // !EDGE_H