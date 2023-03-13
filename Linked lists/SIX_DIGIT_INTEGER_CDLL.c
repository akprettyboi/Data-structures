/******************************************************************************

                           SIX DIGIT INTEGER CIRCULAR DOUBLE LINKED LIST
                           NEEDS MORE WORK NOT COMPLETE

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// define a structure for a node in the linked list
struct node {
int data;
struct node *next;
struct node *prev;
};

// function prototypes
void insert_node(struct node **head, int value);
void delete_node(struct node **head, struct node *node_to_delete);
void print_list(struct node *head);
struct node *add_lists(struct node *list1, struct node *list2);
struct node *subtract_lists(struct node *list1, struct node *list2);
struct node *multiply_lists(struct node *list1, struct node *list2);

int main(void) {
// create two linked lists to store the numbers
struct node *list1 = NULL;
struct node *list2 = NULL;
struct node *result = NULL;
int choice, value, carry;
while (1) {
printf("Enter your choice:\n");
printf("1. Insert a digit into list 1\n");
printf("2. Insert a digit into list 2\n");
printf("3. Perform addition\n");
printf("4. Perform subtraction\n");
printf("5. Perform multiplication\n");
printf("6. Exit\n");
scanf("%d", &choice);

    switch(choice) {
    case 1:
        printf("Enter a digit to insert into list 1: ");
        scanf("%d", &value);
        insert_node(&list1, value);
        break;
    case 2:
        printf("Enter a digit to insert into list 2: ");
        scanf("%d", &value);
        insert_node(&list2, value);
        break;
        case 3:
            result = add_lists(list1, list2);
            printf("Result of addition: ");
            print_list(result);
            printf("\n");
            break;
        case 4:
            result = subtract_lists(list1, list2);
            printf("Result of subtraction: ");
            print_list(result);
            printf("\n");
            break;
        case 5:
            result = multiply_lists(list1, list2);
            printf("Result of multiplication: ");
            print_list(result);
            printf("\n");
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid choice. Try again.\n");
            break;
    }
}

return 0;
}

// function to insert a new node at the end of the linked list
void insert_node(struct node **head, int value) {
// create a new node
struct node *new_node = malloc(sizeof(struct node));
new_node->data = value;
new_node->next = NULL;
new_node->prev = NULL;
if (*head == NULL) {
    // if the list is empty, make the new node the head and set its next and prev pointers to itself
    new_node->next = new_node;
    new_node->prev = new_node;
    *head = new_node;
}
else {
    // if the list is not empty, insert the new node at the end
    struct node *last = (*head)->prev;
    last->next = new_node;
    new_node->prev = last;
    new_node->next = *head;
    (*head)->prev = new_node;
}
}


// function to delete a node from the linked list
void delete_node(struct node **head, struct node *node_to_delete) {
if (*head == NULL || node_to_delete == NULL) {
return;
}
// if the node to be deleted is the only node in the list
if (*head == node_to_delete && (*head)->next == *head) {
    *head = NULL;
    free(node_to_delete);
}
else {
    struct node *prev = node_to_delete->prev;
    struct node *next = node_to_delete->next;
    prev->next = next;
    next->prev = prev;

    if (*head == node_to_delete) {
        *head = next;
    }

    free(node_to_delete);
}
}

// function to print the linked list
void print_list(struct node *head) {
if (head == NULL) {
return;
}
struct node *current = head;

do {
    printf("%d ", current->data);
    current = current->next;
} while (current != head);
}

// function to perform addition on two linked lists
struct node *add_lists(struct node *list1, struct node *list2) {
// create a new linked list to store the result
struct node *result = NULL;
int carry = 0;
// traverse the lists and add the digits
struct node *current1 = list1;
struct node *current2 = list2;
do {
    int sum = current1->data + current2->data + carry;
    carry = sum / 10;
    sum = sum % 10;
    insert_node(&result, sum);

    current1 = current1->next;
    current2 = current2->next;
} while (current1 != list1 && current2 != list2);

// if one of the lists has more digits, add the remaining digits
while (current1 != list1) {
    int sum = current1->data + carry;
    carry = sum / 10;
    sum = sum % 10;
    insert_node(&result, sum);
    current1 = current1->next;
}
while (current2 != list2) {
    int sum = current2->data + carry;
    carry = sum / 10;
    sum = sum % 10;
    insert_node(&result, sum);
    current2 = current2->next;
}

// if there is a final carry, add it to the result
if (carry > 0) {
    insert_node(&result, carry);
}

return result;
}
// function to perform subtraction on two linked lists
 struct node *subtract_lists(struct node *list1, struct node *list2){
// create a new linked list to store the result
struct node *result = NULL;
int borrow = 0;
// traverse the lists and subtract the digits
struct node *current1 = list1;
struct node *current2 = list2;
do {
    int difference = current1->data - current2->data - borrow;
    if (difference < 0) {
        difference += 10;
        borrow = 1;
    }
    else {
        borrow = 0;
    }
    insert_node(&result, difference);

    current1 = current1->next;
    current2 = current2->next;
} while (current1 != list1 && current2 != list2);

// if one of the lists has more digits, subtract the remaining digits
while (current1 != list1) {
    int difference = current1->data - borrow;
    if (difference < 0) {
        difference += 10;
        borrow = 1;
    }
    else {
        borrow = 0;
    }
    insert_node(&result, difference);
    current1 = current1->next;
}
while (current2 != list2) {
    int difference = current2->data - borrow;
    if (difference < 0) {
        difference += 10;
        borrow = 1;
    }
    else {
        borrow = 0;
    }
    insert_node(&result, difference);
    current2 = current2->next;
}

// remove any leading zeros from the result
while (result != NULL && result->data == 0) {
    delete_node(&result, result);
}

return result;
}
// function to perform multiplication on two linked lists
struct node *multiply_lists(struct node *list1, struct node *list2) {
// create a new linked list to store the result
struct node *result = NULL;
int carry = 0;
// traverse the lists and multiply the digits
struct node *current1 = list1;
do {
    int product = current1->data * list2->data + carry;
    carry = product / 10;
    product = product % 10;
    insert_node(&result, product);

    current1 = current1->next;
} while (current1 != list1);

// if there is a final carry, add it to the result
if (carry > 0) {
    insert_node(&result, carry);
}

return result;
}

