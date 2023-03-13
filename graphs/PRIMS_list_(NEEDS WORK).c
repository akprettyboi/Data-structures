/******************************************************************************

                    PRIMS V2

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Number of vertices in the graph
#define V 5

// A structure to represent a node in the adjacency list
typedef struct AdjListNode {
int destination; // Destination vertex
int weight; // Weight of the edge
struct AdjListNode* next; // Pointer to the next node
} AdjListNode;

// A structure to represent an adjacency list
typedef struct AdjList {
AdjListNode* head; // Pointer to the head node
} AdjList;

// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of the array will be V (number of vertices in the graph)
typedef struct Graph {
int numVertices; // Number of vertices
AdjList* adjacencyLists; // An array of adjacency lists
} Graph;

// A utility function to create a new adjacency list node
AdjListNode* createNode(int destination, int weight) {
AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
newNode->destination = destination;
newNode->weight = weight;
newNode->next = NULL;
return newNode;
}

// A utility function to create a graph of V vertices
Graph* createGraph(int numVertices) {
Graph* graph = (Graph*)malloc(sizeof(Graph));
graph->numVertices = numVertices;
graph->adjacencyLists = (AdjList*)malloc(numVertices * sizeof(AdjList));
for (int i = 0; i < numVertices; i++) {
graph->adjacencyLists[i].head = NULL;
}
return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int source, int destination, int weight) {
AdjListNode* newNode = createNode(destination, weight);
newNode->next = graph->adjacencyLists[source].head;
graph->adjacencyLists[source].head = newNode;
}

// A utility function to find the vertex with minimum key value, from
// the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[])
{
// Initialize min value
int min = INT_MAX, min_index;

for (int v = 0; v < V; v++)
if (mstSet[v] == false && key[v] < min)
min = key[v], min_index = v;

return min_index;
}

// A utility function to print the constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V])
{
printf("Edge\t\t Weight\n");
for (int i = 1; i < V; i++)
printf("%d - %d\t\t %d \n", parent[i], i, graph[i][parent[i]]);
}

// Function to construct and print MST for a graph represented using adjacency
// list representation
void primMST(Graph* graph) {
int parent[V]; // Array to store constructed MST
int key[V]; // Key values used to pick minimum weight edge in cut
bool mstSet[V]; // To represent set of vertices not yet included in MST

// Initialize all keys as INFINITE
for (int i = 0; i < V; i++)
key[i] = INT_MAX, mstSet[i] = false;

// Always include first 1st vertex in MST.
key[0] = 0; // Make key 0 so that this vertex is picked as first vertex
parent[0] = -1; // First node is always root of MST

// The MST will have V vertices
for (int count = 0; count < V - 1; count++) {
// Pick the minimum key vertex from the set of vertices not yet included in MST
int u = minKey(key, mstSet);

// Add the picked vertex to the MST Set
mstSet[u] = true;

// Update key value and parent index of the adjacent vertices of the picked vertex.
// Consider only those vertices which are not yet included in MST
AdjListNode* node = graph->adjacencyLists[u].head;
while (node != NULL) {
int v = node->destination;

// Update the key only if graph[u][v] is smaller than key[v]
if (mstSet[v] == false && node->weight < key[v])
key[v] = node->weight, parent[v] = u;

node = node->next;
}
}

// Print the constructed MST
printMST(parent, graph);
}

int main() {
printf("Enter the number of vertices in the graph: ");
scanf("%d", &V);

printf("Enter the values for the adjacency matrix of the graph:\n");
int graph[V][V];
for (int i = 0; i < V; i++) {
for(int j = 0; j < V; j++) {
scanf("%d", &graph[i][j]);
}
}

// Create a graph
Graph* graph = createGraph(V);

// Add edges to the graph
for (int i = 0; i < V; i++) {
for (int j = 0; j < V; j++) {
if (graph[i][j] != 0) {
addEdge(graph, i, j, graph[i][j]);
}
}
}

// Print the solution
primMST(graph);

return 0;
}