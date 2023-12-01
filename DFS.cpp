#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
    int V; // Number of vertices
    vector<list<int> > adj; // Vector of lists for adjacency lists

public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // Method to add edge to graph
    void DFSUtil(int v, vector<bool>& visited); // Recursive utility function for DFS
    void DFS(int s); // Method to perform DFS traversal from given vertex s
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V); // Initialize
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (list<int>::iterator it = adj[v].begin(); it != adj[v].end(); ++it) {
        int adjacent = *it;
        if (!visited[adjacent]) {
            DFSUtil(adjacent, visited);
        }
    }
}

void Graph::DFS(int s) {
    vector<bool> visited(V, false); // Array of visited vertices
    DFSUtil(s, visited);
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "DFS starting from vertex 2: ";
    g.DFS(2);

    return 0;
}
