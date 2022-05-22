#ifndef ALGORITHM_H
#pragma once

#include <iostream>
#include <string>

#include "Vertex.h"
#include "LinkedList.h"
#include "Parse.h"

enum {
    WHITE, GREY, BLACK
};

int countUniqueVertex(List<std::string>& vertices) {
    //O(N^3)
    if (!vertices.isEmpty()) {

        size_t countNotUniqueVertex = vertices.get_size();

        for (int i = 0; i < countNotUniqueVertex - 1; i++)
            for (int j = i + 1; j < countNotUniqueVertex; j++)
                if (vertices.at(i) == vertices.at(j))
                {
                    vertices.remove(j);
                    countNotUniqueVertex--;
                    j--;
                }

        return vertices.get_size();
    }
    else {
        return -1;
    }
}

void setUniqueNumberTown(List<Vertex>& edge, List<std::string>& vertices) {
    //O(N^3)
    size_t uniqueNumberTown = edge.get_size();
    size_t countUniqueVertex = vertices.get_size();

    for (int i = 0; i < uniqueNumberTown; i++) {
        for (int j = 0; j < countUniqueVertex; j++) {
            if (edge.at(i).input == vertices.at(j)) {
                edge.at(i).in = j;
            }
            if (edge.at(i).output == vertices.at(j)) {
                edge.at(i).out = j;
            }
        }
    }
}

void convertListToMatrix(List<Vertex>& graph, List<std::string>& vertex, int** matrix) {
    //O(N^2)
    int size = vertex.get_size();           // 0 0 0 0
    for (int i = 0; i < size; i++) {        // 0 0 0 0
        for (int j = 0; j < size; j++) {    // 0 0 0 0
            matrix[i][j] = 0;               // 0 0 0 0
        }
    }   

    int countEdges = graph.get_size(); // 8;
    for (int i = 0, index, jndex; i < countEdges; i++) {
        index = graph.at(i).in;
        jndex = graph.at(i).out;
        matrix[index][jndex] = graph.at(i).capacity;
    }
    for (int i = 0; i < size; i++) {        
        for (int j = 0; j < size; j++) {    
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

int min(const int& x, const int& y) { // O(N)
    return x < y ? x : y;
}

void enque(const int& x, int& tail, int* queue, int* color) { // O(N)
    queue[tail] = x;     
    tail++;          
    color[x] = GREY; 
}

int deque(int& head, int* queue, int* color) { // O(N)  
    int x = queue[head]; 
    head++;           
    color[x] = BLACK; 
    return x;         
}

int bfs(int start, int end, int* color, int** capacity, int** flow, int* path, const int& size, int* queue){
    // O(N^3)
    int head, tail;
    int u, v;
    for (u = 0; u < size; u++) { // O(N)
        color[u] = WHITE;
    }

    head = 0;
    tail = 0;
    enque(start, tail, queue, color); // O(N)
    path[start] = -1;   
    while (head != tail){ // O(N^3)
        u = deque(head, queue, color); // O(N)
        for (v = 0; v < size; v++){ // O(N^2)
            if (color[v] == WHITE && (capacity[u][v] - flow[u][v]) > 0) {
                enque(v, tail, queue, color); // O(N)
                path[v] = u;
            }
        }
    }
    return color[end] == BLACK ? 0 : 1;
}

int max_flow(const int& source, const int& stock, List<std::string>& vertex, int** capacity, int** flow) {
    // O(N^6)
    int size = vertex.get_size(); // O(N)

    int* color = new int[size]; // Color for vertex
    int* path = new int[size]; // Array of paths
    int* queue = new int[size]; // Queue for custom bfs

    int i, j, u;
    int maxflow = 0;
    for (i = 0; i < size; i++){ // O(N^2)
        for (j = 0; j < size; j++) {
            flow[i][j] = 0;
        }
    }
    while (bfs(source, stock, color, capacity, flow, path, size, queue) == 0){ // O(N^6)
        int delta = 10000;
        for (u = size - 1; path[u] >= 0; u = path[u]) { // O(N^2)
            delta = min(delta, (capacity[path[u]][u] - flow[path[u]][u]));
        }
        for (u = size - 1; path[u] >= 0; u = path[u]) { // O(N)
            flow[path[u]][u] += delta;
            flow[u][path[u]] -= delta;
        }
        maxflow += delta;
    }

    delete[] color;
    delete[] path;
    delete[] queue;

    return maxflow;
}

int findMaxFlow(List<Vertex>& graph, List<std::string>& vertex) {

    int size; // count vertex = 6

    //List<Vertex> graph;
    //List<std::string> vertex;

    //parse(graph, vertex); // O(N^2)
    countUniqueVertex(vertex); // O(N^3)
    setUniqueNumberTown(graph, vertex); // O(N^3)

    size = vertex.get_size();

    int** capacity = new int* [size]; // matrix with capacity
    int** flow = new int* [size]; // matrix with flow (adjacency matrix)


    for (int i = 0; i < size; i++) {
        capacity[i] = new int[size];
        flow[i] = new int[size];
    }

    convertListToMatrix(graph, vertex, capacity); //O(N^2)

    auto maxFlow = max_flow(0, size - 1, vertex, capacity, flow);
    std::cout<<maxFlow<<std::endl; // O(N^6)

    for (int i = 0; i < size; i++) {
        delete[] capacity[i];
        delete[] flow[i];
    }
    delete[] capacity;
    delete[] flow;

    return maxFlow;
}

#endif // !ALGORITHM_H