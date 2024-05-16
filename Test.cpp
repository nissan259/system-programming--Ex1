#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <vector>
#include <random>
//orel55551234@gmail.com
//orel nissan
//322861527

using namespace ariel;

const int SMALL_GRAPH_SIZE = 5;
const int LARGE_GRAPH_SIZE = 1000;

TEST_CASE("Test isConnected - Single vertex graph") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {{0}};
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == true);
}

TEST_CASE("Test isConnected - Connected graph (simple)") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {{0, 1, 1}, {1, 0, 1}, {1, 1, 0}};
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == true);
}

TEST_CASE("Test isConnected - Disconnected graph (simple)") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {{0, 1, 0}, {1, 0, 0}, {0, 0, 0}};
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == false);
}

TEST_CASE("Test isConnected - Connected graph (large)") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
            {1, 0, 1, 0, 0, 0, 1, 0, 0, 0},
            {0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
            {0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
            {0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
            {1, 0, 0, 0, 1, 0, 1, 0, 0, 0},
            {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
            {0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
            {0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
            {0, 0, 0, 0, 1, 0, 0, 0, 1, 0}};
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == true);
}

TEST_CASE("Test isConnected - Disconnected graph (large)") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
            {0, 0, 0, 0, 0, 1, 0, 1, 1, 1},
            {0, 0, 0, 0, 0, 1, 1, 0, 1, 1},
            {0, 0, 0, 0, 0, 1, 1, 1, 0, 1},
            {0, 0, 0, 0, 0, 1, 1, 1, 1, 0}};
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == false);
}

TEST_CASE("Test isConnected - Connected graph (undirected)") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 1, 0},
            {1, 1, 0, 0, 1},
            {0, 1, 0, 0, 1},
            {0, 0, 1, 1, 0}};
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == true);
}

TEST_CASE("Test isConnected - Connected graph (directed)") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 1, 0, 0, 0},
            {0, 0, 1, 1, 0},
            {1, 0, 0, 0, 1},
            {0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0}};
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == true);
}

TEST_CASE("Test isConnected - Disconnected graph (undirected)") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 1, 0, 0, 0},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0}};
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == false);
}

TEST_CASE("Test isConnected - Disconnected graph (directed)") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}};
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == false);
}

TEST_CASE("Test isConnected - Graph with self-loop") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {{1, 1, 0}, {1, 1, 1}, {0, 1, 0}};
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == true);
}

TEST_CASE("Test isConnected - Graph with multiple connected components") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 1, 0, 0, 0, 0},
            {1, 0, 1, 0, 0, 0},
            {0, 1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0},
            {0, 0, 0, 1, 0, 1},
            {0, 0, 0, 0, 1, 0}};
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == false);
}

TEST_CASE("Test isConnected - Graph with isolated vertices") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 1, 0, 0, 0},
            {1, 0, 1, 0, 0},
            {0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}};
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == false);
}

TEST_CASE("Test isConnected - Graph with negative weights") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {0, -1, 1, 0, 0},
            {-1, 0, -1, 1, 0},
            {1, -1, 0, 0, 1},
            {0, 1, 0, 0, -1},
            {0, 0, 1, -1, 0}};
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == true);
}

TEST_CASE("Test isConnected - Graph with negative weights and disconnected components") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {0, -1, 1, 0, 0, 0},
            {-1, 0, -1, 1, 0, 0},
            {1, -1, 0, 0, 1, 0},
            {0, 1, 0, 0, -1, 0},
            {0, 0, 1, -1, 0, 0},
            {0, 0, 0, 0, 0, 0}};
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == false);
}

TEST_CASE("Test isConnected - Graph with negative weights and self-loops") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {-1, -1, 1, 0, 0},
            {-1, -1, -1, 1, 0},
            {1, -1, -1, 0, 1},
            {0, 1, 0, -1, -1},
            {0, 0, 1, -1, -1}};
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == true);
}

TEST_CASE("Test isConnected - Graph with parallel edges") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 1, 0},
            {1, 1, 0, 0, 1},
            {0, 1, 0, 0, 1},
            {0, 0, 1, 1, 0}};
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == true);
}

TEST_CASE("Test isConnected - Graph with mixed weights") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 1, -2, 3, 0},
            {1, 0, 0, -1, 2},
            {-2, 0, 0, 0, 1},
            {3, -1, 0, 0, -2},
            {0, 2, 1, -2, 0}};
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == true);
}

TEST_CASE("Test isConnected - Graph with no edges") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = std::vector<std::vector<int>>(SMALL_GRAPH_SIZE, std::vector<int>(SMALL_GRAPH_SIZE, 0));
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == false);
}

TEST_CASE("Test isConnected - Connected large sparse graph") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = std::vector<std::vector<int>>(LARGE_GRAPH_SIZE, std::vector<int>(LARGE_GRAPH_SIZE, 0));
    for (std::vector<int>::size_type i = 0; i < LARGE_GRAPH_SIZE - 1; ++i) {
        adjacencyMatrix[i][i + 1] = 1;
        adjacencyMatrix[i + 1][i] = 1;
    }
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == true);
}

TEST_CASE("Test isConnected - Graph with a single strongly connected component") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 1, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 1, 0},
            {0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0}};
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == true);
}

TEST_CASE("Test isConnected - Graph with multiple strongly connected components") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 1, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0},
            {1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 0, 1},
            {0, 0, 0, 1, 0, 0}};
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == false);
}

TEST_CASE("Test isConnected - Disconnected graph with self-loops") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {1, 0, 0, 0, 0},
            {0, 1, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}};
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == false);
}

TEST_CASE("Test isConnected - Graph with a combination of positive and negative weights") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 2, 0, -3, 0},
            {2, 0, -1, 0, 4},
            {0, -1, 0, 0, -2},
            {-3, 0, 0, 0, 0},
            {0, 4, -2, 0, 0}};
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == true);
}
TEST_CASE("Test isConnected - Graph with a combination of positive and negative weights (modified)") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 5, 0, -2, 0},
            {5, 0, -3, 0, 1},
            {0, -3, 0, 0, -4},
            {-2, 0, 0, 0, 0},
            {0, 1, -4, 0, 0}};
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == true);
}
TEST_CASE("Test isConnected - Graph with a combination of positive and negative weights") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 2, 0, -3, 0},
            {2, 0, -1, 0, 4},
            {0, -1, 0, 0, -2},
            {-3, 0, 0, 0, 0},
            {0, 4, -2, 0, 0}};
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == true);
}
