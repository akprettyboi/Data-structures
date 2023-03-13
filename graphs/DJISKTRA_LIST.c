#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 50
#define INF INT_MAX

struct ListNode {
int vertex;
int weight;
struct ListNode *next;
};

struct Graph {
int numVertices;
struct ListNode *adjLists[MAX_VERTICES];
};

struct Dist {
int distance;
int parent;
};

struct QueueNode {
int vertex;
int distance;
};

struct Queue {
struct QueueNode *nodes;
int size;
int front;
int rear;
};

// Function to create a new adjacency list node
struct ListNode *createNode(int v, int w) {
struct ListNode *newNode = malloc(sizeof(struct ListNode));
newNode->vertex = v;
newNode->weight = w;
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
void addEdge(struct Graph *graph, int src, int dest, int weight) {
// Add an edge from src to dest with given weight
struct ListNode *newNode = createNode(dest, weight);
newNode->next = graph->adjLists[src];
graph->adjLists[src] = newNode;
}

// Function to create a new distance struct
struct Dist *createDist(int distance, int parent) {
struct Dist *d = malloc(sizeof(struct Dist));
d->distance = distance;
d->parent = parent;
return d;
}

// Function to create a new queue
struct Queue *createQueue(int size) {
struct Queue *q = malloc(sizeof(struct Queue));
q->nodes = malloc(sizeof(struct QueueNode) * size);
q->size = size;
q->front = -1;
q->rear = -1;
return q;
}

// Function to determine if the queue is empty
int isQueueEmpty(struct Queue *q) {
return q->front == -1;
}

// Function to determine if the queue is full
int isQueueFull(struct Queue *q) {
return (q->rear + 1) % q->size == q->front;
}

// Function to add a vertex to the queue
void enqueue(struct Queue *q, int vertex, int distance) {
if (isQueueFull(q)) {
printf("Queue is full\n");
return;
}

q->rear = (q->rear + 1) % q->size;
q->nodes[q->rear].vertex = vertex;
q->nodes[q->rear].distance = distance;

if (q->front == -1)
q->front = q->rear;
}

// Function to remove a vertex from the queue
struct QueueNode dequeue(struct Queue *q) {
if (isQueueEmpty(q)) {
printf("Queue is empty\n");
struct QueueNode empty = {-1, -1};
return empty;
}

struct QueueNode dequeued = q->nodes[q->front];
if (q->front == q->rear)
q->front = q->rear = -1;
else
q->front = (q->front + 1) % q->size;

return dequeued;
}

// Function to implement Dijkstra's algorithm
void dijkstra(struct Graph *graph, int start) {
int n = graph->numVertices;
int i;

// Create an array to store distances
struct Dist *dist[n];
for (i = 0; i < n; i++)
dist[i] = createDist(INF, -1);

dist[start]->distance = 0;

// Create a priority queue
struct Queue *q = createQueue(n);
enqueue(q, start, 0);

while (!isQueueEmpty(q)) {
struct QueueNode qn = dequeue(q);
int u = qn.vertex;

struct ListNode *adjList = graph->adjLists[u];
while (adjList) {
int v = adjList->vertex;
int weight = adjList->weight;

if (dist[v]->distance > dist[u]->distance + weight) {
dist[v]->distance = dist[u]->distance + weight;
dist[v]->parent = u;

if (!isQueueFull(q))
enqueue(q, v, dist[v]->distance);
}

adjList = adjList->next;
}
}

// Print the shortest distances
for (i = 0; i < n; i++)
printf("Vertex %d: distance = %d, parent = %d\n", i, dist[i]->distance, dist[i]->parent);
}

int main() {
int num_vertices;
printf("Enter the number of vertices in the graph: ");
scanf("%d",&num_vertices);

struct Graph *graph = createGraph(num_vertices);

int num_edges;
printf("Enter the number of edges in the graph: ");
scanf("%d",&num_edges);

int i;
for (i = 0; i < num_edges; i++) {
int src, dest, weight;
printf("Enter the source vertex, destination vertex and weight of edge %d: ", i+1);
scanf("%d %d %d", &src, &dest, &weight);
addEdge(graph, src, dest, weight);
}

int start;
printf("Enter the starting vertex for Dijkstra's algorithm: ");
scanf("%d",&start);

dijkstra(graph, start);

return 0;
}



