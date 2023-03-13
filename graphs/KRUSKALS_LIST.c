/******************************************************************************

                    The minimum spanning tree using Kruskal's algorithm ADJENCY LIST
                    JUST NEED TO MAKE OUTPUT LOOK BETTER

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100  // Maximum number of vertices in the graph

// A structure to represent a node in the linked list
typedef struct ListNode {
  int destination;  // Destination vertex
  int weight;  // Weight of the edge
  struct ListNode* next;  // Pointer to the next node
} ListNode;

// A structure to represent the linked list
typedef struct LinkedList {
  ListNode* head;  // Pointer to the head node
} LinkedList;

// A structure to represent a subset for union-find
typedef struct {
  int parent;  // Parent of the subset
  int rank;  // Rank of the subset
} Subset;

// A structure to represent the graph
typedef struct {
  int numVertices;  // Number of vertices in the graph
  int numEdges;  // Number of edges in the graph
  LinkedList* adjacencyList;  // Array of linked lists
} Graph;

typedef struct {
  int source;  // Source vertex
  int destination;  // Destination vertex
  int weight;  // Weight of the edge
} Edge;


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
  graph->adjacencyList = (LinkedList*)malloc(numVertices * sizeof(LinkedList));  // Allocate memory for the linked lists
  for (int i = 0; i < numVertices; i++) {
    graph->adjacencyList[i].head = NULL;  // Initialize the head of the linked list to NULL
  }
  return graph;
}
// Function to add an edge to the graph
void addEdge(Graph* graph, int source, int destination, int weight) {
  ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));  // Allocate memory for the new node
  newNode->destination = destination;
  newNode->weight = weight;
  newNode->next = graph->adjacencyList[source].head;  // Add the new node to the front of the linked list
  graph->adjacencyList[source].head = newNode;
}

// Function to find the subset to which a vertex belongs
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
  Edge* edge1 = a;
  Edge* edge2 = b;
  return edge1->weight - edge2->weight;
}

// Function to find the minimum spanning tree using Kruskal's algorithm
void KruskalMST(Graph* graph) {
  int numVertices = graph->numVertices;
  Edge result[numVertices];  // Array to store the resultant MST
  int e = 0;  // Index variable to store the resultant edges
  int i = 0;  // Index variable to store the current edge

  // Step 1: Sort the edges in ascending order based on their weights
  qsort(graph->adjacencyList, graph->numEdges, sizeof(graph->adjacencyList[0]), compareEdges);

  // Step 2: Create subsets with single element for each vertex
  Subset* subsets = (Subset*)malloc(numVertices * sizeof(Subset));
  for (int v = 0; v < numVertices; v++) {
    subsets[v].parent = v;
    subsets[v].rank = 0;
  }

  // Step 3: Iterate through all edges in the sorted array
   while (e < numVertices - 1) {
    // Step 3a: Select the smallest edge
  ListNode* current = graph->adjacencyList[i].head;
  Edge nextEdge = {i, current->destination, current->weight};


    // Step 3b: Check if adding the edge would create a cycle
    int x = find(subsets, nextEdge.source);
    int y = find(subsets, nextEdge.destination);

    // Step 3c: If the selected edge does not create a cycle, add it to the MST
    if (x != y) {
      result[e++] = nextEdge;
      Union(subsets, x, y);
    }
  }

  // Step 4: Print the minimum spanning tree
  printf("The minimum spanning tree using Kruskal's algorithm is:\n");
  for (int i = 0; i < e; i++) {
    printf("%d - %d\n", result[i].source, result[i].destination);
  }
}





