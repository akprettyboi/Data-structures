/******************************************************************************
LIFT ARRANGEMENT ASS3 CODE 10

*******************************************************************************/

//Here is the complete modified program with sample output:



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // For the sleep() function

// Define a task structure to hold the task name, priority, and completion time
typedef struct {
char name[32];
int priority;
int time;
} Task;

// Define a queue structure to hold the tasks
typedef struct {
Task tasks[100];
int front;
int rear;
} Queue;

// Initialize the queue
void init_queue(Queue *q) {
q->front = 0;
q->rear = 0;
}

// Check if the queue is empty
int is_empty(Queue *q) {
return (q->front == q->rear);
}

// Add a task to the queue
void enqueue(Queue *q, Task t) {
q->tasks[q->rear] = t;
q->rear++;
}

// Remove a task from the queue
Task dequeue(Queue *q) {
Task t = q->tasks[q->front];
q->front++;
return t;
}

int main() {
// Initialize the queues
Queue download_queue;
init_queue(&download_queue);
Queue music_queue;
init_queue(&music_queue);
Queue game_queue;
init_queue(&game_queue);

// Prompt the user to input tasks
printf("Enter the tasks you want to perform (enter 'done' when finished):\n");

char name[32];
int priority;
int time;
while (1) {
printf("Task name: ");
scanf("%s", name);
if (strcmp(name, "done") == 0) {
break;
}
printf("Task priority (1-3, 1 being highest): ");
scanf("%d", &priority);

// Validate the priority input
while (priority < 1 || priority > 3) {
printf("Invalid priority. Please enter a value between 1 and 3: ");
scanf("%d", &priority);
}

printf("Task completion time (in seconds): ");
scanf("%d", &time);

// Validate the completion time input
while (time < 1) {
printf("Invalid completion time. Please enter a value greater than 0: ");
scanf("%d", &time);
}

// Add the task to the appropriate queue based on its priority
Task t = {name, priority, time};
if (priority == 1) {
enqueue(&download_queue, t);
} else if (priority == 2) {
enqueue(&music_queue, t);
} else {
enqueue(&game_queue, t);
}
}
// Process the tasks
while (!is_empty(&download_queue) || !is_empty(&music_queue) || !is_empty(&game_queue)) {


// Process the highest priority queue first
if (!is_empty(&download_queue)) {
Task t = dequeue(&download_queue);
printf("Processing %s for %d seconds\n", t.name, t.time);
sleep(t.time); // Simulate task processing
total_time += t.time;
} else if (!is_empty(&music_queue)) {
Task t = dequeue(&music_queue);
printf("Processing %s for %d seconds\n", t.name, t.time);
sleep(t.time); // Simulate task processing
total_time += t.time;
} else {
Task t = dequeue(&game_queue);
printf("Processing %s for %d seconds\n", t.name, t.time);

// Simulate task processing
sleep(t.time);
total_time += t.time;
}
}
}

printf("All tasks completed in %d seconds.\n", total_time);

return 0;
}
