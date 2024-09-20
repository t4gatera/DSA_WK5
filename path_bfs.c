#include <stdio.h>
#include <stdbool.h>

#define V 5  // Number of vertices in the graph

// Function to perform BFS and print the path if found
bool BFS(int graph[V][V], int src, int dest) {
    // Queue for BFS (stores nodes to visit)
    int queue[V];
    int front = 0, rear = 0;

    // Array to keep track of visited nodes
    bool visited[V] = {false};

    // Parent array to reconstruct the path
    int parent[V];

    // Initialize the parent array
    for (int i = 0; i < V; i++) {
        parent[i] = -1;  // Initialize with -1 (no parent)
    }

    // Mark the source node as visited and enqueue it
    visited[src] = true;
    queue[rear++] = src;

    // Perform BFS
    while (front != rear) {
        // Dequeue a node from the queue
        int current = queue[front++];
        
        // If we reach the destination node, reconstruct the path
        if (current == dest) {
            printf("Path found: ");
            int path[V];  // To store the path
            int pathIndex = 0;

            // Reconstruct the path by backtracking from destination to source
            for (int v = dest; v != -1; v = parent[v]) {
                path[pathIndex++] = v;
            }

            // Print the path in reverse order (from source to destination)
            for (int i = pathIndex - 1; i >= 0; i--) {
                printf("%d ", path[i]); 
            }
            printf("\n");

            return true;
        }

        // Explore adjacent nodes
        for (int i = 0; i < V; i++) {
            // If there is an edge and the node is not visited
            if (graph[current][i] == 1 && !visited[i]) {
                // Mark it as visited and enqueue it
                visited[i] = true;
                queue[rear++] = i;

                // Set the parent of the current node
                parent[i] = current;
            }
        }
    }

    // If we exit the loop without finding the destination
    return false;
}

// Function to check if a path exists between two nodes and print it
bool isPathBFS(int graph[V][V], int src, int dest) {
    // Call BFS to find the path and print it
    return BFS(graph, src, dest);
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
    int src = 0, dest = 4;

    // Check if a path exists and print it
    if (isPathBFS(graph, src, dest)) {
        printf("There is a path between node %d and node %d.\n", src, dest);
    } else {
        printf("There is no path between node %d and node %d.\n", src, dest);
    }

    return 0;
}

