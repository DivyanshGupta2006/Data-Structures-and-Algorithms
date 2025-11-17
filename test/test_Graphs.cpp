#include <iostream>
#include "Graph.h"

using namespace std;

#define pl(a) cout << a << "\n";

void test_Weighted_Graph() {
    // pl("--- Test Case 1: Weighted Undirected Graph ---")

    // create a new weighted undirected graph
    int V = 5;
    Graph g(V, false); // false = undirected

    // pl("------------------------Checking addEdge operation------------------------")
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 8);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 3);
    g.addEdge(2, 4, 9);
    g.addEdge(3, 4, 5);
    pl("Weighted graph created.")

    pl("------------------------Displaying Adjacency List------------------------")
    g.displayList();

    pl("------------------------Checking Dijkstra (Q4)------------------------")
    g.Dijkstra(0);

    // pl("------------------------Checking Prim's MST (Q6)------------------------")
    // g.Q6_MST_Prim(0);
    //
    // pl("------------------------Checking Cycle Detection (Q8)------------------------")
    // cout << "Is graph cyclic? " << (g.Q8_isCyclic() ? "Yes" : "No") << endl;
}

void test_Directed_Acyclic_Graph() {
    pl("\n--- Test Case 2: Directed Acyclic Graph (DAG) ---")

    int V = 6;
    Graph dag(V, true); // true = directed

    pl("------------------------Checking addEdge operation------------------------")
    dag.addEdge(5, 2);
    dag.addEdge(5, 0);
    dag.addEdge(4, 0);
    dag.addEdge(4, 1);
    dag.addEdge(2, 3);
    dag.addEdge(3, 1);
    pl("DAG created.")

    pl("------------------------Displaying Adjacency List------------------------")
    dag.displayList();

    pl("------------------------Checking Topological Sort (Q7)------------------------")
    dag.Q7_TopologicalSort();

    pl("------------------------Checking Cycle Detection (Q8)------------------------")
    cout << "Is graph cyclic? " << (dag.Q8_isCyclic() ? "Yes" : "No") << endl;
}

void test_Directed_Cyclic_Graph() {
    pl("\n--- Test Case 3: Directed Cyclic Graph (for SCCs) ---")

    int V = 5;
    Graph scc_graph(V, true); // true = directed

    pl("------------------------Checking addEdge operation------------------------")
    scc_graph.addEdge(1, 0);
    scc_graph.addEdge(0, 2);
    scc_graph.addEdge(2, 1);
    scc_graph.addEdge(0, 3);
    scc_graph.addEdge(3, 4);
    pl("Directed cyclic graph created.")

    pl("------------------------Displaying Adjacency List------------------------")
    scc_graph.displayList();

    pl("------------------------Checking Cycle Detection (Q8)------------------------")
    cout << "Is graph cyclic? " << (scc_graph.Q8_isCyclic() ? "Yes" : "No") << endl;

    pl("------------------------Checking Strongly Connected Components (Q9)------------------------")
    scc_graph.Q9_printSCCs();
}