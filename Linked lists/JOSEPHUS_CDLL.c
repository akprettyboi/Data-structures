/******************************************************************************

                    Josephus using CDLL

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head;

void insert(int data) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        head->prev = head;
        head->next = head;
        return;
    }

    struct node *current = head;
    while (current->next != head) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
    newNode->next = head;
    head->prev = newNode;
}

void delete(struct node *node) {
    if (node == head) {
        head = node->next;
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;

    free(node);
}

int main() {
    int numPeople, interval;

    printf("Enter the number of people in the circle: ");
    scanf("%d", &numPeople);

    if (numPeople <= 0) {
        printf("Error: Invalid number of people.\n");
        return 1;
    }

    printf("Enter the interval at which people are eliminated: ");
    scanf("%d", &interval);

    if (interval <= 0) {
        printf("Error: Invalid interval.\n");
        return 1;
    }

    for (int i = 1; i <= numPeople; i++) {
        insert(i);
    }

    struct node *current = head;
    while (current->next != current) {
        for (int i = 1; i < interval; i++) {
            current = current->next;
        }
        struct node *next = current->next;
        printf("Eliminating person at position %d\n", current->data);
        delete(current);
        current = next;
    }

    printf("The last person standing is at position %d.\n", current->data);

    return 0;
}

