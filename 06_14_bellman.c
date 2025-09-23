#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// structure to represent a graph
struct Graph {
    int V, E;
    struct Edge* edge;
};

// create graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*) malloc(E * sizeof(struct Edge));
    return graph;
}

// Bellman-Ford algorithm
void BellmanFord(struct Graph* graph, int src) {
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    int i;
    int j;

    // Step 1: Initialize distances
    for ( i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
        

    // Step 2: Relax edges V-1 times
    for (i = 1; i <= V - 1; i++) {
        for ( j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int w = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    for (j = 0; j < E; j++) {
        int u = graph->edge[j].src;
        int v = graph->edge[j].dest;
        int w = graph->edge[j].weight;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("Graph contains negative weight cycle!\n");
            return;
        }
    }

    // Print results
    printf("\nVertex   Distance from Source %d\n", src);
    for (i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            printf("%d \t\t INF\n", i);
        else
            printf("%d \t\t %d\n", i, dist[i]);
    }
}

// Driver code
int main() {
    int V, E, i,src;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Graph* graph = createGraph(V, E);

    printf("Enter edges (src dest weight):\n");
    for ( i = 0; i < E; i++) {
        scanf("%d %d %d", &graph->edge[i].src, &graph->edge[i].dest, &graph->edge[i].weight);
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    BellmanFord(graph, src);

    return 0;
}

