/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 10  // maximum size of the waiting lines

typedef struct {
  int time_taken;  // time taken to serve a passenger
  int type;  // 0 for regular customer, 1 for frequent flyer
} passenger;

typedef struct {
  passenger data[MAX_QUEUE_SIZE];  // array to store the waiting passengers
  int front, rear;  // indices of the front and rear of the queue
} queue;

// Initializes the queue
void init_queue(queue *q) {
  q->front = 0;
  q->rear = MAX_QUEUE_SIZE - 1;
}

// Returns 1 if the queue is empty, 0 otherwise
int is_empty(queue *q) {
  return (q->front > q->rear);
}

// Returns 1 if the queue is full, 0 otherwise
int is_full(queue *q) {
  return ((q->rear - q->front + 1) == MAX_QUEUE_SIZE);
}

// Adds a passenger to the rear of the queue
void enqueue(queue *q, passenger p) {
  if (is_full(q)) {
    printf("Error: queue is full\n");
    return;
  }
  q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
  q->data[q->rear] = p;
}

// Removes a passenger from the front of the queue
passenger dequeue(queue *q) {
  if (is_empty(q)) {
    printf("Error: queue is empty\n");
    exit(1);
  }
  q->front = (q->front + 1) % MAX_QUEUE_SIZE;
  return q->data[q->front];
}

// Simulates the process of serving a passenger, taking a random amount of time
void serve_passenger(passenger *p) {
  p->time_taken = rand() % 5 + 1;  // random time between 1 and 5
  printf("Serving passenger for %d seconds\n", p->time_taken);
  sleep(p->time_taken);  // simulate serving the passenger
}

int main() {
  srand(time(0));  // seed the random number generator

  queue regular_customers, frequent_flyers;
  init_queue(&regular_customers);
  init_queue(&frequent_flyers);

  int strategy;
  printf("Enter the strategy to use (0 for regular customers first, 1 for frequent flyers first): ");
  scanf("%d", &strategy);

  // Read the input from the user
  int num_regular_customers, num_frequent_flyers;
  printf("Enter the number of regular customers: ");
  scanf("%d", &num_regular_customers);
  printf("Enter the number of frequent flyers: ");
  scanf("%d", &num_frequent_flyers);

  // Add the regular customers to the queue
for (int i = 0; i < num_regular_customers; i++) {
passenger p;
p.type = 0;
enqueue(&regular_customers, p);
}
// Add the frequent flyers to the queue
for (int i = 0; i < num_frequent_flyers; i++) {
passenger p;
p.type = 1;
enqueue(&frequent_flyers, p);
}

// Serve the passengers based on the chosen strategy
if (strategy == 0) {
// Serve regular customers first
while (!is_empty(&regular_customers) || !is_empty(&frequent_flyers)) {
if (!is_empty(&regular_customers)) {
passenger p = dequeue(&regular_customers);
serve_passenger(&p);
}
if (!is_empty(&frequent_flyers)) {
passenger p = dequeue(&frequent_flyers);
serve_passenger(&p);
}
}
} else if (strategy == 1) {
// Serve frequent flyers first
while (!is_empty(&regular_customers) || !is_empty(&frequent_flyers)) {
if (!is_empty(&frequent_flyers)) {
passenger p = dequeue(&frequent_flyers);
serve_passenger(&p);
}
if (!is_empty(&regular_customers)) {
passenger p = dequeue(&regular_customers);
serve_passenger(&p);
}
}
} else {
printf("Error: Invalid strategy\n");
return 1;
}

return 0;
}

