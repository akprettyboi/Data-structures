/******************************************************************************

                    The minimum spanning tree using Kruskal's algorithm ADJENCY MATRIX
                    JUST NEED TO MAKE OUTPUT LOOK BETTER

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100  // Maximum number of vertices in the graph

// A structure to represent a weighted edge in the graph
typedef struct {
  int source;  // Source vertex
  int destination;  // Destination vertex
  int weight;  // Weight of the edge
} Edge;

// A structure to represent a subset for union-find
typedef struct {
  int parent;  // Parent of the subset
  int rank;  // Rank of the subset
} Subset;

// A structure to represent the graph
typedef struct {
  int numVertices;  // Number of vertices in the graph
  int numEdges;  // Number of edges in the graph
  Edge* edges;  // Array of edges
} Graph;

// Function prototypes
Graph* createGraph(int numVertices, int numEdges);
void addEdge(Graph* graph, int source, int destination, int weight);
int find(Subset subsets[], int i);
void Union(Subset subsets[], int x, int y);
void KruskalMST(Graph* graph);

int main() {
  // Read the number of vertices and edges in the graph
  int numVertices, numEdges;
  printf("Enter the number of vertices and edges in the graph: ");
  scanf("%d %d", &numVertices, &numEdges);

  // Create a graph with the specified number of vertices and edges
  Graph* graph = createGraph(numVertices, numEdges);

  // Read the edges of the graph and add them to the graph
  printf("Enter the edges of the graph (source destination weight):\n");
  for (int i = 0; i < numEdges; i++) {
    int source, destination, weight;
    scanf("%d %d %d", &source, &destination, &weight);
    addEdge(graph, source, destination, weight);
  }

  // Find the minimum spanning tree using Kruskal's algorithm
  KruskalMST(graph);

  return 0;
}

// Function to create a graph with the specified number of vertices and edges
Graph* createGraph(int numVertices, int numEdges) {
  Graph* graph = (Graph*)malloc(sizeof(Graph));  // Allocate memory for the graph
  graph->numVertices = numVertices;
  graph->numEdges = numEdges;
  graph->edges = (Edge*)malloc(numEdges * sizeof(Edge));  // Allocate memory for the edges
  return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int source, int destination, int weight) {
  static int edgeIndex = 0;  // Keep track of the next available edge
  graph->edges[edgeIndex].source = source;
  graph->edges[edgeIndex].destination = destination;
  graph->edges[edgeIndex].weight = weight;
  edgeIndex++;
}

int find(Subset subsets[], int i) {
// If the vertex is not the parent of itself
if (subsets[i].parent != i) {
// Find the parent of the vertex recursively
subsets[i].parent = find(subsets, subsets[i].parent);
}

// Return the parent of the vertex
return subsets[i].parent;
}


// Function to perform union of two subsets
void Union(Subset subsets[], int x, int y) {
int xRoot = find(subsets, x);
int yRoot = find(subsets, y);

// Attach smaller rank tree under root of high rank tree
// (Union by Rank)
if (subsets[xRoot].rank < subsets[yRoot].rank) {
subsets[xRoot].parent = yRoot;
} else if (subsets[xRoot].rank > subsets[yRoot].rank) {
subsets[yRoot].parent = xRoot;
} else {
// If ranks are same, then make one as root and increment
// its rank by one
subsets[yRoot].parent = xRoot;
subsets[xRoot].rank++;
}
}

// Function to compare two edges based on their weights
int compareEdges(const void* a, const void* b) {
  Edge* edge1 = (Edge*)a;
  Edge* edge2 = (Edge*)b;
  return edge1->weight - edge2->weight;
}


// Function to implement Kruskal's algorithm for finding the minimum spanning tree
void KruskalMST(Graph* graph) {
  int numVertices = graph->numVertices;
  int numEdges = graph->numEdges;
  Edge result[numVertices];  // Array to store the resulting MST
  int e = 0;  // Index variable used to fill the result array
  int i = 0;  // Index variable used to sort the edges

  // Sort the edges in non-decreasing order by weight
  qsort(graph->edges, numEdges, sizeof(graph->edges[0]), 
        (int (*)(const void*, const void*))compareEdges);

  // Allocate memory for creating numVertices subsets
  Subset* subsets = (Subset*)malloc(numVertices * sizeof(Subset));

  // Create numVertices subsets with single elements
  for (int v = 0; v < numVertices; v++) {
    subsets[v].parent = v;
    subsets[v].rank = 0;
  }

  // Iterate through all sorted edges
  while (e < numVertices - 1) {
    // Get the minimum edge
    Edge nextEdge = graph->edges[i++];

    int x = find(subsets, nextEdge.source);
    int y = find(subsets, nextEdge.destination);

    // Check if adding this edge creates a cycle
    if (x != y) {
      // Add the edge to the MST
      result[e++] = nextEdge;
      Union(subsets, x, y);
    }
  }

  // Print the MST
  printf("The minimum spanning tree using Kruskal's algorithm is:\n");
  for (int i = 0; i < e; i++) {
    printf("%d - %d : %d\n", result[i].source, result[i].destination, result[i].weight);
  }
  return;
}



