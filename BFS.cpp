#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
    int V; //num of vertex
    vector<list<int>> adj;//vector of lists for adj lists

public:
    Graph(int V); //constructor
    void addEdge(int v, int w); //method to add edge to graph
    void BFS(int s);//m to perform bfr transversal from given vert s
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);//initialize
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::BFS(int s) {
    vector<bool> visited(V, false); //array of visited vert

    list<int> queue;
    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty()) {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (auto adjacent : adj[s]) {
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFS(2);

    return 0;
}
