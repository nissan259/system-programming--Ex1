#include "Algorithms.hpp"
#include <climits>
#include <queue>

using namespace std;
using namespace ariel;

void Algorithms::dfs(const Graph& graph, size_t vertex, vector<bool>& visited, vector<size_t>& parent, bool& hasCycle, size_t& cycleStart, size_t& cycleEnd) {
    visited[vertex] = true;
    const auto& adjMatrix = graph.getAdjacencyMatrix();
    for (size_t i = 0; i < adjMatrix.size(); ++i) {
        if (adjMatrix[vertex][i] != 0) {
            if (!visited[i]) {
                parent[i] = vertex;
                dfs(graph, i, visited, parent, hasCycle, cycleStart, cycleEnd);
                if (hasCycle) {
                    return;
                }
            } else if (i != parent[vertex]) {
                hasCycle = true;
                cycleStart = i;
                cycleEnd = vertex;
                return;
            }
        }
    }
}

bool Algorithms::isConnected(const Graph& g) {
    const auto& adjMatrix = g.getAdjacencyMatrix();
    vector<bool> visited(adjMatrix.size(), false);

    // Perform DFS starting from vertex 0
    dfs1(g, 0, visited);

    // Check if all vertices are visited
    for (bool v : visited) {
        if (!v) {
            return false;
        }
    }

    return true;
}

string Algorithms::shortestPath(const Graph& graph, size_t start, size_t end) {
    const auto& adjMatrix = graph.getAdjacencyMatrix();
    vector<int> distances(adjMatrix.size(), INT_MAX);
    vector<size_t> parent(adjMatrix.size(), static_cast<size_t>(-1));
    distances[start] = 0;

    for (size_t i = 0; i < adjMatrix.size() - 1; ++i) {
        for (size_t source = 0; source < adjMatrix.size(); ++source) {
            for (size_t destination = 0; destination < adjMatrix.size(); ++destination) {
                if (adjMatrix[source][destination] != 0 && distances[source] != INT_MAX && distances[source] + adjMatrix[source][destination] < distances[destination]) {
                    distances[destination] = distances[source] + adjMatrix[source][destination];
                    parent[destination] = source;
                }
            }
        }
    }

    if (distances[end] == INT_MAX) {
        return "-1";
    }

    string path;
    size_t current = end;
    while (current != static_cast<size_t>(-1)) {
        path = to_string(current) + (path.empty() ? "" : "->") + path;
        current = parent[current];
    }

    return path;
}

string Algorithms::isBipartite(const Graph& graph) {
    const auto& adjMatrix = graph.getAdjacencyMatrix();
    vector<int> colors(adjMatrix.size(), -1);

    for (size_t i = 0; i < adjMatrix.size(); ++i) {
        if (colors[i] == -1) {
            colors[i] = 0;
            queue<size_t> queue;
            queue.push(i);

            while (!queue.empty()) {
                size_t vertex = queue.front();
                queue.pop();

                for (size_t j = 0; j < adjMatrix.size(); ++j) {
                    if (adjMatrix[vertex][j] != 0) {
                        if (colors[j] == -1) {
                            colors[j] = 1 - colors[vertex];
                            queue.push(j);
                        } else if (colors[j] == colors[vertex]) {
                            return "0";
                        }
                    }
                }
            }
        }
    }

    string result = "The graph is bipartite: A={";
    bool first = true;
    for (size_t i = 0; i < colors.size(); ++i) {
        if (colors[i] == 0) {
            result += (first ? "" : ", ") + to_string(i);
            first = false;
        }
    }
    result += "}, B={";
    first = true;
    for (size_t i = 0; i < colors.size(); ++i) {
        if (colors[i] == 1) {
            result += (first ? "" : ", ") + to_string(i);
            first = false;
        }
    }
    result += "}.";

    return result;
}

void Algorithms::dfs1(const Graph& graph, size_t vertex, vector<bool>& visited) {
    visited[vertex] = true;

    const auto& adjMatrix = graph.getAdjacencyMatrix();
    for (size_t i = 0; i < adjMatrix.size(); ++i) {
        if (adjMatrix[vertex][i] != 0 && !visited[i]) {
            dfs1(graph, i, visited);
        }
    }
}

string Algorithms::isContainsCycle(const Graph& graph) {
    const auto& adjMatrix = graph.getAdjacencyMatrix();
    vector<bool> visited(adjMatrix.size(), false);
    vector<size_t> parent(adjMatrix.size(), static_cast<size_t>(-1));
    bool hasCycle = false;
    size_t cycleStart = static_cast<size_t>(-1);
    size_t cycleEnd = static_cast<size_t>(-1);

    for (size_t i = 0; i < adjMatrix.size(); ++i) {
        if (!visited[i]) {
            dfs(graph, i, visited, parent, hasCycle, cycleStart, cycleEnd);
            if (hasCycle) {
                string cycle;
                size_t current = cycleEnd;
                while (current != cycleStart) {
                    cycle = to_string(current) + "->" + cycle;
                    current = parent[current];
                }
                cycle = to_string(cycleStart) + "->" + cycle + to_string(cycleStart);
                return cycle;
            }
        }
    }

    return "-1";
}

string Algorithms::negativeCycle(const Graph& graph) {
    const auto& adjMatrix = graph.getAdjacencyMatrix();
    vector<int> distances(adjMatrix.size(), 0);

    for (size_t i = 0; i < adjMatrix.size(); ++i) {
        for (size_t source = 0; source < adjMatrix.size(); ++source) {
            for (size_t destination = 0; destination < adjMatrix.size(); ++destination) {
                if (adjMatrix[source][destination] != 0 && distances[source] + adjMatrix[source][destination] < distances[destination]) {
                    if (i == adjMatrix.size() - 1) {
                        return "The graph contains a negative cycle.";
                    }
                    distances[destination] = distances[source] + adjMatrix[source][destination];
                }
            }
        }
    }

    return "The graph does not contain a negative cycle.";
}