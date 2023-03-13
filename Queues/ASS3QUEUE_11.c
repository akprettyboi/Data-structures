// ASSIGNMENT 3 11 PROBLEM JOB SCEDULING
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
int id;
int time;
} Job;

typedef struct {
Job queue[MAX_QUEUE_SIZE];
int front;
int rear;
} Queue;

// Function prototypes
void enqueue(Queue *q, Job j);
Job dequeue(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);

int main() {
int time_quantum, t1, t2, t3;
Queue q;
Job j1, j2, j3;

printf("Enter the time quantum: ");
scanf("%d", &time_quantum);
printf("Enter the processing times for the jobs (J1, J2, J3): ");
scanf("%d %d %d", &t1, &t2, &t3);

// Initialize the jobs
j1.id = 1;
j1.time = t1;
j2.id = 2;
j2.time = t2;
j3.id = 3;
j3.time = t3;

// Initialize the queue
q.front = 0;
q.rear = 0;

// Add the jobs to the queue
enqueue(&q, j1);
enqueue(&q, j2);
enqueue(&q, j3);

printf("Processing the jobs...\n");
while (!isEmpty(&q)) {
Job current_job = dequeue(&q);
printf("Processing job %d\n", current_job.id);
if (current_job.time > time_quantum) {
current_job.time -= time_quantum;
enqueue(&q, current_job);
} else {
printf("Completed job %d\n", current_job.id);
}
}

return 0;
}

void enqueue(Queue *q, Job j) {
if (isFull(q)) {
printf("Error: Queue is full\n");
return;
}
q->queue[q->rear] = j;
q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}

Job dequeue(Queue *q) {
if (isEmpty(q)) {
printf("Error: Queue is empty\n");
exit(1);
}
Job j = q->queue[q->front];
q->front = (q->front + 1) % MAX_QUEUE_SIZE;
return j;
}

int isEmpty(Queue *q) {
return q->front == q->rear;
}

int isFull(Queue *q) {
return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

//This program defines a Queue data structure with an array queue, and front and `rear



