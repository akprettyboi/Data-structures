/******************************************************************************

BFS AND DFS non RECURSIVE 

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

// Graph is represented using adjacency list
struct ListNode {
  int vertex;
  struct ListNode *next;
};

struct Graph {
  int numVertices;
  struct ListNode *adjLists[MAX_VERTICES];
};

// Function to create a new adjacency list node
struct ListNode *createNode(int v) {
  struct ListNode *newNode = malloc(sizeof(struct ListNode));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// Function to create a graph of given number of vertices
struct Graph *createGraph(int numVertices) {
  struct Graph *graph = malloc(sizeof(struct Graph));
  graph->numVertices = numVertices;

  // Initialize each adjacency list as empty by making head as NULL
  int i;
  for (i = 0; i < numVertices; i++)
    graph->adjLists[i] = NULL;

  return graph;
}

// Function to add an edge to a graph
void addEdge(struct Graph *graph, int src, int dest) {
  // Add an edge from src to dest. A new node is added to the adjacency
  // list of src. The node is added at the beginning
  struct ListNode *newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  // Since graph is undirected, add an edge from dest to src also
  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

// Function to print the adjacency list representation of graph
void printGraph(struct Graph *graph) {
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct ListNode *temp = graph->adjLists[v];
    printf("Adjacency list of vertex %d:\n", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

// Function to perform a depth-first search (DFS) on a graph
void DFS(struct Graph *graph, int vertex, int *visited) {
  visited[vertex] = 1;
  printf("%d ", vertex);

  struct ListNode *adjList = graph->adjLists[vertex];
  while (adjList) {
    int neighbor = adjList->vertex;
    if (!visited[neighbor])
      DFS(graph, neighbor, visited);
    adjList = adjList->next;
  }
}

// Function to perform a breadth
// Function to perform a breadth-first search (BFS) on a graph
void BFS(struct Graph *graph, int startVertex) {
int visited[graph->numVertices];
int i;
for (i = 0; i < graph->numVertices; i++)
visited[i] = 0;

struct ListNode *queue = NULL;
visited[startVertex] = 1;
enqueue(&queue, startVertex);

while (queue) {
int vertex = dequeue(&queue);
printf("%d ", vertex);

struct ListNode *adjList = graph->adjLists[vertex];
while (adjList) {
  int neighbor = adjList->vertex;
  if (!visited[neighbor]) {
    visited[neighbor] = 1;
    enqueue(&queue, neighbor);
  }
  adjList = adjList->next;
}
}
}

// Function to add a vertex to the queue
void enqueue(struct ListNode **queue, int vertex) {
struct ListNode *newNode = createNode(vertex);
if (!*queue) {
*queue = newNode;
return;
}
struct ListNode *temp = *queue;
while (temp->next)
temp = temp->next;
temp->next = newNode;
}

// Function to remove a vertex from the queue
int dequeue(struct ListNode **queue) {
if (!*queue)
return -1;
struct ListNode *temp = *queue;
*queue = (*queue)->next;
int vertex = temp->vertex;
free(temp);
return vertex;
}

int main() {
// Accept a graph from the user
int numVertices, numEdges;
printf("Enter the number of vertices in the graph: ");
scanf("%d", &numVertices);
printf("Enter the number of edges in the graph: ");
scanf("%d", &numEdges);

struct Graph *graph = createGraph(numVertices);

int i;
for (i = 0; i < numEdges; i++) {
printf("Enter edge %d (from and to vertices): ", i + 1);
int from, to;
scanf("%d%d", &from, &to);
addEdge(graph, from, to);
}

// Print the adjacency list representation of the graph
printf("\nAdjacency list representation of the graph:\n");
printGraph(graph);

// Perform a depth-first search (DFS) on the graph
printf("\nDFS sequence of the graph:\n");
int visited[numVertices];
for (i = 0; i < numVertices; i++)
visited[i] = 0;
DFS(graph, 0, visited);

// Perform a breadth-first search (BFS) on the graph
printf("\nBFS sequence of the graph:\n");
BFS(graph, 0);

return 0;
}





