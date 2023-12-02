#include <iostream>
using namespace std;

#define INF 99999

void printSolution(int dist[][100], int V);

void floydWarshall(int dist[][100], int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF)) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    // dist[i][j] == dist[v]
    // dist[i][k] == dist[u]
    // dist[k][j] == weight
    printSolution(dist, V);
}

void printSolution(int dist[][100], int V) {
    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V;
    cin >> V;
    int graph[100][100]; // Assuming the maximum size of the graph is 100x100

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    floydWarshall(graph, V);
    return 0;
}
