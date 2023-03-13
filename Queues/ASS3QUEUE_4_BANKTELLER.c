

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Data structure to represent a customer
typedef struct customer {
  int arrivalTime;
  int serviceTime;
  int startTime;
  int endTime;
  int waitingTime;
} Customer;

// Data structure to represent a queue
typedef struct queue {
  int size;
  int capacity;
  int front;
  int rear;
  Customer *items;
} Queue;

// Function to create a queue of given capacity
Queue *createQueue(int capacity) {
  Queue *q = (Queue*) malloc(sizeof(Queue));
  q->capacity = capacity;
  q->front = 0;
  q->rear = capacity - 1;
  q->size = 0;
  q->items = (Customer*) malloc(sizeof(Customer) * q->capacity);
  return q;
}

// Function to check whether the queue is full
bool isFull(Queue *q) {
  return (q->size == q->capacity);
}

// Function to check whether the queue is empty
bool isEmpty(Queue *q) {
  return (q->size == 0);
}

// Function to add an item to the queue
void enqueue(Queue *q, Customer item) {
  if (isFull(q))
    return;

  q->rear = (q->rear + 1) % q->capacity;
  q->items[q->rear] = item;
  q->size = q->size + 1;
}

// Function to remove an item from the queue
Customer dequeue(Queue *q) {
  if (isEmpty(q))
    return (Customer){-1, -1, -1, -1, -1};

  Customer item = q->items[q->front];
  q->front = (q->front + 1) % q->capacity;
  q->size = q->size - 1;
  return item;
}

// Function to get the front item of the queue
Customer front(Queue *q) {
  if (isEmpty(q))
    return (Customer){-1, -1, -1, -1, -1};

  return q->items[q->front];
}

// Function to get the rear item of the queue
Customer rear(Queue *q) {
  if (isEmpty(q))
    return (Customer){-1, -1, -1, -1, -1};

  return q->items[q->rear];
}

// Function to simulate the teller operation of a bank
void simulateTellerOperation(int numTellers, int numMinutes) {
  // Seed the random number generator with the current time
  srand(time(NULL));

  // Create a queue to store the customers
  Queue *q = createQueue(numMinutes);

    // Array to store the teller availability status
  bool *tellerAvailable = (bool*) malloc(sizeof(bool) * numTellers);

  // Initialize all tellers to be available
  for (int i = 0; i < numTellers; i++)
    tellerAvailable[i] = true;

  // Variables to keep track of statistics
  int totalCustomers = 0;
  int totalWaitingTime = 0;

  // Run the simulation for the given number of minutes
  for (int minute = 0; minute < numMinutes; minute++) {
    // Check if there are any customers arriving at this minute
    if (rand() % 2 == 0) {
      // Create a new customer with a random service time
      Customer c = {minute, rand() % 5 + 1, -1, -1, -1};
      enqueue(q, c);
      printf("Customer arrived at minute %d with service time %d\n", c.arrivalTime, c.serviceTime);
    }

    // Assign customers to available tellers
    for (int i = 0; i < numTellers; i++) {
      if (tellerAvailable[i] && !isEmpty(q)) {
        Customer c = dequeue(q);
        c.startTime = minute;
        c.endTime = c.startTime + c.serviceTime;
        c.waitingTime = c.startTime - c.arrivalTime;
        totalCustomers++;
        totalWaitingTime += c.waitingTime;
        tellerAvailable[i] = false;
        printf("Customer served by teller %d at minute %d with waiting time %d\n", i, c.startTime, c.waitingTime);
      }
    }

    // Mark tellers as available if they have finished serving a customer
    for (int i = 0; i < numTellers; i++) {
      if (!tellerAvailable[i] && !isEmpty(q) && front(q).endTime == minute) {
        dequeue(q);
        tellerAvailable[i] = true;
      }
    }
  }

  // Calculate and print the statistics
  double averageWaitingTime = (double) totalWaitingTime / totalCustomers;
  printf("Total number of customers: %d\n", totalCustomers);
  printf("Total waiting time: %d\n", totalWaitingTime);
  printf("Average waiting time: %.2f\n", averageWaitingTime);

  // Free the memory allocated for the queue and teller availability array
  free(q->items);
  free(q);
  free(tellerAvailable);
}

int main() {
  int numTellers, numMinutes;
  printf("Enter the number of tellers: ");
  scanf("%d", &numTellers);
  printf("Enter the number of minutes to simulate: ");
  scanf("%d", &numMinutes);
  simulateTellerOperation(numTellers, numMinutes);
  return 0;
}

