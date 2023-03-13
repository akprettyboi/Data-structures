/******************************************************************************

      JOSEPHUS USING QUEUES ASS3 6TH

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

// Queue data structure
struct Queue {
    int data[MAX_QUEUE_SIZE]; // Array to store queue elements
    int front; // Index of front element
    int rear; // Index of rear element
};

// Function prototypes
void enqueue(struct Queue *queue, int value);
int dequeue(struct Queue *queue);
bool isEmpty(struct Queue *queue);
void printQueue(struct Queue *queue);

int main(void) {
    int n, k; // Number of people and interval

    // Read input from user
    printf("Enter the number of people: ");
    scanf("%d", &n);
    printf("Enter the interval: ");
    scanf("%d", &k);

    // Initialize queue
    struct Queue queue;
    queue.front = 0;
    queue.rear = n - 1;
    for (int i = 0; i < n; i++) {
        queue.data[i] = i + 1;
    }

    // Run the Josephus problem
    int count = 0; // Counter to track number of eliminations
    while (!isEmpty(&queue)) {
        for (int i = 0; i < k - 1; i++) {
            // Move front element to rear
            enqueue(&queue, dequeue(&queue));
        }
        // Remove front element
        int removed = dequeue(&queue);
        count++;
        printf("Elimination #%d: Removed person %d\n", count, removed);
        printf("Queue: ");
        printQueue(&queue);
        printf("\n");
    }

    // Print the result
    printf("The last surviving person is: %d\n", dequeue(&queue));

    return 0;
}

// Function to add an element to the queue
void enqueue(struct Queue *queue, int value) {
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->data[queue->rear] = value;
}

// Function to remove an element from the queue
int dequeue(struct Queue *queue) {
    int value = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    return value;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue *queue) {
    return queue->front == queue->rear;
}

// Function to print the contents of the queue
void printQueue(struct Queue *queue) {
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->data[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
    }
    printf("%d", queue->data[i]);
}
