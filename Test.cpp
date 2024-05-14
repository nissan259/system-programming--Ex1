#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <vector>
#include <random>



TEST_CASE("Test isConnected - Single vertex graph") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {{0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("Test isConnected - Connected graph (simple)") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {{0, 1, 1}, {1, 0, 1}, {1, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("Test isConnected - Disconnected graph (simple)") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {{0, 1, 0}, {1, 0, 0}, {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test isConnected - Connected graph (large)") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
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
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("Test isConnected - Disconnected graph (large)") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
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
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test isConnected - Connected graph (undirected)") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 1, 0},
            {1, 1, 0, 0, 1},
            {0, 1, 0, 0, 1},
            {0, 0, 1, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("Test isConnected - Connected graph (directed)") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0, 0, 0},
            {0, 0, 1, 1, 0},
            {1, 0, 0, 0, 1},
            {0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("Test isConnected - Disconnected graph (undirected)") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0, 0, 0},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test isConnected - Disconnected graph (directed)") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test isConnected - Graph with self-loop") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {{1, 1, 0}, {1, 1, 1}, {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("Test isConnected - Graph with multiple connected components") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0, 0, 0, 0},
            {1, 0, 1, 0, 0, 0},
            {0, 1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0},
            {0, 0, 0, 1, 0, 1},
            {0, 0, 0, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test isConnected - Graph with isolated vertices") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0, 0, 0},
            {1, 0, 1, 0, 0},
            {0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test isConnected - Graph with negative weights") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
            {0, -1, 1, 0, 0},
            {-1, 0, -1, 1, 0},
            {1, -1, 0, 0, 1},
            {0, 1, 0, 0, -1},
            {0, 0, 1, -1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("Test isConnected - Graph with negative weights and disconnected components") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
            {0, -1, 1, 0, 0, 0},
            {-1, 0, -1, 1, 0, 0},
            {1, -1, 0, 0, 1, 0},
            {0, 1, 0, 0, -1, 0},
            {0, 0, 1, -1, 0, 0},
            {0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test isConnected - Graph with negative weights and self-loops") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
            {-1, -1, 1, 0, 0},
            {-1, -1, -1, 1, 0},
            {1, -1, -1, 0, 1},
            {0, 1, 0, -1, -1},
            {0, 0, 1, -1, -1}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("Test isConnected - Graph with parallel edges") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 1, 0},
            {1, 1, 0, 0, 1},
            {0, 1, 0, 0, 1},
            {0, 0, 1, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("Test isConnected - Graph with mixed weights") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 1, -2, 3, 0},
            {1, 0, 0, -1, 2},
            {-2, 0, 0, 0, 1},
            {3, -1, 0, 0, -2},
            {0, 2, 1, -2, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("Test isConnected - Graph with no edges") {
    ariel::Graph g;
    std::vector<int>::size_type n = 5;
    std::vector<std::vector<int>> graph = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test isConnected - Connected large sparse graph") {
    ariel::Graph g;
    std::vector<int>::size_type n = 1000;
    std::vector<std::vector<int>> graph = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
    for (std::vector<int>::size_type i = 0; i < n - 1; ++i) {
        graph[i][i + 1] = 1;
        graph[i + 1][i] = 1;
    }
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}
TEST_CASE("Test isConnected - Graph with a single strongly connected component") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 1, 0},
            {0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("Test isConnected - Graph with multiple strongly connected components") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0},
            {1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 0, 1},
            {0, 0, 0, 1, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test isConnected - Disconnected graph with self-loops") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
            {1, 0, 0, 0, 0},
            {0, 1, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test isConnected - Graph with a combination of positive and negative weights") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 2, 0, -3, 0},
            {2, 0, -1, 0, 4},
            {0, -1, 0, 0, -2},
            {-3, 0, 0, 0, 0},
            {0, 4, -2, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

