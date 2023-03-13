/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h> // needed for srand() and rand()
#include <unistd.h> // needed for sleep()

#define MAX_QUEUE_SIZE 100 // maximum size of the waiting lines

// passenger structure to store the time taken to serve a passenger and their type (regular or frequent flyer)
typedef struct {
int time_taken; // time taken to serve a passenger
int type; // 0 for regular customer, 1 for frequent flyer
} passenger;

// queue structure to store the waiting passengers
typedef struct {
passenger data[MAX_QUEUE_SIZE]; // array to store the waiting passengers
int front, rear; // indices of the front and rear of the queue
} queue;

// Initializes the queue by setting the front and rear indices
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
/*void enqueue(queue *q, passenger p) {
if (is_full(q)) {
printf("Error: queue is full\n");
return;
}
q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // update the rear index
q->data[q->rear] = p; // add the passenger to the queue
}
*/

// Adds a passenger to the rear of the queue
void enqueue(queue *q, passenger p) {
  if (is_full(q)) {
    printf("Error: queue is full\n");
    return;
  }
  q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // update the rear index
  q->data[q->rear] = p; // add the passenger to the queue
}

// Removes a passenger from the front of the queue
passenger dequeue(queue *q) {
if (is_empty(q)) {
printf("Error: queue is empty\n");
exit(1); // terminate the program with an error
}
q->front = (q->front + 1) % MAX_QUEUE_SIZE; // update the front index
return q->data[q->front]; // return the passenger from the queue
}

// Simulates the process of serving a passenger, taking a random amount of time
void serve_passenger(passenger *p) {
p->time_taken = rand() % 5 + 1; // random time between 1 and 5
printf("Serving passenger for %d seconds\n", p->time_taken);
sleep(p->time_taken); // simulate serving the passenger
}

/*int main() {
srand(time(0)); // seed the random number generator

queue regular_customers, frequent_flyers; // create two queues for regular and frequent flyers
init_queue(&regular_customers); // initialize the queues
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
*/

int main() {
  srand(time(0)); // seed the random number generator

  queue regular_customers, frequent_flyers; // create two queues for regular and frequent flyers
  init_queue(&regular_customers); // initialize the queues
  init_queue(&frequent_flyers);

  /*int strategy;
  printf("Enter the strategy to use (0 for regular customers first, 1 for frequent flyers first): ");
  scanf("%d", &strategy);

  // Read the input from the user one passenger at a time
  int num_regular_customers = 0, num_frequent_flyers = 0;
  while (1) {
    printf("Enter 0 to add a regular customer, 1 to add a frequent flyer, or -1 to exit: ");
    int passenger_type;
    scanf("%d", &passenger_type);

    if (passenger_type == -1) {
      break; // exit the loop
    }

    passenger p;
    p.type = passenger_type;

    if (passenger_type == 0) {
      enqueue(&regular_customers, p);
      num_regular_customers++;
    } else if (passenger_type == 1) {
      enqueue(&frequent_flyers, p);
      num_frequent_flyers++;
} else {
printf("Invalid passenger type\n");
}
}
*/

 int num_regular_customers = 0;
 int num_frequent_flyers = 0;

  // Read input from the user
  int strategy;
  printf("Enter the strategy to use (0 for regular customers first, 1 for frequent flyers first): ");
  scanf("%d", &strategy);

  char input[10];
  printf("Enter passengers (R for regular, F for frequent flyer): ");
  scanf("%s", input);
  while (input[0] != 'Q') {
    passenger p;
    if (input[0] == 'R') {
      p.type = 0;
      enqueue(&regular_customers, p);
      num_regular_customers++; // increment num_regular_customers
    } else if (input[0] == 'F') {
      p.type = 1;
      enqueue(&frequent_flyers, p);
      num_frequent_flyers++; // increment num_frequent_flyers
    }
    scanf("%s", input);
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
while (!is_empty(&frequent_flyers) || !is_empty(&regular_customers)) {
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
printf("Invalid strategy\n");
}

return 0;
}


