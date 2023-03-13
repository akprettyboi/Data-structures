/******************************************************************************

                            MAX HEAP DESCENDING ORDER

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define LEFT(i) (2 * (i) + 1)
#define RIGHT(i) (2 * (i) + 2)
#define PARENT(i) ((i - 1) / 2)

// Function to heapify the tree at the given index
void heapify(int *heap, int n, int i) {
    int largest = i;
    int left = LEFT(i);
    int right = RIGHT(i);

    // Find the largest element among the root, left, and right nodes
    if (left < n && heap[left] < heap[largest]) {
        largest = left;
    }
    if (right < n && heap[right] < heap[largest]) {
        largest = right;
    }

    // If the root is not the largest, swap it with the largest element
    // and heapify the subtree
    if (largest != i) {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        heapify(heap, n, largest);
    }
}

// Function to build the heap tree
void buildHeap(int *heap, int n) {
    // Start from the last non-leaf node and heapify all nodes
    for (int i = PARENT(n - 1); i >= 0; i--) {
        heapify(heap, n, i);
    }
}

// Function to perform heap sort
void heapSort(int *heap, int n) {
    // Build the heap tree
    buildHeap(heap, n);

    // Repeatedly swap the root with the last element and heapify the tree
    for (int i = n - 1; i >= 0; i--) {
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;

        heapify(heap, i, 0);
    }
}

// Function to display the heap tree
void displayHeap(int *heap, int n) {
    printf("Heap tree: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements in the heap tree: ");
    scanf("%d", &n);

    int *heap = malloc(n * sizeof(int));
    if (heap == NULL) {
                printf("Error allocating memory!\n");
        return 1;
    }

    printf("Enter the elements of the heap tree: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &heap[i]);
    }

    // Perform heap sort and display the sorted heap tree
    heapSort(heap, n);
    displayHeap(heap, n);

    free(heap);
    return 0;
}


