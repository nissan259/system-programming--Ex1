#include "Graph.hpp"
//orel55551234@gmail.com
//orel nissan
//322861527

namespace ariel {

    // Constructor with dimensions
    Graph::Graph(int rows, int cols) : rows(rows), cols(cols), matrix(static_cast<std::vector<int>::size_type>(rows), std::vector<int>(static_cast<std::vector<int>::size_type>(cols), 0)) {}

    // Default constructor
    Graph::Graph() : rows(0), cols(0) {}

    // Destructor - relies on vector's destructor, so no additional implementation is needed
    Graph::~Graph() {}

    // Load graph from an adjacency matrix
    void Graph::loadGraph(const std::vector<std::vector<int>>& adjacencyMatrix) {
        if (adjacencyMatrix.empty()) {
            std::cerr << "Error: Empty adjacency matrix." << std::endl;
            return;
        }

        size_t newRows = adjacencyMatrix.size();
        size_t newCols = adjacencyMatrix[0].size();

        // Check for consistent row sizes in the input matrix
        for (const auto& row : adjacencyMatrix) {
            if (row.size() != newCols) {
                std::cerr << "Error: Dimension mismatch while loading the graph." << std::endl;
                return;
            }
        }

        // If dimensions have changed, resize the matrix
        if (newRows != static_cast<size_t>(rows) || newCols != static_cast<size_t>(cols)) {
            rows = static_cast<int>(newRows);
            cols = static_cast<int>(newCols);
            matrix.resize(static_cast<std::vector<int>::size_type>(rows));
            for (auto& row : matrix) {
                row.resize(static_cast<std::vector<int>::size_type>(cols), 0);  // Initialize new elements to 0
            }
        }

        // Copy the contents of the adjacencyMatrix to the matrix
        for (size_t i = 0; i < newRows; ++i) {
            for (size_t j = 0; j < newCols; ++j) {
                matrix[i][j] = adjacencyMatrix[i][j];
            }
        }
    }

    // Print the graph
    void Graph::printGraph() const {
        int numVertices = static_cast<int>(matrix.size());   // Number of vertices is the size of the matrix
        int numEdges = 0;                  // Initialize edge count

        // Calculate the number of edges
        for (const auto& row : matrix) {
            for (int val : row) {
                if (val != 0) {            // Assuming a non-zero value indicates an edge
                    numEdges++;
                }
            }
        }

        // Print only the structured information about the graph
        std::cout << "Graph with " << numVertices << " vertices and " << numEdges << " edges." << std::endl;
    }

    // Get adjacency matrix
    const std::vector<std::vector<int>>& Graph::getAdjacencyMatrix() const {
        return matrix;
    }

} // namespace ariel
