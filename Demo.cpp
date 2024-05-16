/*
 * Demo program for Exercise 2.
 * Author: Benjamin Saldman.
 */

//orel55551234@gmail.com
//orel nissan
//322861527

#include "Graph.hpp"
#include "Algorithms.hpp"
using ariel::Algorithms;
//orel55551234@gmail.com
//orel nissan
//322861527
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

constexpr int MAGIC_NUMBER_5 = 5;

int main()
{
    ariel::Graph graph;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> adjacencyMatrix = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    graph.loadGraph(adjacencyMatrix); // Load the graph to the object.

    graph.printGraph();                                    // Should print: "Graph with 3 vertices and 4 edges."
    cout << Algorithms::isConnected(graph) << endl;        // Should print: "1" (true).
    cout << Algorithms::shortestPath(graph, 0, 2) << endl; // Should print: 0->1->2.
    cout << Algorithms::isContainsCycle(graph) << " graph 1 "<<endl;    // Should print: "The graph does not contain a cycle. graph 1".
    cout << Algorithms::isBipartite(graph) << endl;        // Should print: "The graph is bipartite: A={0, 2}, B={1}."

    // 5x5 matrix that represents a non-connected graph with a cycle.
    vector<vector<int>> adjacencyMatrix2 = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}};

    graph.loadGraph(adjacencyMatrix2); // Load the graph to the object.

    graph.printGraph();                                    // Should print: "Graph with 5 vertices and 8 edges."
    cout << Algorithms::isConnected(graph) << endl;        // Should print: "0" (false).
    cout << Algorithms::shortestPath(graph, 0, 4) << endl; // Should print: "-1" (there is no path between 0 and 4).
    cout << Algorithms::isContainsCycle(graph) << " graph2"<< endl;    // Should print: "0->1->2->0 graph2".
    cout << Algorithms::isBipartite(graph) << endl;        // Should print: "0" (false).

    // 5x5 matrix that represents a connected weighted graph.
    vector<vector<int>> adjacencyMatrix3 = {
            {0, 1, 2, 0, 0},
            {1, 0, 3, 0, 0},
            {2, 3, 0, 4, 0},
            {0, 0, 4, 0, MAGIC_NUMBER_5},
            {0, 0, 0, MAGIC_NUMBER_5, 0}};
    graph.loadGraph(adjacencyMatrix3); // Load the graph to the object.

    graph.printGraph();                                    // Should print: "Graph with 5 vertices and 10 edges."
    cout << Algorithms::isConnected(graph) << endl;        // Should print: "1" (true).
    cout << Algorithms::shortestPath(graph, 0, 4) << endl; // Should print: 0->2->3->4.
    cout << Algorithms::isContainsCycle(graph) << " graph 3"<< endl;    // Should print: "The graph does not contain a cycle. graph 3".
    cout << Algorithms::isBipartite(graph) << endl;        // Should print: "The graph is bipartite: A={0, 2, 4}, B={1, 3}."

    // 5x4 matrix that represents an invalid graph.
    vector<vector<int>> adjacencyMatrix4 = {
            {0, 1, 2, 0},
            {1, 0, 3, 0},
            {2, 3, 0, 4},
            {0, 0, 4, 0},
            {0, 0, 0, MAGIC_NUMBER_5}};
    try
    {
        graph.loadGraph(adjacencyMatrix4); // Load the graph to the object.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print: "Error: Dimension mismatch while loading the graph."
    }
    return 0;
}