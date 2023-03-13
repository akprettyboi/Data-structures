#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 50

int adjMatrix[MAX_VERTICES][MAX_VERTICES];
int dist[MAX_VERTICES];
int prev[MAX_VERTICES];
int visited[MAX_VERTICES];

int numVertices;
int startVertex;
int endVertex;

// Function to initialize the adjacency matrix, distances, and previous vertices
void initGraph() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    printf("Enter the start vertex: ");
    scanf("%d", &startVertex);

    printf("Enter the end vertex: ");
    scanf("%d", &endVertex);

    for (i = 0; i < numVertices; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
        visited[i] = 0;
    }

    dist[startVertex] = 0;
}

// Function to find the vertex with the smallest distance that has not been visited
int findMinVertex() {
    int i, vertex = -1;
    int minDist = INT_MAX;
    for (i = 0; i < numVertices; i++) {
        if (visited[i] == 0 && dist[i] < minDist) {
            minDist = dist[i];
            vertex = i;
        }
    }
    return vertex;
}

// Function to print the shortest path from the start vertex to the end vertex
void printPath() {
    if (prev[endVertex] != -1) {
        printPath(prev[endVertex]);
    }
    printf("%d ", endVertex);
}

// Function to implement Dijkstra's algorithm
void dijkstra() {
    int i, j, u;
    for (i = 0; i < numVertices; i++) {
        u = findMinVertex();
        visited[u] = 1;

        for (j = 0; j < numVertices; j++) {
            if (visited[j] == 0 && adjMatrix[u][j] != 0 && dist[u] != INT_MAX && dist[u] + adjMatrix[u][j] < dist[j]) {
                dist[j] = dist[u] + adjMatrix[u][j];
                prev[j] = u;
            }
        }
    }
    printf("Shortest path from vertex %d to vertex %d: ", startVertex, endVertex);
    printPath();
}

int main() {
    initGraph();
    dijkstra();
}




