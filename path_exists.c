#include <stdio.h>
#include <stdbool.h>

#define V 5  // Number of vertices in the graph

// Function to perform DFS and print the path if found
bool DFS(int graph[V][V], int src, int dest, bool visited[], int path[], int pathIndex) {
    // Mark the current node as visited and add it to the path
    visited[src] = true;
    path[pathIndex] = src;  // Add current node to the path
    pathIndex++;

    // If the source is the destination, print the path and return true
    if (src == dest) {
        printf("Path found: ");
        for (int i = 0; i < pathIndex; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
        return true;
    }

    // Explore adjacent vertices
    for (int i = 0; i < V; i++) {
        // If there is an edge and the node is not visited
        if (graph[src][i] == 1 && !visited[i]) {
            // Recursively perform DFS
            if (DFS(graph, i, dest, visited, path, pathIndex)) {
                return true;
            }
        }
    }

    // Backtrack: Unmark the current node as visited
    visited[src] = false;
    return false;
}

// Function to check if a path exists between two nodes and print it
bool isPath(int graph[V][V], int src, int dest) {
    // Array to keep track of visited nodes
    bool visited[V] = {false};

    // Array to store the path
    int path[V];
    int pathIndex = 0;

    // Call DFS
    return DFS(graph, src, dest, visited, path, pathIndex);
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = {
        {0, 1, 1, 0, 0},  // Node 0 is connected to Node 1 and Node 2
        {1, 0, 1, 1, 0},  // Node 1 is connected to Node 0, Node 2, and Node 3
        {1, 1, 0, 0, 1},  // Node 2 is connected to Node 0, Node 1, and Node 4
        {0, 1, 0, 0, 1},  // Node 3 is connected to Node 1 and Node 4
        {0, 0, 1, 1, 0}   // Node 4 is connected to Node 2 and Node 3
    };

    // Define source and destination
    int src = 0, dest = 3;

    // Check if a path exists and print it
    if (isPath(graph, src, dest)) {
        printf("There is a path between node %d and node %d.\n", src, dest);
    } else {
        printf("There is no path between node %d and node %d.\n", src, dest);
    }

    return 0;
}

