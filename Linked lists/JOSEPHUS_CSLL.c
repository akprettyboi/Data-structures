/******************************************************************************

                    Josephus using SDLL

*******************************************************************************/


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head;

void insert(int data) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        head->next = head;
        return;
    }

    struct node *current = head;
    while (current->next != head) {
        current = current->next;
    }

    current->next = newNode;
    newNode->next = head;
}

void delete(struct node *node) {
    if (node == head) {
        head = node->next;
    }

    struct node *current = head;
    while (current->next != node) {
        current = current->next;
    }

    current->next = node->next;
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
