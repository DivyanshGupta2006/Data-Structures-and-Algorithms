#pragma once
#include <iostream>
#include "LinkedList.h"
#include "Queue_LinkedList.h"
#include "Stack_LinkedList.h"
#include "Heap.h"

using namespace std;

struct AdjPair {
    int dest;
    int weight;
    AdjPair() : dest(0), weight(0) {}
    AdjPair(int d, int w) : dest(d), weight(w) {}
};

struct HeapPair {
    int value;
    int vertex;
    HeapPair() : value(0), vertex(0) {}
    HeapPair(int v, int vert) : value(v), vertex(vert) {}
};

struct HeapPairGreater {
    bool operator()(const HeapPair& a, const HeapPair& b) const {
        return a.value > b.value;
    }
};

class Graph {
private:
    int V;
    bool isDirected;
    LinkedList<AdjPair>* adj;

    void DFS_recursive_helper(int v, bool* visited) {
        visited[v] = true;
        std::cout << v << " ";
        auto current = adj[v].head;
        while (current != nullptr) {
            int neighbor = current->value.dest;
            if (!visited[neighbor]) {
                DFS_recursive_helper(neighbor, visited);
            }
            current = current->next;
        }
    }

    void Q7_TopologicalSort_Util(int v, bool* visited, Stack_LinkedList<int>& s) {
        visited[v] = true;
        auto current = adj[v].head;
        while (current != nullptr) {
            int neighbor = current->value.dest;
            if (!visited[neighbor]) {
                Q7_TopologicalSort_Util(neighbor, visited, s);
            }
            current = current->next;
        }
        s.push(v);
    }

    bool Q8_isCyclic_Undirected_Util(int v, bool* visited, int parent) {
        visited[v] = true;
        auto current = adj[v].head;
        while (current != nullptr) {
            int u = current->value.dest;
            if (!visited[u]) {
                if (Q8_isCyclic_Undirected_Util(u, visited, v)) {
                    return true;
                }
            } else if (u != parent) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool Q8_isCyclic_Directed_Util(int v, bool* visited, bool* recStack) {
        if (visited[v] == false) {
            visited[v] = true;
            recStack[v] = true;

            auto current = adj[v].head;
            while (current != nullptr) {
                int neighbor = current->value.dest;
                if (!visited[neighbor] && Q8_isCyclic_Directed_Util(neighbor, visited, recStack)) {
                    return true;
                } else if (recStack[neighbor]) {
                    return true;
                }
                current = current->next;
            }
        }
        recStack[v] = false;
        return false;
    }

    Graph getTranspose() {
        Graph gT(V, true);
        for (int u = 0; u < V; ++u) {
            auto current = adj[u].head;
            while (current != nullptr) {
                gT.addEdge(current->value.dest, u, current->value.weight);
                current = current->next;
            }
        }
        return gT;
    }

    void Q9_fillOrder(int v, bool* visited, Stack_LinkedList<int>& s) {
        visited[v] = true;
        auto current = adj[v].head;
        while (current != nullptr) {
            int neighbor = current->value.dest;
            if (!visited[neighbor]) {
                Q9_fillOrder(neighbor, visited, s);
            }
            current = current->next;
        }
        s.push(v);
    }

    void Q9_DFS_Util(int v, bool* visited) {
        visited[v] = true;
        std::cout << v << " ";
        auto current = adj[v].head;
        while (current != nullptr) {
            int neighbor = current->value.dest;
            if (!visited[neighbor]) {
                Q9_DFS_Util(neighbor, visited);
            }
            current = current->next;
        }
    }

public:
    Graph(int vertices, bool directed = false) {
        V = vertices;
        isDirected = directed;
        adj = new LinkedList<AdjPair>[V];
    }

    ~Graph() {
        delete[] adj;
    }

    void addEdge(int u, int v, int w = 1) {
        if (u < 0 || u >= V || v < 0 || v >= V) {
            return;
        }
        adj[u].insert_end(AdjPair(v, w));
        if (!isDirected) {
            adj[v].insert_end(AdjPair(u, w));
        }
    }

    void displayList() {
        std::cout << "Adjacency List:" << std::endl;
        for (int i = 0; i < V; ++i) {
            std::cout << i << ": ";
            auto current = adj[i].head;
            while (current != nullptr) {
                std::cout << "(" << current->value.dest << ", w:" << current->value.weight << ") ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }

    void BFS(int startVertex) {
        if (V == 0) return;
        bool* visited = new bool[V];
        for (int i = 0; i < V; ++i) {
            visited[i] = false;
        }
        Queue_LinkedList<int> q;
        visited[startVertex] = true;
        q.enqueue(startVertex);
        std::cout << "BFS Traversal (starting from " << startVertex << "): ";
        while (!q.isEmpty()) {
            int v = q.dequeue();
            std::cout << v << " ";
            auto current = adj[v].head;
            while (current != nullptr) {
                int neighbor = current->value.dest;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.enqueue(neighbor);
                }
                current = current->next;
            }
        }
        std::cout << std::endl;
        delete[] visited;
    }

    void DFS_recursive(int startVertex) {
        if (V == 0) return;
        bool* visited = new bool[V];
        for (int i = 0; i < V; ++i) {
            visited[i] = false;
        }
        std::cout << "DFS Traversal (Recursive, starting from " << startVertex << "): ";
        DFS_recursive_helper(startVertex, visited);
        std::cout << std::endl;
        delete[] visited;
    }

    void DFS_iterative(int startVertex) {
        if (V == 0) return;
        bool* visited = new bool[V];
        for (int i = 0; i < V; ++i) {
            visited[i] = false;
        }
        Stack_LinkedList<int> s;
        s.push(startVertex);
        std::cout << "DFS Traversal (Iterative, starting from " << startVertex << "): ";
        while (!s.isEmpty()) {
            int v = s.pop();
            if (!visited[v]) {
                visited[v] = true;
                std::cout << v << " ";
            }
            auto current = adj[v].head;
            while (current != nullptr) {
                int neighbor = current->value.dest;
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
                current = current->next;
            }
        }
        std::cout << std::endl;
        delete[] visited;
    }

    bool isBipartite() {
        if (V == 0) return true;
        int* colors = new int[V];
        for (int i = 0; i < V; ++i) {
            colors[i] = 0;
        }
        Queue_LinkedList<int> q;
        for (int i = 0; i < V; ++i) {
            if (colors[i] == 0) {
                q.enqueue(i);
                colors[i] = 1;
                while (!q.isEmpty()) {
                    int u = q.dequeue();
                    auto current = adj[u].head;
                    while (current != nullptr) {
                        int v = current->value.dest;
                        if (colors[v] == 0) {
                            colors[v] = -colors[u];
                            q.enqueue(v);
                        } else if (colors[v] == colors[u]) {
                            delete[] colors;
                            return false;
                        }
                        current = current->next;
                    }
                }
            }
        }
        delete[] colors;
        return true;
    }

    void Dijkstra(int src) {
        int* dist = new int[V];
        for (int i = 0; i < V; ++i) {
            dist[i] = 2147483647;
        }
        Heap<HeapPair, HeapPairGreater> pq;
        dist[src] = 0;
        pq.push(HeapPair(0, src));
        while (!pq.isEmpty()) {
            HeapPair top = pq.pop();
            int d = top.value;
            int u = top.vertex;
            if (d > dist[u]) continue;
            auto current = adj[u].head;
            while (current != nullptr) {
                int v = current->value.dest;
                int weight = current->value.weight;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push(HeapPair(dist[v], v));
                }
                current = current->next;
            }
        }
        cout << "Dijkstra's Shortest Paths (from " << src << "):" << endl;
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << ": " << dist[i] << endl;
        }
        delete[] dist;
    }

    void Q6_MST_Prim(int startNode) {
        int* key = new int[V];
        bool* inMST = new bool[V];
        for (int i = 0; i < V; ++i) {
            key[i] = 2147483647;
            inMST[i] = false;
        }
        Heap<HeapPair, HeapPairGreater> pq;
        key[startNode] = 0;
        pq.push(HeapPair(0, startNode));
        long long mstWeight = 0;
        while (!pq.isEmpty()) {
            HeapPair top = pq.pop();
            int u = top.vertex;
            if (inMST[u]) continue;
            inMST[u] = true;
            mstWeight += top.value;
            auto current = adj[u].head;
            while (current != nullptr) {
                int v = current->value.dest;
                int weight = current->value.weight;
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push(HeapPair(key[v], v));
                }
                current = current->next;
            }
        }
        std::cout << "Prim's MST Total Weight: " << mstWeight << std::endl;
        delete[] key;
        delete[] inMST;
    }

    void Q7_TopologicalSort() {
        if (!isDirected) {
            std::cout << "Topological Sort is only for directed graphs." << std::endl;
            return;
        }
        Stack_LinkedList<int> s;
        bool* visited = new bool[V];
        for (int i = 0; i < V; ++i) {
            visited[i] = false;
        }
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                Q7_TopologicalSort_Util(i, visited, s);
            }
        }
        std::cout << "Topological Sort: ";
        while (!s.isEmpty()) {
            std::cout << s.pop() << " ";
        }
        std::cout << std::endl;
        delete[] visited;
    }

    bool Q8_isCyclic() {
        bool* visited = new bool[V];
        for (int i = 0; i < V; ++i) {
            visited[i] = false;
        }
        if (isDirected) {
            bool* recStack = new bool[V];
            for (int i = 0; i < V; ++i) {
                recStack[i] = false;
            }
            for (int i = 0; i < V; ++i) {
                if (Q8_isCyclic_Directed_Util(i, visited, recStack)) {
                    delete[] visited;
                    delete[] recStack;
                    return true;
                }
            }
            delete[] visited;
            delete[] recStack;
        } else {
            for (int i = 0; i < V; ++i) {
                if (!visited[i]) {
                    if (Q8_isCyclic_Undirected_Util(i, visited, -1)) {
                        delete[] visited;
                        return true;
                    }
                }
            }
            delete[] visited;
        }
        return false;
    }

    void Q9_printSCCs() {
        if (!isDirected) {
            std::cout << "SCCs are only for directed graphs." << std::endl;
            return;
        }
        Stack_LinkedList<int> s;
        bool* visited = new bool[V];
        for (int i = 0; i < V; ++i) {
            visited[i] = false;
        }
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                Q9_fillOrder(i, visited, s);
            }
        }
        Graph gT = getTranspose();
        for (int i = 0; i < V; ++i) {
            visited[i] = false;
        }
        std::cout << "Strongly Connected Components:" << std::endl;
        while (!s.isEmpty()) {
            int v = s.pop();
            if (!visited[v]) {
                gT.Q9_DFS_Util(v, visited);
                std::cout << std::endl;
            }
        }
        delete[] visited;
    }
};