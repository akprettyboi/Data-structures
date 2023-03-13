// Practical 7:Write a C Program to implement Heap sort using Max heap in descending order (for Even Roll no.) and Min Heap in ascending order (for Odd Roll no.)
// Roll no. 6-Sorting in descending order with max heap
#include<stdio.h>
#include<stdlib.h>

typedef struct Heap
{
    struct Heap* left;
    int val;
    struct Heap* right;
}Heap;

//////////////////////////////
typedef struct
{
    Heap** arr;
    int front;
    int rear;
    int cap; // capacity
    int size;// number of elements in queue
}Queue;
// takes one argument, int capacity, returns pointer to the new queue
Queue* mkQueue(int capacity)
{
    Queue* new = (Queue*)calloc(1,sizeof(Queue));
    new->cap = capacity;
    new->rear = capacity - 1;
    new->arr = (Heap**)malloc(new->cap * sizeof(Heap*));
    return new;
}
// takes two arguments, Queue* q, and Heap* element,returns void
void enqueue(Queue* queue, Heap* node)
{
    queue->rear = (queue->rear + 1) % queue->cap;
    queue->arr[queue->rear] = node;
    queue->size++;//size increases
}
// takes one argument, Queue* q; returns Heap*, element previously at front of queue
Heap* dequeue(Queue* queue)
{
    Heap* item = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->cap;
    queue->size--;//size decreases
    return item;
}
// takes one arguments, int node_data,returns pointer to new Heap element
Heap* mkNode(int data)
{
    Heap* new = (Heap*)calloc(1, sizeof(Heap));
    new->val = data;
    return new;
}
/////////////////////////


//takes two arguments, Heap* root, and int new_node_val
// maintains the almost complete binary tree property
// implemented with a queue
Heap* insert(Heap* root, int val)
{
    Queue* q = mkQueue(100);
    if (!root)
        root = mkNode(val);
    else
        enqueue(q, root);
    while (q->size)
    {
        Heap* cur = dequeue(q);
        if (!cur->left)
        {
            cur->left = mkNode(val);
            return root;
        }
        else
            enqueue(q, cur->left);
        if (!cur->right)
        {
            cur->right = mkNode(val);
            return root;
        }
        else
            enqueue(q, cur->right);
    }
    return root;
}

// takes Heap* argument, root, returns void
// preserving the  heap property by bubbling down nodes
void heapify(Heap* root)
{
    if (!root)
        return;
    heapify(root->left);
    heapify(root->right);
    int rootval = root->val;
    int left = (root->left) ? root->left->val : 0;
    int right = (root->right) ? root->right->val : 0;
    if (left > rootval && left > right)//left node has largest value out of the three
    {
        root->val = left;// exchanging values
        root->left->val = rootval;
    }
    else if (right > rootval && right > left)//right node has largest value out of the three
    {
        root->val = right;
        root->right->val = rootval;
    }
}

// takes Heap* argument, root, returns int, previous root value of heap
// deletes the root node, regenerates the heap property and returns the previous root value
int delete(Heap* heap)
{
    int retval = heap->val;
    Heap* curParent = NULL;
    Heap* cur = heap;
    while (1)
    {
        if (cur->right)
        {
            curParent = cur;
            cur = cur->right;
        }
        else if (cur->left)
        {
            curParent = cur;
            cur = cur->left;
        }
        else
            break;
    }
    int newHeapVal = cur->val;
    if (curParent)
    {
        if (cur->val == curParent->left->val)
        {
            free(curParent->left);
            curParent->left = NULL;
        }
        else
        {
            free(curParent->right);
            curParent->right = NULL;
        }
    }
    heap->val = newHeapVal;
    heapify(heap);
    return retval;
}

// takes two arguments, int* input_array, and int input_array_size
// returns int*, pointer_to_sorted_array
int* minHeapSort(int* arr, int arrsize)
{
    int* ret = (int*)malloc(arrsize * sizeof(int));
    Heap* root = NULL;
    for (int i = 0; i < arrsize; i++)
    {
        root = insert(root, arr[i]);
        heapify(root);
    }
    for (int i = 0; i < arrsize; i++)
        ret[i] = delete(root);
    return ret;
}

int main()
{   int arr[100];
    int n;
    printf("Enter the number of elements in the heap tree: ");
    scanf("%d", &arrsize);
    printf("Enter the elements of the heap tree: ");
      for (int i = 0; i < arrsize; i++) {
        scanf("%d", &arr[i]);
    }

    \\int arr[] = { 5, 10,9,20,3,7,1,8 };
    \\int arrsize = sizeof(arr) / sizeof(*arr);
    int* ret = minHeapSort(arr, arrsize);
    printf("The sorted array is: ");
    for (int i = 0; i < arrsize; i++)
        printf("%d ", ret[i]);
    free(ret);
    return 0;
}
