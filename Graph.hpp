#ifndef GRAPH_HPP
#define GRAPH_HPP
//orel55551234@gmail.com
//orel nissan
//322861527

#include <vector>
#include <iostream>

namespace ariel {
    class Graph {
    public:
        Graph(int rows, int cols);
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
