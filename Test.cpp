#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <vector>
#include <random>
// orel55551234@gmail.com
// orel nissan
// 322861527

using namespace ariel;

const int SMALL_GRAPH_SIZE = 5;
const int LARGE_GRAPH_SIZE = 1000;
const int EDGE_EXISTS = 1;
const int NO_EDGE = 0;
const int NEGATIVE_WEIGHT = -1;
const int edges=5;

TEST_CASE("Test isConnected - Single vertex graph") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {{0}};
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == true);
}

TEST_CASE("Test isConnected - Connected graph (simple)") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {NO_EDGE, EDGE_EXISTS, EDGE_EXISTS},
            {EDGE_EXISTS, NO_EDGE, EDGE_EXISTS},
            {EDGE_EXISTS, EDGE_EXISTS, NO_EDGE}
    };
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == true);
}

TEST_CASE("Test isConnected - Disconnected graph (simple)") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {NO_EDGE, EDGE_EXISTS, NO_EDGE},
            {EDGE_EXISTS, NO_EDGE, NO_EDGE},
            {NO_EDGE, NO_EDGE, NO_EDGE}
    };
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
            {0, 0, 0, 0, 1, 0, 0, 0, 1, 0}
    };
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
            {0, 0, 0, 0, 0, 1, 1, 1, 1, 0}
    };
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
            {0, 0, 1, 1, 0}
    };
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
            {0, 0, 0, 0, 0}
    };
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
            {0, 0, 1, 0, 0}
    };
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
            {0, 0, 0, 0, 0}
    };
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == false);
}

TEST_CASE("Test isConnected - Graph with self-loop") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {1, 1, 0},
            {1, 1, 1},
            {0, 1, 0}
    };
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
            {0, 0, 0, 0, 1, 0}
    };
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
            {0, 0, 0, 0, 0}
    };
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == false);
}

TEST_CASE("Test isConnected - Graph with negative weights") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {0, NEGATIVE_WEIGHT, EDGE_EXISTS, NO_EDGE, NO_EDGE},
            {NEGATIVE_WEIGHT, 0, NEGATIVE_WEIGHT, EDGE_EXISTS, NO_EDGE},
            {EDGE_EXISTS, NEGATIVE_WEIGHT, 0, NO_EDGE, EDGE_EXISTS},
            {NO_EDGE, EDGE_EXISTS, NO_EDGE, 0, NEGATIVE_WEIGHT},
            {NO_EDGE, NO_EDGE, EDGE_EXISTS, NEGATIVE_WEIGHT, 0}
    };
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == true);
}

TEST_CASE("Test isConnected - Graph with negative weights and disconnected components") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {0, NEGATIVE_WEIGHT, EDGE_EXISTS, NO_EDGE, NO_EDGE, NO_EDGE},
            {NEGATIVE_WEIGHT, 0, NEGATIVE_WEIGHT, EDGE_EXISTS, NO_EDGE, NO_EDGE},
            {EDGE_EXISTS, NEGATIVE_WEIGHT, 0, NO_EDGE, EDGE_EXISTS, NO_EDGE},
            {NO_EDGE, EDGE_EXISTS, NO_EDGE, 0, NEGATIVE_WEIGHT, NO_EDGE},
            {NO_EDGE, NO_EDGE, EDGE_EXISTS, NEGATIVE_WEIGHT, 0, NO_EDGE},
            {NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, 0}
    };
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == false);
}

TEST_CASE("Test isConnected - Graph with negative weights and self-loops") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {NEGATIVE_WEIGHT, NEGATIVE_WEIGHT, EDGE_EXISTS, NO_EDGE, NO_EDGE},
            {NEGATIVE_WEIGHT, NEGATIVE_WEIGHT, NEGATIVE_WEIGHT, EDGE_EXISTS, NO_EDGE},
            {EDGE_EXISTS, NEGATIVE_WEIGHT, NEGATIVE_WEIGHT, NO_EDGE, EDGE_EXISTS},
            {NO_EDGE, EDGE_EXISTS, NO_EDGE, NEGATIVE_WEIGHT, NEGATIVE_WEIGHT},
            {NO_EDGE, NO_EDGE, EDGE_EXISTS, NEGATIVE_WEIGHT, NEGATIVE_WEIGHT}
    };
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == true);
}

TEST_CASE("Test isConnected - Graph with parallel edges") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {0, EDGE_EXISTS, EDGE_EXISTS, NO_EDGE, NO_EDGE},
            {EDGE_EXISTS, 0, EDGE_EXISTS, EDGE_EXISTS, NO_EDGE},
            {EDGE_EXISTS, EDGE_EXISTS, 0, NO_EDGE, EDGE_EXISTS},
            {NO_EDGE, EDGE_EXISTS, NO_EDGE, 0, EDGE_EXISTS},
            {NO_EDGE, NO_EDGE, EDGE_EXISTS, EDGE_EXISTS, 0}
    };
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
            {0, 2, 1, -2, 0}
    };
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == true);
}

TEST_CASE("Test isConnected - Graph with no edges") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = std::vector<std::vector<int>>(SMALL_GRAPH_SIZE, std::vector<int>(SMALL_GRAPH_SIZE, NO_EDGE));
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == false);
}

TEST_CASE("Test isConnected - Connected large sparse graph") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = std::vector<std::vector<int>>(LARGE_GRAPH_SIZE, std::vector<int>(LARGE_GRAPH_SIZE, NO_EDGE));
    for (std::vector<int>::size_type i = 0; i < LARGE_GRAPH_SIZE - 1; ++i) {
        adjacencyMatrix[i][i + 1] = EDGE_EXISTS;
        adjacencyMatrix[i + 1][i] = EDGE_EXISTS;
    }
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == true);
}

TEST_CASE("Test isConnected - Graph with a single strongly connected component") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {0, EDGE_EXISTS, NO_EDGE, NO_EDGE, NO_EDGE},
            {NO_EDGE, 0, EDGE_EXISTS, NO_EDGE, NO_EDGE},
            {NO_EDGE, NO_EDGE, 0, EDGE_EXISTS, NO_EDGE},
            {NO_EDGE, NO_EDGE, NO_EDGE, 0, EDGE_EXISTS},
            {EDGE_EXISTS, NO_EDGE, NO_EDGE, NO_EDGE, 0}
    };
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == true);
}

TEST_CASE("Test isConnected - Graph with multiple strongly connected components") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {0, EDGE_EXISTS, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE},
            {NO_EDGE, 0, EDGE_EXISTS, NO_EDGE, NO_EDGE, NO_EDGE},
            {EDGE_EXISTS, NO_EDGE, 0, NO_EDGE, NO_EDGE, NO_EDGE},
            {NO_EDGE, NO_EDGE, NO_EDGE, 0, EDGE_EXISTS, NO_EDGE},
            {NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, 0, EDGE_EXISTS},
            {NO_EDGE, NO_EDGE, NO_EDGE, EDGE_EXISTS, NO_EDGE, 0}
    };
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
            {0, 0, 0, 0, 0}
    };
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
            {0, 4, -2, 0, 0}
    };
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == true);
}

TEST_CASE("Test isConnected - Graph with a combination of positive and negative weights (modified)") {
    Graph graph;
    std::vector<std::vector<int>> adjacencyMatrix = {
            {0, edges, 0, -2, 0},
            {edges, 0, -3, 0, 1},
            {0, -3, 0, 0, -4},
            {-2, 0, 0, 0, 0},
            {0, 1, -4, 0, 0}
    };
    graph.loadGraph(adjacencyMatrix);
    CHECK(Algorithms::isConnected(graph) == true);
}
