#ifndef ALGORITHM_H
#pragma once

int countUniqueVertex(List<std::string>* vertices) {

    if (!vertices->isEmpty()) {

        size_t n = vertices->get_size();

        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (vertices->at(i) == vertices->at(j))
                {
                    vertices->remove(j);
                    n--;
                    j--;
                }

        return vertices->get_size();
    }
    else {
        return -1;
    }
}

void setUniqueNumberTown(List<Edge>* edge, List<std::string>* vertices) {

    size_t n = edge->get_size();
    size_t m = vertices->get_size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
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

    size_t n = countUniqueVertex(vertices);
    size_t m = edge->get_size();

    setUniqueNumberTown(edge, vertices);

    int* d = new int[n];
    int conditionalInfinity = INT_MAX - 10000;

    for (int i = 0; i < n; i++) {
        if (vertices->at(i) == from) {
            d[i] = 0;
        }
        else {
            d[i] = conditionalInfinity;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (d[edge->at(j).numberFromTown] + edge->at(j).cost < d[edge->at(j).numberToTown]) {
                d[edge->at(j).numberToTown] = d[edge->at(j).numberFromTown] + edge->at(j).cost;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (from == to) {
            std::cout << std::endl << from << "->" << to << "=" << "Not path" << std::endl;
            return conditionalInfinity;
        }
        else {
            if (vertices->at(i) == to) {
                std::cout << std::endl << from << "->" << to << "=" << d[i] << std::endl;
                return d[i];
            }
        }
    }
}


#endif // !ALGORITHM_H