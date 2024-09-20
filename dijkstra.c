#include <stdio.h>
#include <limits.h>

#define V 5  // Number of vertices in the graph

/* Function to find the vertex with the minimum distance value, 
from the set of vertices not yet processed*/
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

/* Function to print the constructed distance array and 
the path of visited nodes */

void printSolution(int dist[], int prev[], int src) {
    printf("Vertex \t Distance from Source \t Path\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d \t\t\t", i, dist[i]);

        // Print the path from the source to the current vertex
        int j = i;
        while (prev[j] != -1) {
            printf("%d <- ", j);
            j = prev[j];
        }
        printf("%d\n", src);
    }
}

/* Dijkstra's algorithm implementation using an adjacency matrix 
representation of the graph */

void dijkstra(int graph[V][V], int src) {
    /* Output array. dist[i] will hold the shortest distance from src to i*/
    int dist[V];
    /* sptSet[i] will be 1 if vertex i is included in shortest path tree */   
    int sptSet[V];
    /* prev[i] will store the previous node for constructing the path*/
    int prev[V];     

    // Initialize all distances as INFINITE and sptSet[] as 0 (false)
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
        prev[i] = -1;  // Initialize previous node array
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++) {
            /* Update dist[v] only if it's not in sptSet, there is an edge from u to v,
            and the total weight of path from src to v through u is smaller 
            than current value of dist[v]*/
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;  // Store the previous node for the path
            }
        }

        // Print the currently visited node
        printf("Visited node: %d\n", u);
    }

    // Print the constructed distance array and paths
    printSolution(dist, prev, src);
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = { { 0, 10, 0, 0, 5 },
                        { 0, 0, 1, 0, 2 },
                        { 0, 0, 0, 4, 0 },
                        { 7, 0, 6, 0, 0 },
                        { 0, 3, 9, 2, 0 } };

    // Run Dijkstra's algorithm from vertex 0 (source)
    dijkstra(graph, 0);

    return 0;
}

