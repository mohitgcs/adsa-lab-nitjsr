#include <stdio.h>
#define INF 1000000000   // A large value for "infinity"

void floydWarshall(int V, int graph[V][V]) {
    int dist[V][V];
    int i ,j,k;

    // Step 1: Initialize distance matrix same as input graph
    for ( i = 0; i < V; i++) {
        for ( j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Step 2: Update distances considering each vertex as an intermediate
    for ( k = 0; k < V; k++) {
        for ( i = 0; i < V; i++) {
            for ( j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Step 3: Print the final shortest path distance matrix
    printf("\nAll-pairs shortest path matrix:\n");
    for ( i = 0; i < V; i++) {
        for ( j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int V;
    int i , j;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int graph[V][V];

    printf("Enter adjacency matrix (use %d for INF):\n", INF);
    for ( i = 0; i < V; i++) {
        for ( j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(V, graph);

    return 0;
}

