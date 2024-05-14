#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include <string>

namespace ariel {
    class Algorithms {
    public:
        static bool isConnected(const Graph& g);
        static std::string shortestPath(const Graph& g, size_t start, size_t end);
        static std::string isBipartite(const Graph& g);
        static std::string isContainsCycle(const Graph& g);
        static std::string negativeCycle(const Graph& g);

    private:
        static void dfs1(const Graph& g, size_t v, std::vector<bool>& visited);
        static void dfs(const Graph& graph, size_t vertex, std::vector<bool>& visited, std::vector<size_t>& parent, bool& hasCycle, size_t& cycleStart, size_t& cycleEnd);
    };
}

#endif