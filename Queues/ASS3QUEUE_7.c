/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

struct Queue {
  int front;
  int rear;
  int items[MAX_QUEUE_SIZE];
};

struct Queue* createQueue() {
  struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
  q->front = 0;
  q->rear = MAX_QUEUE_SIZE - 1;
  return q;
}

int isFull(struct Queue* q) {
  return (q->rear - q->front + 1) % MAX_QUEUE_SIZE == 0;
}

int isEmpty(struct Queue* q) {
  return q->front == q->rear;
}

void enqueue(struct Queue* q, int x) {
  if (isFull(q)) {
    printf("Queue is full\n");
    return;
  }
  q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
  q->items[q->rear] = x;
}

int dequeue(struct Queue* q) {
  if (isEmpty(q)) {
    printf("Queue is empty\n");
    return -1;
  }
  int x = q->items[q->front];
  q->front = (q->front + 1) % MAX_QUEUE_SIZE;
  return x;
}

int front(struct Queue* q) {
  if (isEmpty(q)) {
    printf("Queue is empty\n");
    return -1;
  }
  return q->items[q->front];
}

int main() {
  struct Queue* q = createQueue();

  while (1) {
    printf("1. Insert a new passenger\n");
    printf("2. Display the passenger at the front of the queue\n");
    printf("3. Remove the passenger at the front of the queue\n");
    printf("4. Display the number of passengers left in the queue\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
      int x;
      printf("Enter the passenger's name: ");
      scanf("%d", &x);
      enqueue(q, x);
    } else if (choice == 2) {
      int x = front(q);
      if (x != -1) {
        printf("The passenger at the front of the queue is: %d\n", x);
      }
    } else if (choice == 3) {
      int x = dequeue(q);
      if (x != -1) {
        printf("The removed passenger is: %d\n", x);
      }
    } else if (choice == 4) {
      int size = (q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE + 1;
printf("There are %d passengers left in the queue\n", size);
} else if (choice == 5) {
break;
} else {
printf("Invalid choice\n");
}
}

return 0;
}


