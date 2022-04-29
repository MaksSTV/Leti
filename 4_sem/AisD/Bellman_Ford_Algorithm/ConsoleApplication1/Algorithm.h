#ifndef ALGORITHM_H
#pragma once

int countUniqueVertex(List<std::string>* vertices) {

    if (!vertices->isEmpty()) {

        size_t countNotUniqueVertex = vertices->get_size();

        for (int i = 0; i < countNotUniqueVertex - 1; i++)
            for (int j = i + 1; j < countNotUniqueVertex; j++)
                if (vertices->at(i) == vertices->at(j))
                {
                    vertices->remove(j);
                    countNotUniqueVertex--;
                    j--;
                }

        return vertices->get_size();
    }
    else {
        return -1;
    }
}

void setUniqueNumberTown(List<Edge>* edge, List<std::string>* vertices) {

    size_t uniqueNumberTown = edge->get_size();
    size_t countUniqueVertex = vertices->get_size();

    for (int i = 0; i < uniqueNumberTown; i++) {
        for (int j = 0; j < countUniqueVertex; j++) {
            if (edge->at(i).from == vertices->at(j)) {
                edge->at(i).numberFromTown = j;
            }
            if (edge->at(i).to == vertices->at(j)) {
                edge->at(i).numberToTown = j;
            }
        }
    }
}

int algorithm(List<Edge>* edge, List<std::string>* vertices, std::string from, std::string to) {

    size_t countVertex = countUniqueVertex(vertices);
    size_t countEdge = edge->get_size();

    setUniqueNumberTown(edge, vertices);

    int* matrixCost = new int[countVertex];
    int conditionalInfinity = INT_MAX - 10000;

    for (int i = 0; i < countVertex; i++) {
        if (vertices->at(i) == from) {
            matrixCost[i] = 0;
        }
        else {
            matrixCost[i] = conditionalInfinity;
        }
    }

    for (int i = 0; i < countVertex - 1; i++) {
        for (int j = 0; j < countEdge; j++) {
            if (matrixCost[edge->at(j).numberFromTown] + edge->at(j).cost < matrixCost[edge->at(j).numberToTown]) {
                matrixCost[edge->at(j).numberToTown] = matrixCost[edge->at(j).numberFromTown] + edge->at(j).cost;
            }
        }
    }

    for (int i = 0; i < countVertex; i++) {
        if (from == to) {
            std::cout << std::endl << from << "->" << to << "=" << "Not path" << std::endl;
            return conditionalInfinity;
        }
        else {
            if (vertices->at(i) == to) {
                std::cout << std::endl << from << "->" << to << "=" << matrixCost[i] << std::endl;
                return matrixCost[i];
            }
        }
    }
    delete[] matrixCost;
}


#endif // !ALGORITHM_H