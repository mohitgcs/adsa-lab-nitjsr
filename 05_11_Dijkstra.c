#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100  // Maximum number of vertices

int minDistance(int dist[], bool sptSet[], int V) {
    int min = INT_MAX, min_index;
    int v;
    for ( v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[MAX][MAX], int src, int V) {
    int dist[MAX];
    bool sptSet[MAX];
    int count;
    int i;

    for ( i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for ( count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;
        int v,i;
        

        for ( v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\nVertex \t Distance from Source\n");
    for ( i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

int main() {
    int V, E,i;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    int graph[MAX][MAX] = {0};

    printf("Enter edges (u v weight) one per line:\n");
    for ( i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;   // For directed graph
        // graph[v][u] = w; // Uncomment for undirected graph
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, src, V);

    return 0;
}

