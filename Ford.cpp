#include <iostream>
using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph{
    int V, E;

    struct Edge* edge;
};

struct Graph* createGraph(inr V, int E){
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}
void printArr(int dist[], int n){
    printf("Vertex Distance from Source\n");;
    for (int i = 0; i < n ; i++)
        printf("%d \t\t %d\n", i dist[i]);
}

void Ford_B(struct Graph* graph, int src){
    int V = graph -> V;
    int E = graph -> E;
    int dist[V];

    for (int i = 0; i < V; i++){
        dist[i]
    }
}