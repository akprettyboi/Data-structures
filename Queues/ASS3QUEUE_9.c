/******************************************************************************
PROGRAM AIRLINES NOT USER DEFINED

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Total simulation time in minutes
#define MINUTES 120
// Time interval for making a runway request in minutes
#define INTERVAL 5
// Time taken for a takeoff to complete in minutes
#define TAKEOFF_TIME 15
// Time taken for a landing to complete in minutes
#define LANDING_TIME 15

// Struct to store stats for the simulation
typedef struct {
  int takeoff_count;
  int landing_count;
  double avg_wait_time_takeoff;
  double avg_wait_time_landing;
  int takeoff_queue_size;
  int landing_queue_size;
} Stats;

// Struct to store a plane's arrival and departure time
typedef struct {
  int arrival_time;
  int departure_time;
} Plane;

// Struct to store a queue of planes
typedef struct {
  int size;
  int capacity;
  Plane* planes;
} Queue;

// Create a queue with the given capacity
Queue* create_queue(int capacity) {
  Queue* queue = malloc(sizeof(Queue));
  queue->capacity = capacity;
  queue->size = 0;
  queue->planes = malloc(queue->capacity * sizeof(Plane));
  return queue;
}

// Add a plane to the queue
void enqueue(Queue* queue, Plane plane) {
  if (queue->size == queue->capacity) {
    // Resize the queue
    queue->capacity *= 2;
    queue->planes = realloc(queue->planes, queue->capacity * sizeof(Plane));
  }
  queue->planes[queue->size++] = plane;
}

// Remove and return the first plane in the queue
Plane dequeue(Queue* queue) {
  Plane plane = queue->planes[0];
  for (int i = 1; i < queue->size; i++) {
    queue->planes[i - 1] = queue->planes[i];
  }
  queue->size--;
  return plane;
}

// Return 1 if the queue is empty, 0 otherwise
int is_empty(Queue* queue) {
  return queue->size == 0;
}

// Simulate the operation of an airport with two runways
// interval: time interval for making a runway request in minutes
Stats simulate_airport(int interval) {
  Stats stats = {0};
  Queue* takeoff_queue = create_queue(1);
  Queue* landing_queue = create_queue(1);

  int current_time = 0;
  while (current_time < MINUTES) {
    // Make a runway request
    int is_landing = rand() % 2;
    if (is_landing) {
      Plane plane = {current_time, current_time + LANDING_TIME};
      enqueue(landing_queue, plane);
    } else {
      Plane plane = {current_time, current_time + TAKEOFF_TIME};
      enqueue(takeoff_queue, plane);
    }

        // Check if there are planes ready to depart
    if (!is_empty(landing_queue)) {
      Plane plane = dequeue(landing_queue);
      if (plane.departure_time <= current_time) {
        stats.landing_count++;
      } else {
        enqueue(landing_queue, plane);
      }
    }
    if (!is_empty(takeoff_queue)) {
      Plane plane = dequeue(takeoff_queue);
      if (plane.departure_time <= current_time) {
        stats.takeoff_count++;
      } else {
        enqueue(takeoff_queue, plane);
      }
    }

    // Update wait times and queue sizes
    stats.takeoff_queue_size = takeoff_queue->size;
    stats.landing_queue_size = landing_queue->size;
    for (int i = 0; i < takeoff_queue->size; i++) {
      stats.avg_wait_time_takeoff += takeoff_queue->planes[i].departure_time - takeoff_queue->planes[i].arrival_time;
    }
    for (int i = 0; i < landing_queue->size; i++) {
      stats.avg_wait_time_landing += landing_queue->planes[i].departure_time - landing_queue->planes[i].arrival_time;
    }
    if (stats.takeoff_count > 0) {
      stats.avg_wait_time_takeoff /= stats.takeoff_count;
    }
    if (stats.landing_count > 0) {
      stats.avg_wait_time_landing /= stats.landing_count;
    }

    current_time += interval;
  }

  // Clean up
  free(takeoff_queue->planes);
  free(takeoff_queue);
  free(landing_queue->planes);
  free(landing_queue);

  return stats;
}

int main() {
  srand(time(NULL));
  Stats stats = simulate_airport(INTERVAL);
  printf("Number of takeoffs completed: %d\n", stats.takeoff_count);
  printf("Number of landings completed: %d\n", stats.landing_count);
  printf("Average wait time for takeoff requests: %.2f\n", stats.avg_wait_time_takeoff);
  printf("Average wait time for landing requests: %.2f\n", stats.avg_wait_time_landing);
    printf("Size of takeoff queue: %d\n", stats.takeoff_queue_size);
  printf("Size of landing queue: %d\n", stats.landing_queue_size);
  return 0;
}

