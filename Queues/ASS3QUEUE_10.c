/******************************************************************************
LIFT ARRANGEMENT ASS3 CODE 10

*******************************************************************************/

/*
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int priority;
    char *name;
} element;

element queue[MAX_SIZE];
int front = 0;
int rear = -1;

void enqueue(element item, int priority) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    rear++;
    queue[rear] = item;
    queue[rear].priority = priority;
}

element dequeue() {
    element item;
    if (front > rear) {
        printf("Queue is empty!\n");
        item.name = "";
        item.priority = -1;
        return item;
    }
    item = queue[front];
    front++;
    return item;
}

int main() {
    element item1, item2, item3, item4, item5;
    item1.name = "Students";
    item1.priority = 2;
    item2.name = "Staff";
    item2.priority = 3;
    item3.name = "HODs/Deans/Director";
    item3.priority = 4;
    item4.name = "Guests";
    item4.priority = 1;
    item5.name = "Faculty";
    item5.priority = 5;

    enqueue(item1, item1.priority);
    enqueue(item2, item2.priority);
    enqueue(item3, item3.priority);
    enqueue(item4, item4.priority);
    enqueue(item5, item5.priority);

    element item = dequeue();
    printf("%s with priority %d was dequeued\n", item.name, item.priority);
    item = dequeue();
    printf("%s with priority %d was dequeued\n", item.name, item.priority);
    item = dequeue();
    printf("%s with priority %d was dequeued\n", item.name, item.priority);
    item = dequeue();
    printf("%s with priority %d was dequeued\n", item.name, item.priority);
    item = dequeue();
    printf("%s with priority %d was dequeued\n", item.name, item.priority);
    item = dequeue();
    printf("%s with priority %d was dequeued\n", item.name, item.priority);

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Struct to represent an element in the queue
typedef struct {
    int priority; // Priority of the element
    char name[50]; // Name of the element
} element;

// Queue implemented as an array
element queue[MAX_SIZE];
int front = 0; // Index of the first element in the queue
int rear = -1; // Index of the last element in the queue

// Function to enqueue an element into the queue
/*void enqueue(element item, int priority) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    // Increment the rear index and add the element to the queue
    rear++;
    queue[rear] = item;
    queue[rear].priority = priority;
}
*/

void enqueue(element item, int priority) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    // Increment the rear index
    rear++;
    // Shift elements with lower priority to the right to make room for the new element
    int i;
    for (i = rear; i > front && queue[i - 1].priority > priority; i--) {
        queue[i] = queue[i - 1];
    }
    // Insert the new element at the correct position
    queue[i] = item;
    queue[i].priority = priority;
}

// Function to dequeue an element from the queue
element dequeue() {
    element item;
    // If the queue is empty, return an element with empty name and priority -1
    if (front > rear) {
        printf("Queue is empty!\n");
        item.name[0] = '\0';
        item.priority = -1;
        return item;
    }
    // Get the first element in the queue and increment the front index
    item = queue[front];
    front++;
    return item;
}

int main() {
    element item;
    int priority;
    char name[50];

    // Keep looping until the user enters an empty name
    while (1) {
        printf("Enter name (or hit Enter to stop): ");
        fgets(name, 50, stdin);
        // If the user entered an empty name, break out of the loop
        if (name[0] == '\n') {
            break;
        }
        // Remove the newline character from the name
        name[strlen(name) - 1] = '\0';

        printf("Enter priority: ");
        scanf("%d", &priority);

        // Clear the input buffer
        while (getchar() != '\n');

        // Create an element with the user-entered name and priority
        strcpy(item.name, name);
        item.priority = priority;

        // Enqueue the element
        enqueue(item, priority);
    }

    // Dequeue and print elements until the queue is empty
    while (1) {
        element item = dequeue();
        // If the element has empty name and priority -1, the queue is empty
        if (item.name[0] == '\0' && item.priority == -1) {
            break;
        }
        printf("%s with priority %d was dequeued\n", item.name, item.priority);
    }

    return 0;
}
