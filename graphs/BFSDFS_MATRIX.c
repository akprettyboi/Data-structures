#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

// Graph is represented using adjacency matrix
int adjMatrix[MAX_VERTICES][MAX_VERTICES];

struct Graph {
  int numVertices;
};

// Function to create a graph of given number of vertices
struct Graph *createGraph(int numVertices) {
  struct Graph *graph = malloc(sizeof(struct Graph));
  graph->numVertices = numVertices;

  // Initialize adjacency matrix as all zeroes
  int i, j;
  for (i = 0; i < numVertices; i++) {
    for (j = 0; j < numVertices; j++) {
      adjMatrix[i][j] = 0;
    }
  }

  return graph;
}

// Function to add an edge to a graph
void addEdge(struct Graph *graph, int src, int dest) {
  // Add an edge from src to dest
  adjMatrix[src][dest] = 1;

  // Since graph is undirected, add an edge from dest to src also
  adjMatrix[dest][src] = 1;
}

// Function to print the adjacency matrix representation of graph
void printGraph(struct Graph *graph) {
  int i, j;
  printf("Adjacency matrix:\n");
  for (i = 0; i < graph->numVertices; i++) {
    for (j = 0; j < graph->numVertices; j++) {
printf("%d ", adjMatrix[i][j]);
}
printf("\n");
}
}

// Function to perform a depth-first search (DFS) on a graph (non-recursive)
void DFS(struct Graph *graph, int startVertex) {
int visited[graph->numVertices];
int i;
for (i = 0; i < graph->numVertices; i++)
visited[i] = 0;

struct Stack {
int data;
struct Stack* next;
}*stack = NULL;
push(&stack, startVertex);

while (stack) {
int vertex = pop(&stack);
if (!visited[vertex]) {
visited[vertex] = 1;
printf("%d ", vertex);
}
int i;
for (i = 0; i < graph->numVertices; i++) {
  if (adjMatrix[vertex][i] && !visited[i])
    push(&stack, i);
}
}
}

// Function to push a vertex to the stack
void push(struct Stack **stack, int vertex) {
struct Stack *newNode = (struct Stack)malloc(sizeof(struct Stack));
newNode->data = vertex;
newNode->next = *stack;
*stack = newNode;
}

// Function to pop a vertex from the stack
int pop(struct Stack **stack) {
if (*stack == NULL)
return -1;

struct Stack *temp = *stack;
*stack = (*stack)->next;
int data = temp->data;
free(temp);
return data;
}

// Function to perform a breadth-first search (BFS) on a graph
void BFS(struct Graph *graph, int startVertex) {
int visited[graph->numVertices];
int i;
for (i = 0; i < graph->numVertices; i++)
visited[i] = 0;

struct Queue {
int data;
struct Queue* next;
}*queue = NULL;
enqueue(&queue, startVertex);
visited[startVertex] = 1;

while (queue) {
int vertex = dequeue(&queue);
printf("%d ", vertex);
int i;
for (i = 0; i < graph->numVertices; i++) {
  if (adjMatrix[vertex][i] && !visited[i]) {
    visited[i] = 1;
    enqueue(&queue, i);
  }
}
}
}

// Function to add a vertex to the queue
void enqueue(struct Queue **queue, int vertex) {
struct Queue *newNode = (struct Queue)malloc(sizeof(struct Queue));
newNode->data = vertex;
newNode->next = *queue;
*queue = newNode;
}

// Function to remove a vertex from the queue
int dequeue(struct Queue **queue) {
if (*queue == NULL)
return -1;

struct Queue *temp = *queue;
*queue = (*queue)->next;
int vertex = temp->vertex;
free(temp);
return vertex;
}

int main() {
  int numVertices;
  printf("Enter the number of vertices: ");
  scanf("%d", &numVertices);

  struct Graph *graph = createGraph(numVertices);

  int numEdges;
  printf("Enter the number of edges: ");
  scanf("%d", &numEdges);

  int i;
  for (i = 0; i < numEdges; i++) {
    int src, dest;
    printf("Enter edge %d (src dest): ", i + 1);
    scanf("%d %d", &src, &dest);
    addEdge(graph, src, dest);
  }

  printf("Adjacency matrix representation of the graph:\n");
  printGraph(graph);

  int startVertex;
  printf("Enter the starting vertex for DFS: ");
  scanf("%d", &startVertex);
  printf("DFS traversal of the graph: ");
  DFS(graph, startVertex);

  printf("\nEnter the starting vertex for BFS: ");
  scanf("%d", &startVertex);
  printf("BFS traversal of the graph: ");
  BFS(graph, startVertex);

  return 0;
}




