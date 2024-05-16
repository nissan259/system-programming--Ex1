This project deals with graph algorithms implemented in C++. It provides functionality to check if a graph is bipartite, detect negative cycles, find shortest paths, and more.
Getting Started

To get started with this project, follow these steps:

    Clone the repository:

    sh

git clone https://github.com/nissan259/system-programming--Ex1.git

Navigate to the project directory:

sh

cd system-programming--Ex1

Build the project:

sh

    make

Running Tests

To run the tests for this project, use the following commands:

sh

make test
./test

Cleaning the Project

To clean the project and remove all build files, use the following command:

sh

make clean

Running Tidy Test

To run the tidy test, use the following command:

sh

make tidy

Running Valgrind Test

To run the valgrind test, use the following command:

sh

make valgrind

Algorithms

The project includes the following algorithms:
isBipartite

The isBipartite function checks if a given graph is bipartite. It uses the tryColorGraph function to attempt coloring the graph with two colors such that no two adjacent vertices have the same color. If successful, the graph is bipartite.
negativeCycle

The negativeCycle function checks for the presence of a negative cycle in the graph. It uses the Bellman-Ford algorithm to relax the edges of the graph and detects if a negative cycle exists. If found, it constructs the negative cycle using the detectAndConstructCycle function.
shortestPath

The shortestPath function finds the shortest path between two vertices in the graph.
isConnected

The isConnected function checks if the graph is connected, meaning there is a path between every pair of vertices.
isContainsCycle

The isContainsCycle function checks if the graph contains a cycle.
Data Structures

The project utilizes various data structures, including:

    Vectors: Used to represent the graph, color arrays, parent arrays, and cycles.
    Queues: Used in certain algorithms, such as breadth-first search (BFS).

Graph Representation

The graph is represented using an adjacency matrix. The Graph class provides methods to load a graph from an adjacency matrix, print the graph, and retrieve the adjacency matrix.
Author

    Name: Orel Nissan
    ID: 322861527
    Email: orel55551234@gmail.com

Feel free to explore the code and utilize the provided algorithms for your graph-related needs!
