#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>

namespace ariel {
    class Graph {
    public:
        Graph(int r, int c);
        Graph();
        ~Graph();
        void loadGraph(const std::vector<std::vector<int>>& adjacencyMatrix);
        void printGraph() const;
        const std::vector<std::vector<int>>& getAdjacencyMatrix() const;

    private:
        int rows, cols;
        std::vector<std::vector<int>> matrix;
    };
}

#endif // GRAPH_HPP